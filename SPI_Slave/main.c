/*

 * main.c
 *
 *  Created on: Aug 14, 2022
 *      Author: Alaa Sayed
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_register.h"


int main (void)
{

	//Mosi o/p
	//Miso i/p
	//Sck o/p
	//ss input pullup
	u8 Local_u8RecievedData;
	DIO_voidInit();
	SPI_SlaveInit();
	while(1)
	{
		Local_u8RecievedData = SPI_u8Transcieve(0);
		if(Local_u8RecievedData == 1)
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
	}


	return 0;
}
