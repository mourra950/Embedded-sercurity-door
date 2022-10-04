
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "common_macros.h"
#include "std_types.h"
#include "dcMotor.h"




void MotorInit(void)
{
	GPIO_setupPinDirection(PORTMotor, PinMotor1, PIN_OUTPUT);
	GPIO_writePin(PORTMotor, PinMotor1, LOGIC_LOW);

	GPIO_setupPinDirection(PORTMotor, PinMotor2, PIN_OUTPUT);
	GPIO_writePin(PORTMotor, PinMotor2, LOGIC_LOW);
}

void MotorM(MotorMode mode)
{
	if (mode == ClockWise_Motor)
	{
		GPIO_writePin(PORTMotor, PinMotor1, LOGIC_LOW);
		GPIO_writePin(PORTMotor, PinMotor2, LOGIC_HIGH);
	}
	else if(mode==AntiClock_Motor)
	{
		GPIO_writePin(PORTMotor, PinMotor1, LOGIC_HIGH);
		GPIO_writePin(PORTMotor, PinMotor2, LOGIC_LOW);

	}
	else
	{
		GPIO_writePin(PORTMotor, PinMotor1, LOGIC_LOW);
		GPIO_writePin(PORTMotor, PinMotor2, LOGIC_LOW);

	}
}

