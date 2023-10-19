/*
 ================================================================================================================================
 * File Name   : ultrasonic.h
 *
 * Module Name : Ultrasonic
 *
 * Description : Header file for Ultrasonic driver
 *
 * Created On  : Oct 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ULTRASONIC_TRIGGER_PORT_ID          PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID           PIN5_ID
#define ULTRASONIC_NUM_OF_DETECTED_EDGES    2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initialize the Ultrasonic driver by:
 * 1. Initialize the Trigger pin direction
 * 2. Initialize the ICU driver and Its Call back function.
 */
void Ultrasonic_init(void);
/*
 * Description :
 * Function calculates the distance measured by the Ultrasonic sensor by:
 * 1. Clear all the variables from the previous read operation.
 * 2. Clear the ICU timer register
 * 3. Send the Trigger to the Ultrasonic by call Ultrasonic_Trigger function
 * 4. Wait for the measurements to be done by the ICU. We need two edges raising and falling bec of echo pin.
 * 5. Calculate the distance
 */

uint16 Ultrasonic_readDistance(void);


#endif /* ULTRASONIC_H_ */
