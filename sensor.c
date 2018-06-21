/*
 * sensor.c
 *
 * Created: 11/05/2018 11:23:34
 *  Author: Eric
 */ 
#include "sensor.h"
#include "app.h"

void mysensortask(void *p)
{
	uint8_t i = 0;
	uint8_t status;
	uint8_t pdata;
	
	display_init(FOSC0*8);
	//display_init(configCPU_CLOCK_HZ);
	
	I2C_Init();
	
	/* Check that Proximity sensor is OK */
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, 0x0F, &status);
	if (status != 104) {
		dip204_set_cursor_position(1,1);
		dip204_printf_string("Sensor error");
		while(1) {
			vTaskDelay(mainLCDTEST_PERIOD);
		}
		} else {
		dip204_set_cursor_position(1,1);
		dip204_printf_string("Sensor OK");
	}
	
	/* Enable Accelerometer mode */
	uint8_t accelSettings = 0b11011000;
	I2C_writeRegister(LSM9DS1_ACC_ADDRESS, CTRL_REG6_XL, accelSettings);
	
	while(1) {
		analizar();
		vTaskDelay(mainLCDTEST_PERIOD);
	}
	
}

