/*
 * eeprom.c
 *
 *  Created on: Mar 14, 2024
 *      Author: bakra, based on controllerstech.com tutorial
 */


#include "eeprom.h"
#include "math.h"
#include "string.h"

//AT24C256 address (all pins 0)
#define EEPROM_ADDR 0xA0




//return how many bytes remain to be read or written during current operation
uint16_t remaining_bytes (uint16_t size, uint16_t offset){
	if ((size+offset) < PAGE_SIZE) return size;
	else return PAGE_SIZE-offset;
}

/*
 * void eeprom_write_bytes(I2C_HandleTypeDef* i2c, uint16_t page, uint16_t offset, uint8_t* data, uint16_t size)
 * Write bytes to AT24C256.
 * @param i2c handler for i2c instance to use
 * @param page to address within page count
 * @param offset bytes into the page within page size
 * @param data pointer to bytes to write
 * @param size how many bytes to write
 *
 */

void eeprom_write_bytes(I2C_HandleTypeDef* i2c, uint16_t page, uint16_t offset, uint8_t* data, uint16_t size){

	//Calculate bits to shift page number by
	int page_address_offset = log(PAGE_SIZE) / log(2);

	//start and end pages
	uint16_t start_page = page;
	uint16_t end_page = page + ((size+offset)/PAGE_SIZE);

	//number of pages to write
	uint16_t pages_to_write = (end_page-start_page) + 1;
	uint16_t pos=0;

	for (int i = 0; i<pages_to_write; i++){

		//get operative memory address by making page start 9 bits more significant, then "adding" the page offset.
		uint16_t mem_address = start_page << page_address_offset | offset;
		uint16_t bytes_remaining = remaining_bytes(size, offset);

		//write to chip
		HAL_I2C_Mem_Write(i2c, EEPROM_ADDR, mem_address, 2, &data[pos], bytes_remaining, 1000);

		//increase the start page and adjust offset, size, and position going forward.
		start_page += 1;
		offset = 0;
		size = size-bytes_remaining;
		pos += bytes_remaining;

		HAL_Delay(5);
	}
}

/*
 * void eeprom_read_bytes(I2C_HandleTypeDef* i2c, uint16_t page, uint16_t offset, uint8_t* data, uint16_t size)
 * Write bytes to AT24C256.
 * @param i2c handler for i2c instance to use
 * @param page to address within page count
 * @param offset bytes into the page within page size
 * @param data pointer to which data is read
 * @param size how many bytes to read
 *
 */

void eeprom_read_bytes(I2C_HandleTypeDef* i2c, uint16_t page, uint16_t offset, uint8_t* data, uint16_t size){

	//Calculate bits to shift page number by
	int page_address_offset = log(PAGE_SIZE) / log(2);

	//start and end pages
	uint16_t start_page = page;
	uint16_t end_page = page + ((size+offset)/PAGE_SIZE);

	//number of pages to write
	uint16_t pages_to_write = (end_page-start_page) + 1;
	uint16_t pos=0;

	for (int i = 0; i<pages_to_write; i++){

		//get operative memory address by making page start 9 bits more significant, then "adding" the page offset.
		uint16_t mem_address = start_page<<page_address_offset | offset;
		uint16_t bytes_remaining = remaining_bytes(size, offset);

		//write to chip
		HAL_I2C_Mem_Read(i2c, EEPROM_ADDR, mem_address, 2, &data[pos], bytes_remaining, 1000);

		//increase the start page and adjust offset, size, and position going forward.
		start_page += 1;
		offset = 0;
		size = size-bytes_remaining;
		pos += bytes_remaining;

	}
}

/*
 * void eeprom_erasepage(I2C_HandleTypeDef* i2c, uint16_t page)
 * Erase page
 * @param i2c handler for i2c instance to use
 * @param page to erase
 */

void eeprom_erasepage(I2C_HandleTypeDef* i2c, uint16_t page){

	//Calculate bits to shift page number by
	int page_address_offset = log(PAGE_SIZE)/log(2);

	//get operative memory address by making page start 9 bits more significant
	uint16_t mem_address = page << page_address_offset;

	//create memory of just zeroes to write to chip
	uint8_t data[PAGE_SIZE];
	memset(data,0xff,PAGE_SIZE);

	//write page as blank
	HAL_I2C_Mem_Write(i2c, EEPROM_ADDR, mem_address, 2, data, PAGE_SIZE, 1000);

	HAL_Delay(5);

}
