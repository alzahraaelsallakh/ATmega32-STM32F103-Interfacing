#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_MS_interface.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

void main (void)
{
  PortInitialize();
  CLCD_voidInitialize();
  
  /* Sends the asci code as address */
  CLCD_voidWriteData('A');
  CLCD_voidWriteData('l');
  CLCD_voidWriteData('z');
  CLCD_voidWriteData('a');
  CLCD_voidWriteData('h');
  CLCD_voidWriteData('r');
  CLCD_voidWriteData('a');
  CLCD_voidWriteData('a');
  
}