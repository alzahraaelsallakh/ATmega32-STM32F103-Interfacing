/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 11 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: URTM                              */
/* File Name: URTM_interface.h                  */
/************************************************/

#ifndef URTM_INTERFACE_H
#define URTM_INTERFACE_H

#define URTM_SEND_SYNC    0 
#define URTM_SEND_ASYNCH  1
#define URTM_REC_SYNC     2
#define URTM_REC_ASYNCH   2


typedef struct 
{
  u8 JobType;
  u8 * DataBuffer;
  u8 Length;
  void (*CallBack)(void);
}URTM_JobRequest;


u8 URTM_u8PerformJobRequest (URTM_JobRequest Copy_JobInfo);



#endif
