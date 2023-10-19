/*
 ================================================================================================================================
 * File Name   : icu.c
 *
 * Module Name : ICU
 *
 * Description : Source file for ICU driver
 *
 * Created On  : Oct 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */

#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio_interface.h"
#include <avr/interrupt.h> /* For ICU ISR */
#include "icu_interface.h"
#include "icu_private.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr)
{
	/* Configure ICP1/PD6 as i/p pin */
	GPIO_setupPinDirection(PORTD_ID, PIN6_ID, PIN_INPUT);

	/* Timer1 always operates in Normal Mode */
	TIMER1_TCCR1A_REG.Byte=0;
	TIMER1_TCCR1A_REG.Bits.FOC1A_Bit=1;
	TIMER1_TCCR1A_REG.Bits.FOC1B_Bit=1;
	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
	TIMER1_TCCR1B_REG.Byte=(TIMER1_TCCR1B_REG.Byte & 0XF8)|(Config_Ptr->clock);
	/*
     * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TIMER1_TCCR1B_REG.Byte=(TIMER1_TCCR1B_REG.Byte& 0xBF)|((Config_Ptr->edge)<<6);

	/* Initial Value for Timer1 */
	TIMER1_TCNT1_REG.TwoBytes=0;
	/* Initial Value for the input capture register */
	TIMER1_ICR1_REG.TwoBytes = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMER1_TIMSK_REG.Bits.TICIE1_Bit=1;
}

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TIMER1_TCCR1B_REG.Byte=(TIMER1_TCCR1B_REG.Byte&0xBF)|(a_edgeType<<6);
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void)
{
	return TIMER1_ICR1_REG.TwoBytes;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void)
{
	TIMER1_TCNT1_REG.TwoBytes=0;
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void)
{
	/* Clear All Timer1/ICU Registers */
	TIMER1_TCCR1A_REG.Byte = 0;
	TIMER1_TCCR1B_REG.Byte = 0;
	TIMER1_TCNT1_REG.TwoBytes = 0;
	TIMER1_ICR1_REG.TwoBytes = 0;

	/* Disable the Input Capture interrupt */
	TIMER1_TIMSK_REG.Bits.TICIE1_Bit=1;
	/* Reset the global pointer value */
	g_callBackPtr = NULL_PTR;
}
