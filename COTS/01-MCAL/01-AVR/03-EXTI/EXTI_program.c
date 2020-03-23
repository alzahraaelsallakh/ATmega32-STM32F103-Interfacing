/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 4 Feb 2020                           */ 
/* Layer: MCAL                                */  
/* Component: EXTI                            */                
/* File Name: EXTI_program.c                  */ 
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_register.h"
#include "EXTI_private.h"


static void (*EXTI_ptrCallBackFunction[3]) (void) = {NULL,NULL,NULL};

/*
 * Description: A function to initailize external interrupts int0, int1 and int2
 *              according to the precompiled configurations
 * Input: void
 * Output: void
 */
extern void EXTI_voidInit(void)
{
  
    #if EXTI_u8_INT0_SENSE == LOW_LEVEL
      CLR_BIT(MCUCR,MCUCR_ISC00);
      CLR_BIT(MCUCR,MCUCR_ISC01);
    #elif EXTI_u8_INT0_SENSE == ON_CHANGE
      SET_BIT(MCUCR,MCUCR_ISC00);
      CLR_BIT(MCUCR,MCUCR_ISC01);
    #elif EXTI_u8_INT0_SENSE == FALLING_EDGE
      CLR_BIT(MCUCR,MCUCR_ISC00);
      SET_BIT(MCUCR,MCUCR_ISC01);
    #elif EXTI_u8_INT0_SENSE == RISING_EDGE
      SET_BIT(MCUCR,MCUCR_ISC00);
      SET_BIT(MCUCR,MCUCR_ISC01);
    #else
      #error "Wrong EXTI_u8_INT0_SENSE Configuration"
    #endif
    
    #if EXTI_u8_INT1_SENSE == LOW_LEVEL
      CLR_BIT(MCUCR,MCUCR_ISC10);
      CLR_BIT(MCUCR,MCUCR_ISC11);
    #elif EXTI_u8_INT1_SENSE == ON_CHANGE
      SET_BIT(MCUCR,MCUCR_ISC10);
      CLR_BIT(MCUCR,MCUCR_ISC11);
    #elif EXTI_u8_INT1_SENSE == FALLING_EDGE
      CLR_BIT(MCUCR,MCUCR_ISC10);
      SET_BIT(MCUCR,MCUCR_ISC11);
    #elif EXTI_u8_INT1_SENSE == RISING_EDGE
      SET_BIT(MCUCR,MCUCR_ISC10);
      SET_BIT(MCUCR,MCUCR_ISC11);
    #else
      #error "Wrong EXTI_u8_INT1_SENSE Configuration"
    #endif
    
    #if EXTI_u8_INT2_SENSE == FALLING_EDGE
      CLR_BIT(MCUCSR,MCUCSR_ISC2);
    #elif EXTI_u8_INT2_SENSE == RISING_EDGE
      SET_BIT(MCUCSR,MCUCSR_ISC2);
    #else
      #error "Wrong EXTI_u8_INT2_SENSE Configuration"
    #endif
  
  
  
  
    #if EXTI_u8_INT0_CONTROL == ENABLED
      SET_BIT(GICR,GICR_INT0);
    #elif EXTI_u8_INT0_CONTROL == DISABLED
      CLR_BIT(GICR,GICR_INT0);
    #else
      #error "Wrong EXTI_u8_INT0_CONTROL Configuration"
    #endif
    
    #if EXTI_u8_INT1_CONTROL == ENABLED
      SET_BIT(GICR,GICR_INT1);
    #elif EXTI_u8_INT1_CONTROL == DISABLED
      CLR_BIT(GICR,GICR_INT1);
    #else
      #error "Wrong EXTI_u8_INT1_CONTROL Configuration"
    #endif
    
    #if EXTI_u8_INT2_CONTROL == ENABLED
      SET_BIT(GICR,GICR_INT2);
    #elif EXTI_u8_INT2_CONTROL == DISABLED
      CLR_BIT(GICR,GICR_INT2);
    #else
      #error "Wrong EXTI_u8_INT2_CONTROL Configuration"
    #endif
}


