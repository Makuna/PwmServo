//
// supported PWM/PINs for high resolution Servo PWM
//
//  Pin#	Timer Set		Arduino Board Label
//  2		3				PWM2, 
//  3		3				PWM3, 
//	5		3				PWM5, 
//	6		4				PWM6, 
//	7		4				PWM7, 
//	8		4				PWM8, 
//	11		1				PWM11, 
//	12		1				PWM12, 
//	44		5				D44, 
//	45		5				D45, 
//  46		5				D46
//
//  Refrain from using the timers from a set for any other purpose
//  when any pins using that timer set are used for pwmServo
#ifndef PwmServo_h
#define PwmServo_h

#include <Arduino.h>

// duty cycle values
#define pwmServoCenter 3000 // normal center for 1.5ms pulse
#define pwmServoLow 2000 // normal low for 1ms pulse
#define pwmServoHigh 4000 // normal high for 2ms pulse
#define pwmServo1ms 2000

void pwmServoAttachPin(uint8_t pin, int pwmDutyCycle = pwmServoCenter);
void pwmServoDetachPin(uint8_t pin);
void pwmServoWrite(uint8_t pin, int pwmDutyCycle);

#endif