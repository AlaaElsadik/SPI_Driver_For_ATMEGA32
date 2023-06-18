/*

 * SPI_prog.c
 *
 *  Created on: Aug 14, 2022
 *      Author: Alaa Sayed
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_register.h"

void SPI_MasterInit(void)
{
	/*Master Mode Select => Set MSTR High */
	SET_BIT(SPCR,SPCR_MSTR);

	/*Choose Clock Polarity => Leading = Raising*/
	CLR_BIT(SPCR,SPCR_CPOL);

	/*Choose Clock Phase to sample first*/
	CLR_BIT(SPCR,SPCR_CPHA);

	/*Choose Speed => /16*/
	CLR_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);

	/*SPI Peripheral Enable*/
	SET_BIT(SPCR,SPCR_SPE);

}
void SPI_SlaveInit(void)
{
	/*Slave Mode Select => Set MSTR to LOW */
	CLR_BIT(SPCR,SPCR_MSTR);

	/*Choose Clock Polarity => Leading = Raising*/
	CLR_BIT(SPCR,SPCR_CPOL);

	/*Choose Clock Phase to sample first*/
	CLR_BIT(SPCR,SPCR_CPHA);

	/*SPI Peripheral Enable*/
	SET_BIT(SPCR,SPCR_SPE);



}
u8 SPI_u8Transcieve(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while((GET_BIT(SPSR,SPSR_SPIF)) == 0);

	return SPDR;

}
