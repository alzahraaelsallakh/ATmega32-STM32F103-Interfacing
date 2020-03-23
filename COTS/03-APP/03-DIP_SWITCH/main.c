#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "DELAY_MS_interface.h"

#include "LED_interface.h"

int main(void)
{
	PortInitialize();

	u8 switchState;
	while (1)
	{
		for (u8 i = 0; i<5; i++ )
		{
			switchState = getPinValue('A',i);
			setPinValue('D',i,switchState ^0x01);
		}
	}


	return 0;
}
