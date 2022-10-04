#include "lcd.h"
#include "keypad.h"
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>
#include "icu.h"
#include "uart.h"
#include "common_macros.h"
#include "std_types.h"

#define MC2_READY 0x10

void printStar() {
	LCD_displayCharacter('*');
	_delay_ms(500);
}

void ShortMessage(uint8 s) {

	LCD_clearScreen();
	if (s == 0)
		LCD_displayString("Success");
	else
		LCD_displayString("Failed Try again");
	_delay_ms(1000);
	LCD_clearScreen();

}


/*Case 1 is the entry of the program when the system start
 *ask for password twice if they are equal to each
 *advance to case 2
 *else go to case 1 again
*/
uint8 case1(void) {
	//clear screen to start the program
	LCD_clearScreen();
	LCD_displayString("Pass :");
	LCD_moveCursor(1, 0);
	//

	uint8 key, count = 0, response = 0;
	while (count < 4) {
		key = KEYPAD_getPressedKey();
		if ((key >= 0) && (key <= 9)) {
			count++;
			UART_sendByte(key);
			printStar();
		}
	}

	LCD_clearScreen();
	LCD_displayString("AGAIN :");
	LCD_moveCursor(1, 0);

	while (count < 8) {
		key = KEYPAD_getPressedKey();
		if ((key >= 0) && (key <= 9)) {
			count++;
			UART_sendByte(key);
			printStar();
		}
	}

	LCD_clearScreen();
	response = UART_recieveByte();

	//response = 1 means success
	if (response == 2) {
		ShortMessage(0);
		return 2;
	} else {
		ShortMessage(1);
		return 1;
	}
}

uint8 case2(void) {
	uint8 key = 0;
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "open door : +");
	LCD_displayStringRowColumn(1, 0, "Change Pass : -");
	while (1) {
		key = KEYPAD_getPressedKey();
		if (key == '+') {
			UART_sendByte(3);
			return 3;
		} else if (key == '-') {
			UART_sendByte(4);
			return 4;
		}
	}
}

uint8 case3(void) {
	uint8 key = 0, response = 0;
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "enter P:");
	LCD_moveCursor(1, 0);
	uint8 count1 = 0;

	for (int i = 0; i < 4; i++) {
		_delay_ms(200);
		key = KEYPAD_getPressedKey();
		if ((key >= 0) && (key <= 9)) {
			count1++;
			UART_sendByte(key);
			printStar();

		}

	}
	_delay_ms(200);

	response = UART_recieveByte();
//	LCD_intgerToString(response);
	if (response == 5) {
		return 5;
	} else if (response == 3) {
		return 3;
	} else if (response == 2) {
		return 2;
	}

}

uint8 case4(void) {
	uint8 key = 0, response = 0;
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "Please enter P:");
	LCD_moveCursor(1, 0);
	uint8 count = 0;
	for (int i = 0; i < 4; i++) {
		_delay_ms(100);
		key = KEYPAD_getPressedKey();
		if ((key >= 0) && (key <= 9)) {
			count++;
			UART_sendByte(key);
			printStar();

		} else {
			while (count < 4) {
				_delay_ms(200);
				count++;
				UART_sendByte(0);
			}
		}
	}
	response = UART_recieveByte();
	if (response == 5) {
		return 5;
	} else if (response == 4) {
		return 4;
	} else if (response == 1) {
		return 1;
	}

}

uint8 case5(void) {
	LCD_clearScreen();
	LCD_displayString("error 3 times");
	_delay_ms(20000);
	return 2;
}




int main(void) {
	config_uart config = { B_9600, EigthBits, disabled_parity, stop_one };
	LCD_init();
	UART_init(&config);
	while (UART_recieveByte() != MC2_READY) {
	}

	uint8 CASE = 1;
	while (1) {
		_delay_ms(50);
		//case 1
		if (CASE == 1)
			CASE = case1();

		_delay_ms(50);
		//case 2
		if (CASE == 2)
			CASE = case2();
		_delay_ms(100);
		//case 3
		if (CASE == 3)
			CASE = case3();
		_delay_ms(100);
		//case 4
		if (CASE == 4)
			CASE = case4();
		_delay_ms(50);
		//case 5
		if (CASE == 5)
			CASE = case5();

	}

}
