/*
 * targetFunctions.c
 *
 *  Created on: Oct 10, 2019
 *      Author: jdoe8
 */

#include "headers.h"

void sensorRead(void){
	uint8_t adcTempBuffer[5]; /* Stores the ADC data in the ___________ format. */
	uint8_t flags = 0x00;   /* MUST CHANGE FLAGS aggragate? pressure? */
	int32_t ADCdat;     /* Stores the data read from the ADC. */
	uint32_t rhData = 0;    /* Dummy needed for storing Relative Humidity data. */
	uint32_t impact;   /* Stores the impact data read from the sensor in the correct format */
	uint8_t *p = adcTempBuffer; /* Pointer to HTM temperature buffer needed for converting values to bitstream. */
	static int32_t DummyValue = 0l;

	/* Convert flags to bitstream and append them in the HTM temperature data buffer (htmTempBuffer) */
	UINT8_TO_BITSTREAM(p, flags);

	/* Sensor relative humidity and temperature measurement returns 0 on success, nonzero otherwise */
	if (Si7013_MeasureRHAndTemp(I2C0, SI7021_ADDR, &rhData, &ADCdat) != 0) {
		ADCdat = DummyValue + 20000l;
	  DummyValue = (DummyValue + 1000l) % 21000l;
	}
	/* Convert sensor data to correct temperature format */
	impact = FLT_TO_UINT32(ADCdat, -3);
	/* Convert temperature to bitstream and place it in the HTM temperature data buffer (htmTempBuffer) */
	UINT32_TO_BITSTREAM(p, impact);

	/* Send indication of the temperature in htmTempBuffer to all "listening" clients.
	 * This enables the Health Thermometer in the Blue Gecko app to display the temperature.
	 *  0xFF as connection ID will send indications to all connections. */
	gecko_cmd_gatt_server_send_characteristic_notification(
	  0xFF, gattdb_temperature_measurement, 5, adcTempBuffer);
}
