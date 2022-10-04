
#include "lcd.h"
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "common_macros.h"
#include "std_types.h"




typedef enum
{
	Timer_Normalmode=0x80,Timer_compareMode=0xC0,Timer_PWM=0x08,Timer_fastPWM=0x48
}TimerMode;
typedef enum
{
	Timer_PORTNormal=0x00,Timer_compareTogle=0x10,Timer_compareSet=0x30,Timer_compareClear=0x20,Timer_PWMReversed=0x10,Timer_PWMClear=0x20,Timer_PWMSet=0x30
}ComparePort;


typedef enum
{
	Timer_disabled=0x00,timerNoScale=0x01,timerF_CPU8=0x02,timerF_CPU64=0x03,timerF_CPU256=0x04,timerF_CPU1024=0x05,TimerExtFalling=0x06,TimerExtRising=0x07
}Timer_prescaler;

typedef enum
{
TimerCompareInt=0x02 ,TimerOverflowInt=0x01,TimerMaskDisabled=0x00
}Timer_mask;



typedef struct
{
	uint8	Timer_initVal;
	uint8	Compare_value;
	ComparePort Port;
	TimerMode	Timer_mode;
	Timer_prescaler	Timer_scale;
	Timer_mask intmask;
}config_timer;

void timerinit( const config_timer *config);

void timerDinit(void);

void timerreset(void);
void timercallback();
