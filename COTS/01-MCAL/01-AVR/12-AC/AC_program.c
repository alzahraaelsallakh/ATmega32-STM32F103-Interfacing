/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 17 May 2020                            */
/* Layer: MCAL                                  */
/* Component: AC                                */
/* File Name: AC_program.c                      */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "AC_interface.h"
#include "AC_private.h"
#include "AC_config.h"
#include "AC_register.h"

static void (*AC_globalNotificationFnPosGreaterNeg)(void) = NULL;
static void (*AC_globalNotificationFnNegGreaterPos)(void) = NULL;


void __vector_18 (void) __attribute__((signal));


/*
    Description: This function shall initiate AC
    Input: void
    output: STD_TYPES_ERROR
 */
STD_TYPES_ERROR AC_errAnalogCompInit (void)
{
	STD_TYPES_ERROR local_errStatus = STD_TYPES_ERROR_OK;


	/* Input positive pin configuration  */
#if (AC_u8_POSITIVE_PIN_INPUT_STATE == AC_u8_POSITIVE_PIN_INPUT_AIN0)
	CLR_BIT(ACSR,BAND_GAP_PIN);

#elif (AC_u8_POSITIVE_PIN_INPUT_STATE == AC_u8_POSITIVE_PIN_INPUT_VOLTAGE_BAND_GAP)
	SET_BIT(ACSR,BAND_GAP_PIN);
#endif

	/* Input positive pin configuration  */
#if (AC_u8_NEGATIVE_PIN_INPUT_STATE == AC_u8_NEGATIVE_PIN_INPUT_AIN1)
	CLR_BIT(SFIOR,ACME_PIN);
#else
	SET_BIT(SFIOR,ACME_PIN);
	/* Check ADC enable */

	/* Choose negative channel after clearing ADMUX */
	ADMUX &=~(0b00011111);
	ADMUX |= AC_u8_NEGATIVE_PIN_INPUT_STATE;
#endif

#if (AC_u8_ANALOG_COMPARATOR_INTERRUPT_INIT == AC_u8_INTERRUPT_ENABLE)

	ACSR |= AC_u8_ANALOG_COMPARATOR_INTERRUPT_TRIGGER_SRC_INIT;
	SET_BIT(ACSR,ACIE_PIN);

#elif (AC_u8_ANALOG_COMPARATOR_INTERRUPT_INIT == AC_u8_INTERRUPT_DISABLE)
	CLR_BIT(ACSR,ACIE_PIN);

#endif

	/* AC ICE enable */


	return local_errStatus;
}


/*
    Description: This function shall get the output of the analog comparator synchronous
    Input:
    	1- Copy_u8AnalogComOutput -> Pointer to hold the output value
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR AC_errGetAnalogCompOutputValueSynch (u8 * Copy_u8AnalogComOutput)
{
	STD_TYPES_ERROR local_errStatus = STD_TYPES_ERROR_OK;

	if (Copy_u8AnalogComOutput == NULL)
	{
		local_errStatus = STD_TYPES_ERROR_NULL_POINTER;
	}
	else
	{
		*Copy_u8AnalogComOutput = GET_BIT(ACSR,ACO_PIN);
	}

	return local_errStatus;
}

/*
    Description: This function shall get the output of the analog comparator synchronous
    Input:
    	1- Copy_u8AnalogComOutput -> Pointer to hold the output value
    	2- Copy_NotifyPosGreaterNeg -> Callback function to be called if the positive value is greater than the negative value
    	3- Copy_NotifyNegGreaterPos -> Callback function to be called if the negative value is greater than the positive value
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR AC_errGetAnalogCompOutputValueAsynch (u8 * Copy_u8AnalogComOutput, void (* Copy_NotifyPosGreaterNeg)(void),void (* Copy_NotifyNegGreaterPos)(void))
{
	STD_TYPES_ERROR local_errStatus = STD_TYPES_ERROR_OK;

	if (Copy_u8AnalogComOutput == NULL || Copy_NotifyPosGreaterNeg == NULL || Copy_NotifyNegGreaterPos == NULL)
	{
		local_errStatus = STD_TYPES_ERROR_NULL_POINTER;
	}
	else
	{
		*Copy_u8AnalogComOutput = GET_BIT(ACSR, ACO_PIN);
		AC_globalNotificationFnPosGreaterNeg = Copy_NotifyPosGreaterNeg;
		AC_globalNotificationFnNegGreaterPos = Copy_NotifyNegGreaterPos;

		/* Enable interrupt of analog comparator */
		ACSR |= AC_u8_ANALOG_COMPARATOR_INTERRUPT_TRIGGER_SRC_INIT;
		SET_BIT(ACSR,ACIE_PIN);
	}

	return local_errStatus;
}

/*
    Description: This function shall disable AC
    Input: void
    output: STD_TYPES_ERROR
 */
extern STD_TYPES_ERROR AC_errAnalogCompDisable (void)
{
	STD_TYPES_ERROR local_errStatus = STD_TYPES_ERROR_OK;


	return local_errStatus;
}



void __vector_18 (void)
{

#if (AC_u8_ANALOG_COMPARATOR_INTERRUPT_TRIGGER_SRC_INIT == AC_u8_INTERRUPT_MODE_FALLING)

	AC_globalNotificationFnNegGreaterPos();

#elif (AC_u8_ANALOG_COMPARATOR_INTERRUPT_TRIGGER_SRC_INIT == AC_u8_INTERRUPT_MODE_RISING)

	AC_globalNotificationFnPosGreaterNeg();

#elif (AC_u8_ANALOG_COMPARATOR_INTERRUPT_TRIGGER_SRC_INIT == AC_u8_INTERRUPT_MODE_TOGGLE)
	if (GET_BIT(ACSR,ACO_PIN) == AC_u8_ANALOG_COMPARATOR_OUTPUT_POS_GREATER_NEG)
	{
		AC_globalNotificationFnPosGreaterNeg();
	}
	else
	{
		AC_globalNotificationFnNegGreaterPos();
	}

#endif

	/* Disable interrupt */
	CLR_BIT(ACSR,ACIE_PIN);

}