/*
 * Description: A function to set enable of external interrupts int0,int1 and int2
 * Input: Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorIntEnable(u8 Copy_u8Idx)
{
  ErrorStatus Local_Error = OK;
  
  switch (Copy_u8Idx)
  {
    case EXTI_u8_INT0: SET_BIT(GICR,GICR_INT0); break;
    case EXTI_u8_INT1: SET_BIT(GICR,GICR_INT1); break;
    case EXTI_u8_INT2: SET_BIT(GICR,GICR_INT2); 
    default: Local_Error = NOK;
  }
  
  return Local_Error;
}

/*
 * Description: A function to set disable of external interrupts int0,int1 and int2
 * Input: Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorIntDisable(u8 Copy_u8Idx)
{
  ErrorStatus Local_Error = OK;
  
  switch (Copy_u8Idx)
  {
    case EXTI_u8_INT0: CLR_BIT(GICR,GICR_INT0); break;
    case EXTI_u8_INT1: CLR_BIT(GICR,GICR_INT1); break;
    case EXTI_u8_INT2: CLR_BIT(GICR,GICR_INT2); 
    default: Local_Error = NOK;
  }
  
  return Local_Error;  
}

/*
 * Description: A function to set the required sense level of external interrupts int0,int1 and int2
 * Input: 1- Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 *        2- required sense level, Ranges are:
 *                          1- EXTI_u8_LOW_LEVEL
 *                          2- EXTI_u8_ON_CHANGE
 *                          3- EXTI_u8_FALLING_EDGE
 *                          3- EXTI_u8_RISING_EDGE
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorSetSenseLevel(u8 Copy_u8Idx,u8 Copy_u8SenseLevel)
{
  ErrorStatus Local_Error = OK;
  
  switch (Copy_u8Idx)
  {
    case EXTI_u8_INT0: 
      switch (Copy_u8SenseLevel)
      {
        case (EXTI_u8_LOW_LEVEL):
          CLR_BIT(MCUCR,MCUCR_ISC00);
          CLR_BIT(MCUCR,MCUCR_ISC01);
          break;
        case (EXTI_u8_ON_CHANGE):
          SET_BIT(MCUCR,MCUCR_ISC00);
          CLR_BIT(MCUCR,MCUCR_ISC01);
          break;
        case (EXTI_u8_FALLING_EDGE):
          CLR_BIT(MCUCR,MCUCR_ISC00);
          SET_BIT(MCUCR,MCUCR_ISC01);
          break;
        case (EXTI_u8_RISING_EDGE):
          SET_BIT(MCUCR,MCUCR_ISC00);
          SET_BIT(MCUCR,MCUCR_ISC01);
        default: Local_Error = NOK;
          
      }
      break;
      
    case EXTI_u8_INT1: 
      switch (Copy_u8SenseLevel)
      {
        case (EXTI_u8_LOW_LEVEL):
          CLR_BIT(MCUCR,MCUCR_ISC10);
          CLR_BIT(MCUCR,MCUCR_ISC11);
          break;
        case (EXTI_u8_ON_CHANGE):
          SET_BIT(MCUCR,MCUCR_ISC10);
          CLR_BIT(MCUCR,MCUCR_ISC11);
          break;
        case (EXTI_u8_FALLING_EDGE):
          CLR_BIT(MCUCR,MCUCR_ISC10);
          SET_BIT(MCUCR,MCUCR_ISC11);
          break;
        case (EXTI_u8_RISING_EDGE):
          SET_BIT(MCUCR,MCUCR_ISC10);
          SET_BIT(MCUCR,MCUCR_ISC11);
        default: Local_Error = NOK;
          
      }
      break;
      
    case EXTI_u8_INT2: 
      switch (Copy_u8SenseLevel)
      {
        case (EXTI_u8_FALLING_EDGE):
          CLR_BIT(MCUCSR,MCUCSR_ISC2);
          break;
        case (EXTI_u8_RISING_EDGE):
          SET_BIT(MCUCSR,MCUCSR_ISC2);
        default: Local_Error = NOK;
          
      }
      
    default: Local_Error = NOK;
  }
  
  return Local_Error; 
}

/*
 * Description: A function to set the required address of ISR application function of int0, int1 and int2 
 * Input: 1- Interrupt Index, Ranges are:
 *                          1- EXTI_u8_INT0
 *                          2- EXTI_u8_INT1
 *                          3- EXTI_u8_INT2
 *        2- Pointer to the required callback application function
 * Output: Error Status
 */
extern ErrorStatus EXTI_errorSetCallBack(u8 Copy_u8Idx, void (*Copy_ptrCallBack)(void))
{
  ErrorStatus Local_Error = OK;
  
  if (Copy_ptrCallBack != NULL)
  {
    if (Copy_u8Idx < 3)
    {
      EXTI_ptrCallBackFunction[Copy_u8Idx] = Copy_ptrCallBack; 
    }
    else
    {
      Local_Error = NOK;
    }
    
  }
  else
  {
    Local_Error = NULLPOINTER;
  }
  
  return Local_Error;
  
}

/* ISR of INT0 */
void __vector_1(void)
{
  if (EXTI_ptrCallBackFunction[EXTI_u8_INT0]!= NULL)
  {
    EXTI_ptrCallBackFunction[EXTI_u8_INT0]();
  }
}

/* ISR of INT1 */
void __vector_2(void)
{
  if (EXTI_ptrCallBackFunction[EXTI_u8_INT1]!= NULL)
  {
    EXTI_ptrCallBackFunction[EXTI_u8_INT1]();
  }
}

/* ISR of INT2 */
void __vector_3(void)
{
  if (EXTI_ptrCallBackFunction[EXTI_u8_INT2]!= NULL)
  {
    EXTI_ptrCallBackFunction[EXTI_u8_INT2]();
  }
}