/*
 * SPI_interface.h
 *
 *  Created on: Aug 14, 2022
 *      Author: Alaa Sayd
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
u8 SPI_u8Transcieve(u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
