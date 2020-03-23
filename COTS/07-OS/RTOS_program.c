/**********************************************/
/* Author: Alzahraa Elsallakh                 */
/* Version: V01                               */
/* Date: 11 Feb 2020                          */
/* Layer: OS                                  */
/* Component: RTOS                            */
/* File Name: RTOS_program.c                  */
/**********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"



typedef struct 
{
  void (*TaskHandler)(void);
  f32 Periodicity;
  u32 FirstDelay;
  u8 State;
} Task;

Task RTOS_TaskSysTasks[NUM_OF_TASKS];

/*
**
**  Description: This function shall initiate RTOS by setting all tasks' periodicity values to -1
**  Input: void
**  Output: void
**
**/
extern void RTOS_voidInit (void)
{
  /* Setting initial periodicity values to all possible running tasks */
  for (u8 Local_u8TaskElement = 0; Local_u8TaskElement < NUM_OF_TASKS; Local_u8TaskElement ++)
  {
    RTOS_TaskSysTasks[Local_u8TaskElement].Periodicity = -1;  
  }
}

/*
**
**  Description: This function shall suspend any task by changing its state to RTOS_u8SUSPEND from RTOS_u8RUNNING
**  Input: Task ID number
**  Output: void
**
**/
extern void RTOS_voidSuspendTask (u8 Copy_u8TaskID)
{
  RTOS_TaskSysTasks[Copy_u8TaskID].State = RTOS_u8SUSPEND;
}

/*
**
**  Description: This function shall resume any task by changing its state to RTOS_u8RUNNING from RTOS_u8SUSPEND
**  Input: Task ID number
**  Output: void
**
**/
extern void RTOS_voidResumeTask (u8 Copy_u8TaskID)
{
  RTOS_TaskSysTasks[Copy_u8TaskID].State = RTOS_u8RUNNING;
}

/*
**
**  Description: This function shall schedule running tasks depending on their periodicity, first delay and their state
**  Input: void
**  Output: void
**
**/
static void RTOS_voidScheduler(void)
{
  
  for (u8 Local_u8TasksLoop = 0; Local_u8TasksLoop < NUM_OF_TASKS; Local_u8TasksLoop++)
  {
    if (RTOS_TaskSysTasks[Local_u8TasksLoop].State == RTOS_u8RUNNING)
    {
      /* Check task Periodicity against current tick */
      if (RTOS_TaskSysTasks[Local_u8TasksLoop].FirstDelay == 0)
      {
        (RTOS_TaskSysTasks[Local_u8TasksLoop].TaskHandler) ();
        RTOS_TaskSysTasks[Local_u8TasksLoop].FirstDelay = RTOS_TaskSysTasks[Local_u8TasksLoop].Periodicity - 1;
      }
      else
      {
        RTOS_TaskSysTasks[Local_u8TasksLoop].FirstDelay --;
      }
    }
    else
    {
      /* Task is suspended */
    }
  }
}

/*
**
**  Description: This function shall start the Real Time Operating System by setting the scheduler as call back function and starting Timer by the tick time
**  Input: void
**  Output: void
**
**/
extern void RTOS_voidStartOS(void)
{
    STK_voidSetCallBack(RTOS_voidScheduler);
    STK_voidStart(TICK_TIME);
}

/*
**
**  Description: This function shall create tasks by assigning their periodicity, call back function, first delay and state to the corresponding array that holds the whole tasks
**  Input: Task priority which represents task ID, Task periodicity represented in number of ticks, pointer to the task responsible function, 
           Task first delay at startup time and task initial state which could be RTOS_u8RUNNING or RTOS_u8SUSPEND
**  Output: void
**
**/
extern void RTOS_voidCreateTask(u32 Copy_u32Priority,f32 Copy_u32Periodicity,void(*Copy_HandlerPtr)(void), u32 Copy_u32FirstDelay, u8 Copy_u8InitialState)
{
  if (Copy_u32Priority < NUM_OF_TASKS && RTOS_TaskSysTasks[Copy_u32Priority].Periodicity == -1 )
  {
      RTOS_TaskSysTasks[Copy_u32Priority].TaskHandler = Copy_HandlerPtr;
      RTOS_TaskSysTasks[Copy_u32Priority].Periodicity = Copy_u32Periodicity;
      RTOS_TaskSysTasks[Copy_u32Priority].FirstDelay = Copy_u32FirstDelay;
      RTOS_TaskSysTasks[Copy_u32Priority].State = Copy_u8InitialState;
  }

}


/*
**
**  Description: This function shall delete task by assigning -1 to the periodicity of the corresponding task ID number
**  Input: Task ID number
**  Output: void
**
**/
extern void RTOS_voidDeleteTask(u8 Copy_u8TaskID)
{
    if (Copy_u8TaskID < NUM_OF_TASKS && RTOS_TaskSysTasks[Copy_u8TaskID].Periodicity != -1 )
    {
        RTOS_TaskSysTasks[Copy_u8TaskID].Periodicity = -1 ;
    }
}