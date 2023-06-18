/*

 * main.c
 *
 *  Created on: Aug 14, 2022
 *      Author: Alaa Sayed
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_register.h"


int main (void)
{

	//Mosi o/p
	//Miso i/p
	//Sck o/p
	//ss input pullup
	u8 Local_u8RecievedDData;

	DIO_voidInit();
	SPI_MasterInit();
	while(1)
	{
		Local_u8RecievedDData = SPI_u8Transcieve(1);
		_delay_ms(1000);

	}


	return 0;
}
