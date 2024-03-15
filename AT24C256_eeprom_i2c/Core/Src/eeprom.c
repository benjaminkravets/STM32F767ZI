/*
 * eeprom.c
 *
 *  Created on: Mar 14, 2024
 *      Author: bakra
 */


#include "eeprom.h"
#include "math.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;

//AT24C256 address (all pins 0)
#define EEPROM_ADDR 0xA0


//512 64 byte pages
#define PAGE_SIZE 64
#define PAGE_COUNT 512


uint16_t remaining_bytes (uint16_t size, uint16_t offset){
	if ((size+offset) < PAGE_SIZE) return size;
	else return PAGE_SIZE-offset;
}

/*
 * void eeprom_write_bytes(uint16_t page, uint16_t offset, uint8_t* data, uint16_t size);
 * Write bytes to AT24C256.
 * @param page to address within page count
 * @param offset bytes into the page within page size
 * @param data pointer to bytes to write
 * @param size how many bytes to write
 *
 */

void eeprom_write_bytes(uint16_t page, uint16_t offset, uint8_t* data, uint16_t size){
	int paddrposition = log(PAGE_SIZE) / log(2);
}
void eeprom_read_bytes(uint16_t page, uint16_t offset, uint8_t* data, uint16_t size);
