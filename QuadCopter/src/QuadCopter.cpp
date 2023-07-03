#include <QuadCopter.h>
#include <RCC.h>
#include <Core.h>
#include <GPIO.h>

#define MOTOR0 PA0
#define MOTOR1 PA1
#define MOTOR2 PA8
#define MOTOR3 PA3

uint32_t micros = 0;

// #define direct 10
using namespace global;

GPIO_TypeDef *GPIOAA_Base = GPIOA;
TIM_TypeDef *TIM1_Base = TIM1;
TIM_TypeDef *TIM6_Base = TIM6;

void delay(uint32_t milliseconds){
	uint32_t value = milliseconds*8000;
	for(int i = 0; i < value; i++);
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
	// thrust is a value between 0 and 100
	// you should map it to be a value between min and max
	uint32_t temp = map(thrust, 0, 100, this->min, this->max);
	channel.capture_compare =  temp;
	timer->set_capture_compare(timer->init_struct.instance, &channel);
	current_thrust = thrust;
}

void QuadCopter::init_pins(){
	RCC_GPIOA_CLK_ENABLE();
	gpio_pin_conf_t pin;
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
	// TIMER tim2;
	TIMx_init_t tim2_init, tim1_init, tim6_init;
	tim2_init.instance = TIM2;					// choose timer2
	tim2_init.direction = TIM_DIR_UPCOUNT;		// up count direction
	tim2_init.preload = TIM_CR1_ARPE;			// Auto reload preload enable
	tim2_init.prescaler = 0;					// no prescaler it's getting the full 80Mhz of the controller clock
	tim2_init.auto_reload = 1600000;			// acheiving a period of 20ms for 50Hz

	tim1_init.instance = TIM1;					// choose timer2
	tim1_init.direction = TIM_DIR_UPCOUNT;		// up count direction
	tim1_init.preload = TIM_CR1_ARPE;			// Auto reload preload enable
	tim1_init.prescaler = 1600-1;					// no prescaler it's getting the full 80Mhz of the controller clock
	tim1_init.auto_reload = 1000;			// acheiving a period of 20ms for 50Hz

	tim6_init.instance = TIM6;					// choose timer2
	tim6_init.direction = TIM_DIR_UPCOUNT;		// up count direction
	tim6_init.preload = TIM_CR1_ARPE;			// Auto reload preload enable
	tim6_init.prescaler = 0;					// no prescaler it's getting the full 80Mhz of the controller clock
	tim6_init.auto_reload = 80;					// acheiving a period of 20ms for 50Hz

	RCC_TIM1_CLK_ENABLE();						// enable clock first as usual
	RCC_TIM2_CLK_ENABLE();						// enable clock first as usual
	RCC_TIM6_CLK_ENABLE();
	timer1.init(&tim1_init);
	timer2.init(&tim2_init);		// init the tim and pass the init struct with the parameters
	timer6.init(&tim6_init);
	Nvic.enableInterrupt(TIM6_DAC_IRQn);		   // enable interrupt (not necessary for now we not using the ISR yet)
	TIM6->DIER |= TIM_DIER_UIE;
}

void QuadCopter::init_channels(){
	channel_conf_t  channel;					// for tim2 enable the first 4 channel to output a pwm signal
	channel.io = CHANNEL_IO_OUTPUT;
	channel.polarity = CHANNEL_POLARITY_HIGH;
	channel.capture_preload_enable = 0;
	channel.mode = OCxM_PWM_1;
	channel.capture_compare = 0;

	// this range values are based on tests of escs ranges since I got ones 
	// that don't support programming mode of range calibration :(
	channel.no = 1;
	motors.push_back(Motor(&timer2, &channel, 60000, 180000));
	timer2.channel_init(timer2.init_struct.instance, &channel);
	channel.no = 2;
	motors.push_back(Motor(&timer2, &channel, 84000, 160000));
	timer2.channel_init(timer2.init_struct.instance, &channel);
	channel.no = 1;
	motors.push_back(Motor(&timer1, &channel, 51, 100));
	timer1.channel_init(timer1.init_struct.instance, &channel);
	channel.no = 4;
	motors.push_back(Motor(&timer2, &channel, 59900, 180000));
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
	//init timer to calculate for dt
	Systick.Init();

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

	direct = 10;
	Update();

	mpu.Init();
	mpu.calibrate();
	// mpu.printValues();
	// mpu.printErrors();
	// mpu.printAngles();
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

void QuadCopter::IMU_Read(bool print){
	mpu.readAcc();
	mpu.readGyro();
	mpu.readMag();
	dt = Systick.getDeltaT();
	//mpu.calculateAngles(dt);
	// mpu.angles = mahony.update(mpu.acc, mpu.gyro, dt);
	// mpu.angles = madgwick.MadgwickQuaternionUpdate(mpu.acc, mpu.gyro, mpu.mag, dt);
	if(print)
		mpu.printValues();
}

void QuadCopter::Control() {
	dt = (micros - prev_micros) * 0.000001;
	prev_micros = micros;
	controllers.Roll.run(desired_roll, mpu.angles.roll, dt);
	// Pitch_Controller.run(0, mpu.pitch, dt);
	// Yaw_Controller.run(0, mpu.yaw, dt);
	// Altitude_Controller.run(1, mpu.altitude, dt);
	Update();
}

void QuadCopter::Update() {
	motors[0].setThrust(direct - controllers.Roll.command);
	motors[1].setThrust(direct + controllers.Roll.command);
	motors[2].setThrust(direct - controllers.Roll.command);
	motors[3].setThrust(direct + controllers.Roll.command);
}

extern "C" {

void TIM6_DAC_IRQHandler(){
	micros++;


	Nvic.clearPending(TIM6_DAC_IRQn);
	TIM6->SR &= ~TIM_SR_UIF;
}


}