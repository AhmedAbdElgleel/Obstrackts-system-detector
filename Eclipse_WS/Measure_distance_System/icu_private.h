/*
 ================================================================================================================================
 * File Name   : icu_private.h
 *
 * Module Name : icu_private
 * 
 * Description : Private header File for ICU module Registers
 *
 * Created On  : Oct 18, 2023
 *
 * Author Name : Ahmed Abd Elgleel
 ================================================================================================================================
 */
#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

#include "std_types.h"
/*******************************************************************************
 *                  Registers type structure declaration for timer1            *
 *******************************************************************************/
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 WGM10_Bit :1;
		uint8 WGM11_Bit :1;
		uint8 FOC1A_Bit :1;
		uint8 FOC1B_Bit :1;
		uint8 COM1B0_Bit :1;
		uint8 COM1B1_Bit :1;
		uint8 COM1A0_Bit :1;
		uint8 COM1A1_Bit :1;
	} Bits;
} Timer1_TCCR1A_Type;

typedef union
{
	uint8 Byte;
	struct
	{
		uint8 CS10_Bit :1;
		uint8 CS11_Bit :1;
		uint8 CS12_Bit :1;
		uint8 WGM12_Bit :1;
		uint8 WGM13_Bit :1;
		uint8 :1;
		uint8 ICES1_Bit :1;
		uint8 ICNC1_Bit :1;
	} Bits;
} Timer1_TCCR1B_Type;

typedef union
{
	uint16 TwoBytes;
	struct
	{
		uint16 Bit0 :1;
		uint16 Bit1 :1;
		uint16 Bit2 :1;
		uint16 Bit3 :1;
		uint16 Bit4 :1;
		uint16 Bit5 :1;
		uint16 Bit6 :1;
		uint16 Bit7 :1;
		uint16 Bit8 :1;
		uint16 Bit9 :1;
		uint16 Bit10 :1;
		uint16 Bit11 :1;
		uint16 Bit12 :1;
		uint16 Bit13 :1;
		uint16 Bit14 :1;
		uint16 Bit15 :1;
	} Bits;
} Timer1_TCNT1_Type;

typedef union
{
	uint16 TwoBytes;
	struct
	{
		uint16 Bit0 :1;
		uint16 Bit1 :1;
		uint16 Bit2 :1;
		uint16 Bit3 :1;
		uint16 Bit :1;
		uint16 Bit5 :1;
		uint16 Bit6 :1;
		uint16 Bit7 :1;
		uint16 Bit8 :1;
		uint16 Bit9 :1;
		uint16 Bit10 :1;
		uint16 Bit11 :1;
		uint16 Bit12 :1;
		uint16 Bit13 :1;
		uint16 Bit14 :1;
		uint16 Bit15 :1;
	} Bits;
} Timer1_OCR1A_Type;

typedef union
{
	uint16 TwoBytes;
	struct
	{
		uint16 Bit0 :1;
		uint16 Bit1 :1;
		uint16 Bit2 :1;
		uint16 Bit3 :1;
		uint16 Bit :1;
		uint16 Bit5 :1;
		uint16 Bit6 :1;
		uint16 Bit7 :1;
		uint16 Bit8 :1;
		uint16 Bit9 :1;
		uint16 Bit10 :1;
		uint16 Bit11 :1;
		uint16 Bit12 :1;
		uint16 Bit13 :1;
		uint16 Bit14 :1;
		uint16 Bit15 :1;
	} Bits;
} Timer1_OCR1B_Type;

typedef union
{
	uint16 TwoBytes;
	struct
	{
		uint16 Bit0 :1;
		uint16 Bit1 :1;
		uint16 Bit2 :1;
		uint16 Bit3 :1;
		uint16 Bit :1;
		uint16 Bit5 :1;
		uint16 Bit6 :1;
		uint16 Bit7 :1;
		uint16 Bit8 :1;
		uint16 Bit9 :1;
		uint16 Bit10 :1;
		uint16 Bit11 :1;
		uint16 Bit12 :1;
		uint16 Bit13 :1;
		uint16 Bit14 :1;
		uint16 Bit15 :1;
	} Bits;
} Timer1_ICR1_Type;

typedef union
{
	uint8 Byte;
	struct
	{
		uint8 TOIE0_Bit :1;
		uint8 OCIE0_Bit :1;
		uint8 TOIE1_Bit :1;
		uint8 OCIE1B_Bit :1;
		uint8 OCIE1A_Bit :1;
		uint8 TICIE1_Bit :1;
		uint8 TOIE2_Bit :1;
		uint8 OCIE2_Bit :1;
	} Bits;
} Timers_TIMSK_Type;

typedef union
{
	uint8 Byte;
	struct
	{
		uint8 TOV0_Bit :1;
		uint8 OCF0_Bit :1;
		uint8 TOV1_Bit :1;
		uint8 OCF1B_Bit :1;
		uint8 OCF1A_Bit :1;
		uint8 ICF1_Bit :1;
		uint8 TOV2_Bit :1;
		uint8 OCF2_Bit :1;
	} Bits;
} Timers_TIFR_Type;

/*******************************************************************************
 * Registers definitions for each type struct in the memory mapped Registers   *
 *******************************************************************************/
#define TIMER1_TCNT1_REG     (*((volatile Timer1_TCNT1_Type* const )0x004C))
#define TIMER1_TCCR1A_REG    (*((volatile Timer1_TCCR1A_Type* const)0x004F))
#define TIMER1_TCCR1B_REG    (*((volatile Timer1_TCCR1B_Type* const)0x004E))
#define TIMER1_TIFR_REG      (*((volatile Timers_TIFR_Type* const)0x0058))
#define TIMER1_TIMSK_REG     (*((volatile Timers_TIMSK_Type* const)0x0059))
#define TIMER1_OCR1A_REG     (*((volatile Timer1_OCR1A_Type* const)0x004A))
#define TIMER1_OCR1B_REG     (*((volatile Timer1_OCR1B_Type* const)0x0048))
#define TIMER1_ICR1_REG      (*((volatile Timer1_ICR1_Type* const)0x0046))

#endif /* ICU_PRIVATE_H_ */
