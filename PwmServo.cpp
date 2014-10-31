#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <Arduino.h> 
#include "PwmServo.h"

#define CyclesFor20ms 39999 // (16mhz / 8) / 50hz = ticks for 50hz or 20ms

// supported PWM/PINs for high resolution Servo PWM
//  PWM2, PWM3, PWM5, PWM6, PWM7, PWM8, PWM11, PWM12, PIN44, PIN45, PIN46

// due to reading the TCCRnA causing problems (pin stays high)
// we keep track of it and just set it (since sbi/sbi will read)
#if defined(TCCR1A) && defined(WGM13)
static uint8_t tccr1a = 0;
#endif
#if defined(TCCR3A) && defined(WGM33)
static uint8_t tccr3a = 0;
#endif
#if defined(TCCR4A) && defined(WGM43)
static uint8_t tccr4a = 0;
#endif
#if defined(TCCR5A) && defined(WGM53)
static uint8_t tccr5a = 0;
#endif

void pwmServoAttachPin(uint8_t pin, int pwmDutyCycle)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);

	uint8_t timer = digitalPinToTimer(pin);

	switch (timer)
	{
		#if defined(TCCR1A) && defined(COM1A1) && defined(WGM13) 
		case TIMER1A:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr1a |= _BV(COM1A1) | _BV(WGM11); 
			TCCR1A = tccr1a;
			TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS11); // prescaler 8
			TCNT1 = 0;
			ICR1 = CyclesFor20ms;
			OCR1A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR1A) && defined(COM1B1) && defined(WGM13)
		case TIMER1B:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr1a |= _BV(COM1B1) | _BV(WGM11); 
			TCCR1A = tccr1a;
			TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS11); // prescaler 8
			TCNT1 = 0;
			ICR1 = CyclesFor20ms;
			OCR1B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3A1) && defined(WGM33)
		case TIMER3A:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr3a |=  _BV(COM3A1) | _BV(WGM31);
			TCCR3A = tccr3a;
			TCCR3B = _BV(WGM32) | _BV(WGM33) | _BV(CS31); // prescaler 8
			TCNT3 = 0;
			ICR3 = CyclesFor20ms;
			OCR3A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3B1) && defined(WGM33)
		case TIMER3B:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr3a |=  _BV(COM3B1) | _BV(WGM31);
			TCCR3A = tccr3a;
			TCCR3B = _BV(WGM32) | _BV(WGM33) | _BV(CS31); // prescaler 8
			TCNT3 = 0;
			ICR3 = CyclesFor20ms;
			OCR3B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3C1) && defined(WGM33)
		case TIMER3C:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr3a |=  _BV(COM3C1) | _BV(WGM31);
			TCCR3A = tccr3a;
			TCCR3B = _BV(WGM32) | _BV(WGM33) | _BV(CS31); // prescaler 8
			TCNT3 = 0;
			ICR3 = CyclesFor20ms;
			OCR3C = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4A1) && defined(WGM43)
		case TIMER4A:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr4a |=  _BV(COM4A1) | _BV(WGM31);
			TCCR4A = tccr4a;
			TCCR4B = _BV(WGM42) | _BV(WGM43) | _BV(CS41); // prescaler 8
			TCNT4 = 0;
			ICR4 = CyclesFor20ms;
			OCR4A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4B1) && defined(WGM43)
		case TIMER4B:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr4a |=  _BV(COM4B1) | _BV(WGM31);
			TCCR4A = tccr4a;
			TCCR4B = _BV(WGM42) | _BV(WGM43) | _BV(CS41); // prescaler 8
			TCNT4 = 0;
			ICR4 = CyclesFor20ms;
			OCR4B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4C1) && defined(WGM43)
		case TIMER4C:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr4a |=  _BV(COM4C1) | _BV(WGM31);
			TCCR4A = tccr4a;
			TCCR4B = _BV(WGM42) | _BV(WGM43) | _BV(CS41); // prescaler 8
			TCNT4 = 0;
			ICR4 = CyclesFor20ms;
			OCR4C = pwmDutyCycle; // set pwm duty
			break;
		#endif
				
		#if defined(TCCR5A) && defined(COM5A1) && defined(WGM53)
		case TIMER5A:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr5a |=  _BV(COM5A1) | _BV(WGM51);
			TCCR5A = tccr5a;
			TCCR5B = _BV(WGM52) | _BV(WGM53) | _BV(CS51); // prescaler 8
			TCNT5 = 0;
			ICR5 = CyclesFor20ms;
			OCR5A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR5A) && defined(COM5B1) && defined(WGM53)
		case TIMER5B:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr5a |=  _BV(COM5B1) | _BV(WGM51);
			TCCR5A = tccr5a;
			TCCR5B = _BV(WGM52) | _BV(WGM53) | _BV(CS51); // prescaler 8
			TCNT5 = 0;
			ICR5 = CyclesFor20ms;
			OCR5B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR5A) && defined(COM5C1) && defined(WGM53)
		case TIMER5C:
			// clear on compare, fast PWM, TOP=ICRn (WGMn3/WGMn2 in TCCRnB)
			tccr5a |=  _BV(COM5C1) | _BV(WGM51);
			TCCR5A = tccr5a;
			TCCR5B = _BV(WGM52) | _BV(WGM53) | _BV(CS51); // prescaler 8
			TCNT5 = 0;
			ICR5 = CyclesFor20ms;
			OCR5C = pwmDutyCycle; // set pwm duty
			break;
		#endif

		case NOT_ON_TIMER:
		default:
			break;
	}

}

