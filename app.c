/*
 * app.c
 *
 * Created: 11/05/2018 11:37:59
 *  Author: Eric
 */ 

#include "app.h"
#include "common.h"
#include "display.h"


void analizar()
{
	uint8_t dataRead, dataH, dataL;
	int16_t ejeX, ejeY, ejeZ;
	static int16_t maxX, maxY, maxZ;
	int16_t tempX, tempY, minZ;
	
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, ACCEL_SENSOR_X_h, &dataH );
	delay_ms(200);
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, ACCEL_SENSOR_X_l, &dataL );
	ejeX = dataH << 8 | dataL;
	tempX = abs(ejeX);
	tempY= abs(maxX);
	if (tempY < tempX)
	{
		maxX = ejeX;
	}
	
	
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, ACCEL_SENSOR_Y_h, &dataH );
	delay_ms(200);
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, ACCEL_SENSOR_Y_l, &dataL );
	ejeY = dataH << 8 | dataL;
	tempX = abs(ejeY);
	tempY= abs(maxY);
	if (tempY < tempX)
	{
		maxY = ejeY;
	}
	
	
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, ACCEL_SENSOR_Z_h, &dataH );
	delay_ms(200);
	I2C_readRegister(LSM9DS1_ACC_ADDRESS, ACCEL_SENSOR_Z_l, &dataL );
	ejeZ = dataH << 8 | dataL;
	tempX = abs(ejeZ);
	tempY= abs(maxZ);
	if (tempY < tempX)
	{
		maxZ = ejeZ;
	}
	
	printarDades(ejeX, ejeY, ejeZ, maxX, maxY, maxZ);
}