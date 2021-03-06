/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 11 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: URTM                              */
/* File Name: URTM_program.c                    */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "UART_interface.h"

#include "URTM_interface.h"
#include "URTM_config.h"
#include "URTM_private.h"


URTM_JobRequest URTM_QUEUE [URTM_u8_MAX_QUEUE_SIZE];

u8 URTM_QCurrent = 0;
u8 URTM_QNext = 0;
u8 URTM_QAvailableSize = URTM_u8_MAX_QUEUE_SIZE;
u8 URTM_BusyFlag = 0;
u8 URTM_AsynchCounter = 0;

STD_TYPES_ERROR URTM_u8PerformJobRequest (URTM_JobRequest Copy_JobInfo)
{
	u8 Local_u8ErrorStatus = STD_TYPES_ERROR_OK;

	/* Add job to the next location */
	if (URTM_QAvailableSize > 0)
	{
		/* Add the job to the queue "Enqueue" */

		URTM_QAvailableSize--;
		URTM_QUEUE[URTM_QNext] = Copy_JobInfo;

		/* Increment the next */
		if (URTM_QNext == URTM_u8_MAX_QUEUE_SIZE - 1)
		{
			URTM_QNext = 0;
		}
		else
		{
			URTM_QNext++;
		}

	}
	else
	{
		Local_u8ErrorStatus = STD_TYPES_ERROR_NOK;
	}

	return Local_u8ErrorStatus;
}

STD_TYPES_ERROR URTM_voidExecuteJobs(void)
{
	STD_TYPES_ERROR Local_u8ErrorStatus = STD_TYPES_ERROR_OK;

	if (URTM_BusyFlag == 0)
	{
		voidStart();
	}
	else
	{
		/* Do Nothing */
	}

	return Local_u8ErrorStatus;
}

static void voidStart (void)
{
	u8 Local_u8WhileFlag;

	while (1)
	{
		/* Queue is empty */
		if (URTM_QAvailableSize == URTM_u8_MAX_QUEUE_SIZE)
		{
			URTM_BusyFlag = 0;
			break;
		}
		/* Queue includes jobs */
		else
		{
			URTM_BusyFlag = 1;

			/* Start job */
			switch(URTM_QUEUE[URTM_QCurrent].JobType)
			{
			case URTM_SEND_SYNC: voidSendSync(); break;

			case URTM_REC_SYNC:  voidRecSync(); break;

			case URTM_SEND_ASYNCH: voidSendAsynch();  Local_u8WhileFlag = 1; break;

			case URTM_REC_ASYNCH: voidRecAsynch(); Local_u8WhileFlag = 1; break;
			}

			if (Local_u8WhileFlag == 1)
			{
				/* Break the while due to asynchronous job */
				break;
			}
		}
	}


}

static void voidRecAsynch (void)
{
	URTM_AsynchCounter = 0;
	UART_u8ReceiveAsynch(&(URTM_QUEUE[URTM_QCurrent].DataBuffer[URTM_AsynchCounter]),&AsynchCallBack);
	URTM_AsynchCounter ++;
}

static void voidSendAsynch (void)
{
	URTM_AsynchCounter = 0;
	UART_u8TransmitDataAsynch((URTM_QUEUE[URTM_QCurrent].DataBuffer[URTM_AsynchCounter]),&AsynchCallBack);
	URTM_AsynchCounter ++;
}

static void voidRecSync (void)
{
	u8 Local_u8Counter;
	for (Local_u8Counter = 0; Local_u8Counter < URTM_QUEUE[URTM_QCurrent].Length ; Local_u8Counter ++)
	{
		UART_u8ReceiveSynch(&(URTM_QUEUE[URTM_QCurrent].DataBuffer[Local_u8Counter]));
	}

	URTM_QAvailableSize++;

	/* Increment the current */
	if (URTM_QCurrent == URTM_u8_MAX_QUEUE_SIZE - 1)
	{
		URTM_QCurrent = 0;
	}
	else
	{
		URTM_QCurrent++;
	}
}

static void voidSendSync (void)
{
	u8 Local_u8Counter;
	for (Local_u8Counter = 0; Local_u8Counter < URTM_QUEUE[URTM_QCurrent].Length ; Local_u8Counter ++)
	{
		UART_u8TransmitDataSynch (URTM_QUEUE[URTM_QCurrent].DataBuffer[Local_u8Counter]);
	}

	URTM_QAvailableSize++;

	/* Increment the current */
	if (URTM_QCurrent == URTM_u8_MAX_QUEUE_SIZE - 1)
	{
		URTM_QCurrent = 0;
	}
	else
	{
		URTM_QCurrent++;
	}
}

static void AsynchCallBack(void)
{
	if (URTM_AsynchCounter < URTM_QUEUE[URTM_QCurrent].Length)
	{
		switch (URTM_QUEUE[URTM_QCurrent].JobType)
		{
		case URTM_SEND_ASYNCH:
			UART_u8TransmitDataAsynch((URTM_QUEUE[URTM_QCurrent].DataBuffer[URTM_AsynchCounter]),&AsynchCallBack);
			break;
		case URTM_REC_ASYNCH:
			UART_u8ReceiveAsynch(&(URTM_QUEUE[URTM_QCurrent].DataBuffer[URTM_AsynchCounter]),&AsynchCallBack);
			break;
		}
		URTM_AsynchCounter++;
	}
	else
	{
		/* Job is done, call application callback function and then start new job */
		URTM_QUEUE[URTM_QCurrent].CallBack();

		URTM_QAvailableSize++;

		if (URTM_QCurrent == (URTM_u8_MAX_QUEUE_SIZE -1))
		{
			URTM_QCurrent = 0;
		}
		else
		{
			URTM_QCurrent++;
		}

		URTM_BusyFlag = 0;
	}
}
