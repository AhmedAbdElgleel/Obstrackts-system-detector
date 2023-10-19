/*
 ================================================================================================================================
 * File Name   : led.h
 *
 * Module Name : LED
 *
 * Description : Header file for LED driver
 *
 * Created On  : Oct 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#ifndef LED_H_
#define LED_H_
#include"std_types.h"

/*this #define was made to be used in the app to prevent using magic number*/
#define RED_LED				0
#define GREEN_LED			1
#define BLUE_LED			2

#define RED_LED_PORT_ID			PORTC_ID
#define RED_LED_PIN_ID			PIN0_ID

#define GREEN_LED_PORT_ID		PORTC_ID
#define GREEN_LED_PIN_ID		PIN1_ID

#define BLUE_LED_PORT_ID		PORTC_ID
#define BLUE_LED_PIN_ID			PIN2_ID

/*this define is responsible led connection mode*/
#define LED_POSTIVE_LOGIC


#ifdef LED_POSTIVE_LOGIC
#define TURN_ON_LED		LOGIC_HIGH
#define TURN_OFF_LED	LOGIC_LOW
#elif LED_Negative_LOGIC
#define TURN_ON_LED		LOGIC_LOW
#define TURN_OFF_LED	LOGIC_HIGH
#else
#error "Choose LED connection mode (LED_POSTIVE_LOGIC or LED_Negative_LOGIC)"
#endif

/*
 * Description :
 * Function to initialize the required led using gpio .
 */
void LED_init(void);

/*
 * Description :
 * Function to turn on the required led using gpio .
 */
void LED_on(uint8 a_led_id);

/*
 * Description :
 * Function to turn off the required led using gpio .
 */
void LED_off(uint8 a_led_id);

/*
 * Description :
 * Function to toggle the required led using gpio .
 */
void LED_toggle(uint8 a_led_id);

#endif /* LED_H_ */
