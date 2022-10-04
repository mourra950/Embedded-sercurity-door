#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define PinMotor1  				  PIN2_ID
#define PinMotor2                 PIN3_ID
#define PORTMotor  			      PORTD_ID
typedef enum
{
ClockWise_Motor,AntiClock_Motor,MotorDisabled
}MotorMode;


void MotorInit(void);
void MotorM(MotorMode mode);

#endif
