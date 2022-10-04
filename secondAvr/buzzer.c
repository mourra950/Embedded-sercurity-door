#include "gpio.h"
#include "common_macros.h"
#include <util/delay.h>
#include "buzzer.h"


void Buzzinit(void) {
	GPIO_setupPinDirection(BuzzPort, BuzzPin, PIN_OUTPUT);
	GPIO_writePin(BuzzPort, BuzzPin, LOGIC_LOW);
}

void Buzzon(void)
{
	GPIO_writePin(BuzzPort, BuzzPin, LOGIC_HIGH);

}

void Buzzoff(void)
{
	GPIO_writePin(BuzzPort, BuzzPin, LOGIC_LOW);

}
