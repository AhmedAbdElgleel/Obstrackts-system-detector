/*
 ================================================================================================================================
 * File Name   : icu_interface.h
 *
 * Module Name : ICU
 *
 * Description : header file for ICU driver
 *
 * Created On  : Oct 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_ClockType;

typedef enum
{
	FALLING,RISING
}ICU_EdgeType;

typedef struct
{
	ICU_ClockType clock;
	ICU_EdgeType edge;
}ICU_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void);

#endif /* ICU_INTERFACE_H_ */
