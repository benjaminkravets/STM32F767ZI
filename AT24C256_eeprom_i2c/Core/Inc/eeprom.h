/*
 * eeprom.h
 *
 *  Created on: Mar 14, 2024
 *      Author: bakra, based on controllerstech.com tutorial
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stdint.h"
#include "stm32f7xx.h"

//512 64 byte pages
#define PAGE_SIZE 64
#define PAGE_COUNT 512

void eeprom_write_bytes(I2C_HandleTypeDef* i2c, uint16_t page, uint16_t offset, uint8_t* data, uint16_t size);
void eeprom_read_bytes(I2C_HandleTypeDef* i2c, uint16_t page, uint16_t offset, uint8_t* data, uint16_t size);

void eeprom_erasepage(I2C_HandleTypeDef* i2c, uint16_t page);

#endif /* INC_EEPROM_H_ */
