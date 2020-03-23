/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 12 Dec 2019                          */
/* Layer: HAL                                 */
/* Component: SEVENSEG                        */
/* File Name: SEVENSEG_program.c              */
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVENSEG_interface.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_private.h"

#define SEVENSEG_u8_SEVENSEGMENTS_NUMBER 2

u8 SEVENSEG_u8LastNumber = SEVENSEG_u8_INITIAL_VALUE;

u8 SEVENSEG_u8EnablePorts [SEVENSEG_u8_SEVENSEGMENTS_NUMBER] = {SEVENSEG_u8_SEGMENTONE_ENABLE_PORT, SEVENSEG_u8_SEGMENTTWO_ENABLE_PORT};
u8 SEVENSEG_u8EnablePins [SEVENSEG_u8_SEVENSEGMENTS_NUMBER] =  {SEVENSEG_u8_SEGMENTONE_ENABLE_PIN, SEVENSEG_u8_SEGMENTTWO_ENABLE_PIN};


extern void SEVENSEG_voidSetNumber(u8 Copy_u8Number)
{
  u8 Local_u8SevenSegNumbers [10] = { 0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111 };
  
  /* Common Cathode */
  #if SEVENSEG_u8_MODE == 1
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_A, SEVENSEG_u8_PIN_A_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],0));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_B, SEVENSEG_u8_PIN_B_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],1));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_C, SEVENSEG_u8_PIN_C_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],2));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_D, SEVENSEG_u8_PIN_D_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],3));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_E, SEVENSEG_u8_PIN_E_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],4));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_F, SEVENSEG_u8_PIN_F_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],5));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_G, SEVENSEG_u8_PIN_G_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],6));
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_H, SEVENSEG_u8_PIN_H_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],7));
  /* Common Anode */
  #elif SEVENSEG_u8_MODE == 0
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_A, SEVENSEG_u8_PIN_A_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],0) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_B, SEVENSEG_u8_PIN_B_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],1) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_C, SEVENSEG_u8_PIN_C_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],2) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_D, SEVENSEG_u8_PIN_D_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],3) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_E, SEVENSEG_u8_PIN_E_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],4) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_F, SEVENSEG_u8_PIN_F_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],5) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_G, SEVENSEG_u8_PIN_G_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],6) ^0x01);
  DIO_voidSetPinValue(SEVENSEG_u8_PORT_H, SEVENSEG_u8_PIN_H_NUMBER, GET_BIT(Local_u8SevenSegNumbers[Copy_u8Number],7) ^0x01);
  #endif
  
  SEVENSEG_u8LastNumber = Copy_u8Number;
}

extern void SEVENSEG_voidEnable(u8 Copy_u8SEVENSEGNumber)
{

  /* Common Cathode */
  #if SEVENSEG_u8_MODE == 1
  DIO_voidSetPinValue(SEVENSEG_u8EnablePorts[Copy_u8SEVENSEGNumber], SEVENSEG_u8EnablePins[Copy_u8SEVENSEGNumber], 0); 
  /* Common Anode */
  #elif SEVENSEG_u8_MODE == 0
  DIO_voidSetPinValue(SEVENSEG_u8EnablePorts[Copy_u8SEVENSEGNumber], SEVENSEG_u8EnablePins[Copy_u8SEVENSEGNumber], 1); 
  #endif
  
  SEVENSEG_voidSetNumber (SEVENSEG_u8LastNumber);
  
}

extern void SEVENSEG_voidDisable(u8 Copy_u8SEVENSEGNumber)
{
  /* Common Cathode */
  #if SEVENSEG_u8_MODE == 1
  DIO_voidSetPinValue(SEVENSEG_u8EnablePorts[Copy_u8SEVENSEGNumber], SEVENSEG_u8EnablePins[Copy_u8SEVENSEGNumber], 1); 
  /* Common Anode */
  #elif SEVENSEG_u8_MODE == 0
  DIO_voidSetPinValue(SEVENSEG_u8EnablePorts[Copy_u8SEVENSEGNumber], SEVENSEG_u8EnablePins[Copy_u8SEVENSEGNumber], 0); 
  #endif
  
}