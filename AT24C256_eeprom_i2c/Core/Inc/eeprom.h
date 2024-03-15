/*
 * eeprom.h
 *
 *  Created on: Mar 14, 2024
 *      Author: bakra
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stdint.h";
#include "stm32f7xx.h"

void eeprom_write_bytes(uint16_t page, uint16_t offset, uint8_t* data, uint16_t size);
void eeprom_read_bytes(uint16_t page, uint16_t offset, uint8_t* data, uint16_t size);

void eeprom_erasepage(uint16_t page);

#endif /* INC_EEPROM_H_ */
