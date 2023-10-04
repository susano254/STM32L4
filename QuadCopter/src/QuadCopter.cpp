#include <QuadCopter.h>
#include <RCC.h>
#include <Core.h>
#include <GPIO.h>

#define MOTOR0 PA0
#define MOTOR1 PA1
#define MOTOR2 PA8
#define MOTOR3 PA3

using namespace global;

uint32_t millis;
uint32_t prev_millis;
uint32_t tim6_overflows = 0;
// uint32_t tim6_reload = 40000-1;
uint32_t tim6_prev_millis = 0;
uint32_t timX_millis = 0;
uint32_t timX_prev_millis = 0;

// TIM_TypeDef *TIM6_Base = TIM6;
// DWT_Type *DWT_Base = DWT;
// SCB_Type *SCB_Base = SCB;
// CoreDebug_Type *CoreDebug_Base = CoreDebug;

// struct Micros {
// 	uint32_t overflows;
// 	uint16_t ticks;
// 
// 	Micros(uint16_t ticks, uint32_t overflows) : overflows(overflows), ticks(ticks) {}
// };
// 
// Micros get_micros(){
// 	return Micros(TIM6->CNT, tim6_overflows);
// }
// 
// float getdt(Micros cur_micros, Micros prev_micros){
// 	return  (cur_micros.ticks- prev_micros.ticks)*0.000001f + (cur_micros.overflows-prev_micros.overflows)*0.065535f;
// }

void delay(uint32_t milliseconds){
	uint32_t startmillis = Systick.getMillis();
	while((Systick.getMillis()-startmillis) < milliseconds);
}

int map(int value, int oldMin, int oldMax, int newMin, int newMax){
	float temp = (float) (value - oldMin)/(oldMax - oldMin);
	return temp * (newMax - newMin) + newMin;
}

int map(float value, int oldMin, int oldMax, int newMin, int newMax){
	float temp = (float) (value - oldMin)/(oldMax - oldMin);
	return temp * (newMax - newMin) + newMin;
}

Motor::Motor(TIMER *timer, channel_conf_t *channel, uint32_t min, uint32_t max) {
	this->timer = timer;
	// init the thrust to 0
	current_thrust = 0;

	//deep copy the channel
	this->channel.no = channel->no;
	this->channel.io = channel->io;
	this->channel.mode = channel->mode;
	this->channel.polarity = channel->polarity;
	this->channel.capture_preload_enable = channel->capture_preload_enable;
	this->channel.capture_compare = channel->capture_compare;

	this->min = min;
	this->max = max;
}

void Motor::setThrust(float thrust){
	if(thrust < 0) thrust = 0;
	// thrust is a value between 0 and 100
	// you should map it to be a value between min and max
	uint32_t temp = map(thrust, 0, 100, this->min, this->max);
	channel.capture_compare =  temp;
	timer->set_capture_compare(timer->init_struct.instance, &channel);
	current_thrust = thrust;
}

void QuadCopter::init_pins(){
	gpio_pin_conf_t pin;

	RCC_GPIOA_CLK_ENABLE();

	pin.mode = GPIO_PIN_ALT_FUN_MODE;
	pin.op_type = GPIO_PIN_OP_TYPE_PUSH_PULL;
	pin.pupd = GPIO_PIN_PUPD_NO_PUPD;
	pin.speed = GPIO_PIN_OSPEED_VERY_HIGH;
	pin.alternate_function = 1;

	//pins PA0 to PA3 for the 4 motors
	pin.pin = MOTOR0;
	gpio_init(GPIOA, &pin);
	pin.pin = MOTOR1;
	gpio_init(GPIOA, &pin);
	pin.pin = MOTOR2;				//leave PA2 for now because it's used with the usart peripheral
	gpio_init(GPIOA, &pin);
	pin.pin = MOTOR3;
	gpio_init(GPIOA, &pin);
}

void QuadCopter::init_timer(){
	TIMx_init_t tim2_init, tim1_init, tim6_init, timX_init;
	tim2_init.instance = TIM2;					// choose timer2
	tim2_init.direction = TIM_DIR_UPCOUNT;		// up count direction
	tim2_init.preload = TIM_CR1_ARPE;			// Auto reload preload enable
	tim2_init.prescaler = 80-1;					// no prescaler it's getting the full 80Mhz of the controller clock
	tim2_init.auto_reload = 16650-1;			// acheiving a period of 16.77ms for 60Hz

	tim1_init.instance = TIM1;
	tim1_init.direction = TIM_DIR_UPCOUNT;
	tim1_init.preload = TIM_CR1_ARPE;
	tim1_init.prescaler = 80-1;
	tim1_init.auto_reload = 16650-1;

	// tim6_init.instance = TIM6;				
	// tim6_init.direction = TIM_DIR_UPCOUNT;
	// tim6_init.preload = TIM_CR1_ARPE;	
	// tim6_init.prescaler = 79;
	// tim6_init.auto_reload = -1;

	// timX_init.instance = TIM15;				
	// timX_init.direction = TIM_DIR_UPCOUNT;
	// timX_init.preload = TIM_CR1_ARPE;	
	// timX_init.prescaler = 0;
	// timX_init.auto_reload = 80-1;

	RCC_TIM1_CLK_ENABLE();							// enable clock first as usual
	RCC_TIM2_CLK_ENABLE();							// enable clock first as usual
	// RCC_TIM6_CLK_ENABLE();
	// RCC_TIM15_CLK_ENABLE();

	timer1.init(&tim1_init);
	timer2.init(&tim2_init);			// init the tim and pass the init struct with the parameters

	// timer6.init(&tim6_init);

	// Nvic.enableInterrupt(TIM6_DAC_IRQn);		   // enable interrupt (not necessary for now we not using the ISR yet)
	// TIM6->DIER |= TIM_DIER_UIE;
}

