#include "lcd.h"
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "common_macros.h"
#include "std_types.h"
#include "timer0.h"
#include <avr/interrupt.h>




void (*g_TIMER0_callBackPtr)(void);


ISR(TIMER0_OVF_vect) {
	if (g_TIMER0_callBackPtr!=NULL_PTR)
	(*g_TIMER0_callBackPtr)();
}

/* Timer0 compare match ISR */
ISR(TIMER0_COMP_vect) {
	if (g_TIMER0_callBackPtr!=NULL_PTR)
	(*g_TIMER0_callBackPtr)();
}



void timerinit(const config_timer *config) {
	TCNT0 = config->Timer_initVal;

	OCR0=config->Compare_value;
	TCCR0 =(1<<FOC0) | config->Timer_mode | config->Timer_scale |config->Port ;
	TIMSK |= config->intmask;






}

void timerDinit(void) {

	TCNT0 = 0;
	TIMSK &= 0xFC;
	OCR0 = 0;
	TCCR0 = 0;
}

void timerreset(void)
{
	TCNT0 = 0;
}


void TIMER0_setCallback(void (*functionPtr)(void)) {
	g_TIMER0_callBackPtr = functionPtr;
}
