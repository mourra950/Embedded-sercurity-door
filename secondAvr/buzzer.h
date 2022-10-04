#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"
#include <util/delay.h>

#define BuzzPort PORTC_ID
#define BuzzPin PIN3_ID

void Buzzinit(void);
void Buzzon(void);

void Buzzoff(void);