void pwmServoDetachPin(uint8_t pin)
{
	uint8_t timer = digitalPinToTimer(pin);

	switch (timer)
	{
		#if defined(TCCR1A) && defined(COM1A1) && defined(WGM13)
		case TIMER1A:
			// disconnect pwm to pin on timer 1, channel A
			tccr1a &= ~_BV(COM1A1);
			TCCR1A = tccr1a;
			break;
		#endif

		#if defined(TCCR1A) && defined(COM1B1) && defined(WGM13)
		case TIMER1B:
			// disconnect pwm to pin on timer 1, channel B
			tccr1a &= ~_BV(COM1B1);
			TCCR1A = tccr1a;
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3A1) && defined(WGM33)
		case TIMER3A:
			// disconnect pwm to pin on timer 3, channel A
			tccr3a &= ~_BV(COM3A1);
			TCCR3A = tccr3a;
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3B1) && defined(WGM33)
		case TIMER3B:
			// disconnect pwm to pin on timer 3, channel B
			tccr3a &= ~_BV(COM3B1);
			TCCR3A = tccr3a;
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3C1) && defined(WGM33)
		case TIMER3C:
			// disconnect pwm to pin on timer 3, channel C
			tccr3a &= ~_BV(COM3C1);
			TCCR3A = tccr3a;
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4A1) && defined(WGM43)
		case TIMER4A:
			// disconnect pwm to pin on timer 4, channel A
			tccr4a &= ~_BV(COM4A1);
			TCCR4A = tccr4a;
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4B1) && defined(WGM43)
		case TIMER4B:
			// disconnect pwm to pin on timer 4, channel B
			tccr4a &= ~_BV(COM4B1);
			TCCR4A = tccr4a;
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4C1) && defined(WGM43)
		case TIMER4C:
			// disconnect pwm to pin on timer 4, channel C
			tccr4a &= ~_BV(COM4C1);
			TCCR4A = tccr4a;
			break;
		#endif
				
		#if defined(TCCR5A) && defined(COM5A1) && defined(WGM53)
		case TIMER5A:
			// disconnect pwm to pin on timer 5, channel A
			tccr5a &= ~_BV(COM5A1);
			TCCR5A = tccr5a;
			break;
		#endif

		#if defined(TCCR5A) && defined(COM5B1) && defined(WGM53)
		case TIMER5B:
			// disconnect pwm to pin on timer 5, channel B
			tccr5a &= ~_BV(COM5B1);
			TCCR5A = tccr5a;
			break;
		#endif

		#if defined(TCCR5A) && defined(COM5C1) && defined(WGM53)
		case TIMER5C:
			// disconnect pwm to pin on timer 5, channel C
			tccr5a &= ~_BV(COM5C1);
			TCCR5A = tccr5a;
			break;
		#endif

		case NOT_ON_TIMER:
		default:
			break;
	}

	digitalWrite(pin, LOW);
}

void pwmServoWrite(uint8_t pin, int pwmDutyCycle)
{
	uint8_t timer = digitalPinToTimer(pin);

	switch (timer)
	{
		#if defined(TCCR1A) && defined(COM1A1) && defined(WGM13) 
		case TIMER1A:
			OCR1A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR1A) && defined(COM1B1) && defined(WGM13) 
		case TIMER1B:
			OCR1B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3A1) && defined(WGM33)
		case TIMER3A:
			OCR3A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3B1) && defined(WGM33)
		case TIMER3B:
			OCR3B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR3A) && defined(COM3C1) && defined(WGM33)
		case TIMER3C:
			OCR3C = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4A1) && defined(WGM43)
		case TIMER4A:
			OCR4A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4B1) && defined(WGM43)
		case TIMER4B:
			OCR4B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR4A) && defined(COM4C1) && defined(WGM43)
		case TIMER4C:
			OCR4C = pwmDutyCycle; // set pwm duty
			break;
		#endif
				
		#if defined(TCCR5A) && defined(COM5A1) && defined(WGM53)
		case TIMER5A:
			OCR5A = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR5A) && defined(COM5B1) && defined(WGM53)
		case TIMER5B:
			OCR5B = pwmDutyCycle; // set pwm duty
			break;
		#endif

		#if defined(TCCR5A) && defined(COM5C1) && defined(WGM53)
		case TIMER5C:
			OCR5C = pwmDutyCycle; // set pwm duty
			break;
		#endif

		case NOT_ON_TIMER:
		default:
			break;
	}
}