/*
 ================================================================================================================================
 * File Name   : main.c
 *
 * Module Name : main
 *
 * Created On  : OCT 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#include "lcd.h"
#include "buzzer.h"
#include "led.h"
#include "ultrasonic.h"
#include"Internal_mapping_register_private.h"/*for Global interrupt enable*/
#include <util/delay.h>
int main(void)
{
	uint16 distance = 0;

	/*Enable Global Interrupt*/
	SREG_REG.Bits.I_Bit=1;

	/*Initialization of LCD*/
	LCD_init();

	/*Initialization of the Buzzer*/
	BUZZER_init();

	/*Initialization of the Ultrasonic sensor*/
	Ultrasonic_init();

	/*Initialization of the define LEDS*/
	LED_init();

	LCD_displayString("Distance= ");

	while(1)
	{
		/* Read the distance from the Ultrasonic sensor */
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
		LCD_displayString(" cm   ");

		if(distance <= 5)
		{
			BUZZER_on();
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			_delay_ms(250);
			BUZZER_off();
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			_delay_ms(250);
		}
		else if(distance<=10)
		{
			BUZZER_off();
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			}
		else if(distance<=15)
		{
			BUZZER_off();
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if(distance<=20)
		{
			BUZZER_off();
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if(distance<=25)
		{
			BUZZER_off();
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else
		{

		}
		_delay_ms(250);
	}
}
