/*
 ================================================================================================================================
 * File Name   : led.c
 *
 * Module Name : LED
 *
 * Description : Source file for LED driver
 *
 * Created On  : Oct 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#include "led.h"
#include "gpio_interface.h"
/*
 * Description :
 * Function to initialize the required led using gpio and initially turn it off .
 */
void LED_init(void)
{
#ifdef RED_LED
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, TURN_OFF_LED);
#endif
#ifdef GREEN_LED
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, TURN_OFF_LED);
#endif
#ifdef BLUE_LED
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, TURN_OFF_LED);
#endif
}
/*
 * Description :
 * Function to turn on the required led using gpio .
 */
void LED_on(uint8 a_led_id)
{
	/*this mean that is is the Red Led*/
	if(0==a_led_id)
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, TURN_ON_LED);
	}
	/*this mean that is is the green Led*/
	else if (1==a_led_id)
	{
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, TURN_ON_LED);
	}
	/*this mean that is is the blue Led*/
	else if (2==a_led_id)
	{
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, TURN_ON_LED);
	}
	else
	{
		/*handling more LED_id if u need to connect more leds*/
	}

}

/*
 * Description :
 * Function to turn off the required led using gpio .
 */
void LED_off(uint8 a_led_id)
{
	/*this mean that is is the Red Led*/
	if(0==a_led_id)
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, TURN_OFF_LED);
	}
	/*this mean that is is the green Led*/
	else if (1==a_led_id)
	{
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, TURN_OFF_LED);
	}
	/*this mean that is is the blue Led*/
	else if (2==a_led_id)
	{
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, TURN_OFF_LED);
	}
	else
	{
		/*handling more LED_id if u need to connect more leds*/
	}

}

/*
 * Description :
 * Function to toggle the required led using gpio .
 */
void LED_toggle(uint8 a_led_id)
{
	/*this mean that is is the Red Led*/
	if(0==a_led_id)
	{
		GPIO_togglePin(RED_LED_PORT_ID, RED_LED_PIN_ID);
	}
	/*this mean that is is the green Led*/
	else if (1==a_led_id)
	{
		GPIO_togglePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID);
	}
	/*this mean that is is the blue Led*/
	else if (2==a_led_id)
	{
		GPIO_togglePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID);
	}
	else
	{
		/*handling more LED_id if u need to connect more leds*/
	}
}