void QuadCopter::init_channels(){
	channel_conf_t  channel;						// for tim2 enable the first 4 channel to output a pwm signal
	channel.io = CHANNEL_IO_OUTPUT;
	channel.polarity = CHANNEL_POLARITY_HIGH;
	channel.capture_preload_enable = 0;
	channel.mode = OCxM_PWM_1;
	channel.capture_compare = 0;

	// this range values are based on tests of escs ranges since I got ones 
	// that don't support programming mode of range calibration :(
	channel.no = 1;
	motors.push_back(Motor(&timer2, &channel, 750, 2000));
	timer2.channel_init(timer2.init_struct.instance, &channel);
	channel.no = 2;
	motors.push_back(Motor(&timer2, &channel, 1150, 2000));
	timer2.channel_init(timer2.init_struct.instance, &channel);
	channel.no = 1;
	motors.push_back(Motor(&timer1, &channel, 1050, 2000));
	timer1.channel_init(timer1.init_struct.instance, &channel);
	channel.no = 4;
	motors.push_back(Motor(&timer2, &channel, 750, 2000));
	timer2.channel_init(timer2.init_struct.instance, &channel);
	
	timer1.timer_update();
	timer2.timer_update();
}

void QuadCopter::init_escs(){
	motors[0].setThrust(0);
	motors[1].setThrust(0);
	motors[2].setThrust(0);
	motors[3].setThrust(0);
	//delay
	delay(5000);
}

void QuadCopter::init_motors(){
	//set the pins to alternate function mode for the timer output
	init_pins();
	//init the timer
	init_timer();

	//init the timer channels for motors
	init_channels();

	//ESC init sequence
	init_escs();

	//init the pid controllers
	init_controllers();
}

void QuadCopter::init_controllers() {
	controllers.Roll.kp = 0.00;
	controllers.Roll.kd = 0.00;
	controllers.Roll.ki = 0.00;

	controllers.Pitch.kp = 0.00;
	controllers.Pitch.kd = 0.00;
	controllers.Pitch.ki = 0.00;

	controllers.Yaw.kp = 0.00;
	controllers.Yaw.kd = 0.00;
	controllers.Yaw.ki = 0.00;
}

void QuadCopter::Init(){
  	init_motors();

	direct = 5;
	Update();

	mpu.Init();
	mpu.calibrate();

	nrf.init(CE_PIN, CSN_PIN);
	nrf.setRxMode(nrf.defaultAddr, 0);

	direct = 00;
	Update();
}

void QuadCopter::NRF_Read(bool print){
	nrf.status = nrf.readReg(STATUS);
	if(nrf.isDataAvailable(0)){
		nrf.receive();
		if(print)
			nrf.printData();
	}
}

void QuadCopter::IMU_Update(Madgwick &madgwick, bool print){
	static ZeroVelocityUpdate gyroFilter(5, Vector3(3.0f, 3.0f, 3.0f));
	static uint32_t prev_micros = 0;

	mpu.readAcc();
	mpu.readGyro();
	mpu.readMag();

	dt = System.getDeltaT(prev_micros);
	prev_micros = System.getMicros();



	mpu.gyro = gyroFilter.update(mpu.gyro);
	// mpu.angles = madgwick.update(mpu.acc, mpu.gyro, dt_l);

	// mpu.calculateAngles(dt);
	mpu.q = madgwick.MadgwickQuaternionUpdate(mpu.acc, mpu.gyro, mpu.mag, dt);
	mpu.angles = quat2EulerAngles(mpu.q);
	//convert to degrees back
	mpu.angles.phi *= (180.0f/M_PIf);
	mpu.angles.theta *= (180.0f/M_PIf);
	mpu.angles.psi *= (180.0f/M_PIf);

	if(print)
		mpu.printValues();
}

void QuadCopter::Control() {
	static uint32_t prev_micros = 0;

	dt = System.getDeltaT(prev_micros);
	prev_micros = System.getMicros();

	controllers.Roll.run(desired_roll, mpu.angles.roll, dt);
	// controllers.Pitch.run(desired_pitch, mpu.angles.pitch, dt);
	// controllers.Yaw.run(desired_yaw, mpu.angles.yaw, dt);
	// controllers.Altitude.run(1, mpu.altitude, dt);)
	Update();
}

void QuadCopter::Update() {
	motors[0].setThrust(direct - controllers.Roll.command);
	motors[1].setThrust(direct + controllers.Roll.command);
	motors[2].setThrust(direct - controllers.Roll.command);
	motors[3].setThrust(direct + controllers.Roll.command);
}

// extern "C" {
// 	void TIM6_DAC_IRQHandler(){
// 		tim6_overflows++;
// 
// 
// 		Nvic.clearPending(TIM6_DAC_IRQn);
// 		TIM6->SR &= ~TIM_SR_UIF;
// 	}
// }

