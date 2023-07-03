#include <vector>
#include <GPIO.h>
#include <TIMER.h>
#include <MPU.h>
#include <NRF24.h>
#include <USART.h>
#include <Core.h>
#include <queue>

using namespace std;
using namespace global;


struct Motor {
	TIMER *timer;
	channel_conf_t channel;
	uint32_t min, max;
	float current_thrust;


	Motor(TIMER *timer, channel_conf_t *channel, uint32_t min, uint32_t max);
	void setThrust(float thrust);
};


struct Controller {
	float kp, ki, kd;
	float error, prev_error, filtered_de;
	float propotional, integral, derivative;
	float command;
	float temp_dt = 0;
	// float dt;
	int x = 0;

	explicit Controller(){
		error = 0;
		prev_error = 0;
		kp = 0;
		ki = 0;
		kd = 0;
		propotional = 0;
		integral = 0;
		derivative = 0;
		command = 0;
		filtered_de = 0;
	}

	void calc_error(float desired, float current){
		error = desired - current;
	}
	void calc_proportional(){
		propotional = kp * error;
	}
	void calc_integral(float dt){
		integral += ki * error * dt;
	}
	void calc_derivative(float dt){
		if(temp_dt < 1) { 
			temp_dt += dt;
			x++;
		}
		else {
			temp_dt = 0;
			x = 0;
		}
		float change = error - prev_error;
		// float alpha = 0.99;
		// filtered_de = alpha * filtered_de + (1-alpha) * change / dt;
		// derivative = kd*filtered_de;
		derivative = kd*(change/dt);
		prev_error = error;
	}
	void run(float desired, float current, float dt){
		calc_error(desired, current);
		calc_proportional();
		calc_integral(dt);
		calc_derivative(dt);
		command = propotional + integral + derivative;
	}
};

struct QuadCopter {
	TIMER timer1, timer2, timer6;
	uint32_t prev_micros = 0;
	vector<Motor> motors;
	MPU_t mpu;
	Madgwick madgwick;
	NRF24 nrf;
	float dt;
	float desired_roll = 0, desired_pitch = 0, desired_yaw = 0;

	float direct = 0;
	struct {
		Controller Roll, Pitch, Yaw, Altitude;
	} controllers;


	QuadCopter() : controllers{ Controller(), Controller(), Controller(), Controller() }, madgwick(1.5) {}
	void Init();
	void NRF_Read(bool);
	// void NRF_Send();
	void IMU_Read(bool);
	void Control();

	private:
		// some helper functions for the init sequence
		void Update();
		void init_pins();
		void init_timer();
		void init_channels();
		void init_escs();
		void init_motors();
		void init_controllers();
};