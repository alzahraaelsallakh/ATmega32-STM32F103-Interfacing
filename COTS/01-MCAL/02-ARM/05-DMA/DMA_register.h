/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 30 Mar 2020                            */
/* Layer: MCAL                                  */
/* Component: DMA                               */
/* File Name: DMA_register.h                    */  
/************************************************/

#ifndef DMA_REGISTER_H
#define DMA_REGISTER_H


/* Register per channel */
typedef struct 
{
  u32 CCR;
  u32 CNDTR;
  u32 CPAR;
  u32 CMAR;
  u32 Reserved;
  
}DMA_Channel;

/* General DMA registers */
typedef struct 
{
  u32 ISR;
  u32 IFCR;
  DMA_Channel Channel[7];
  
}DMA_t;


#define DMA  ((volatile DMA_t*) 0x40020000)


#endif
