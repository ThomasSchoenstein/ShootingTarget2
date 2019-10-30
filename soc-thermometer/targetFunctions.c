/*
 * targetFunctions.c
 *
 *  Created on: Oct 10, 2019
 *      Author: jdoe8
 */

#include "headers.h"
#include "em_adc.h"


void initADC(void){
	CMU_ClockEnable(cmuClock_ADC0, true);  //enable ADC clock
	CMU_ClockEnable(cmuClock_PRS, true);   //enable PRS clock
	ADC_IntEnable(ADC0, ADC_IEN_SINGLE); //enable ADC interrupts

	ADC_Init_TypeDef adcConfig=ADC_INIT_DEFAULT;                         //initialization variables for ADC
		adcConfig.em2ClockConfig=adcEm2ClockAlwaysOn;
		adcConfig.ovsRateSel=adcOvsRateSel2;
		adcConfig.prescale=ADC_PrescaleCalc(16000000,40000000);
		adcConfig.tailgate=true;
		adcConfig.timebase=ADC_TimebaseCalc(0);
		adcConfig.warmUpMode=adcWarmupKeepADCWarm;

	ADC_Init(ADC0,&adcConfig);  //function to init ADC

	//Clears FIFO and pending interrupt
	ADC0->SINGLEFIFOCLEAR = ADC_SINGLEFIFOCLEAR_SINGLEFIFOCLEAR;
	NVIC_ClearPendingIRQ(ADC0_IRQn);
	NVIC_EnableIRQ(ADC0_IRQn);


	//ADC_LoadDevinfoCal(ADC0, adcRefVDD, true);   //Function calebrates ADC
	/*ADC_InitScanInput_TypeDef adcScanInputConfig;

	ADC_InitScan_TypeDef adcScanConfig=ADC_INITSCAN_DEFAULT;  //ADC Scan configuration
		adcScanConfig.acqTime=adcAcqTime1;
		adcScanConfig.diff=false;
		adcScanConfig.fifoOverwrite=false;
		adcScanConfig.leftAdjust=false;
		adcScanConfig.prsEnable=false;
		adcScanConfig.prsSel=adcPRSSELCh0;
		adcScanConfig.reference=adcRefVDD;
		adcScanConfig.rep=true;
		adcScanConfig.resolution=adcRes8Bit;
		adcScanConfig.scanDmaEm2Wu=true;
		adcScanConfig.scanInputConfig=adcScanInputConfig;

		//ADC pins for scanning CHANGE TO ACTUAL PINS LATER
	ADC_ScanSingleEndedInputAdd(&adcScanConfig, adcScanInputGroup0, adcPosSelAPORT1XCH6);   //typedef, ,pin (Page 72 BGM111 dat sheet
	ADC_ScanSingleEndedInputAdd(&adcScanConfig, adcScanInputGroup1, adcPosSelAPORT1XCH8);   //pin PC8
	ADC_ScanSingleEndedInputAdd(&adcScanConfig, adcScanInputGroup1, adcPosSelAPORT1XCH10);   //pin PC10
	ADC_ScanSingleEndedInputAdd(&adcScanConfig, adcScanInputGroup2, adcPosSelAPORT1XCH16);    // PF0
	ADC_ScanSingleEndedInputAdd(&adcScanConfig, adcScanInputGroup2, adcPosSelAPORT1XCH18);    //PF2

	ADC_InitScan(ADC0,adcScanConfig);*/

	//PINS ARE FOUND ON PAGE 72 OF BGM111 DATA SHEET
	ADC_InitSingle_TypeDef adcSingleConfig1=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin PC6
		adcSingleConfig1.posSel=adcPosSelAPORT1XCH6;       //Positive is Pin PC6

		adcSingleConfig1.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfig1.diff=false;            //single ended input
		adcSingleConfig1.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfig1.leftAdjust=false;      //right adjusted
		adcSingleConfig1.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfig1.prsEnable=false;       //prs is disabled
		adcSingleConfig1.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfig1.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfig1.rep=false;              //will not repeat
		adcSingleConfig1.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfig1.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfig2=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin C8
		adcSingleConfig2.posSel=adcPosSelAPORT1XCH8;       //Positive is Pin C8

		adcSingleConfig2.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfig2.diff=false;            //single ended input
		adcSingleConfig2.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfig2.leftAdjust=false;      //right adjusted
		adcSingleConfig2.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfig2.prsEnable=false;       //prs is disabled
		adcSingleConfig2.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfig2.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfig2.rep=false;              //will not repeat
		adcSingleConfig2.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfig2.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfig3=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin C10
		adcSingleConfig3.posSel=adcPosSelAPORT1XCH10;       //Positive is Pin C10

		adcSingleConfig3.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfig3.diff=false;            //single ended input
		adcSingleConfig3.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfig3.leftAdjust=false;      //right adjusted
		adcSingleConfig3.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfig3.prsEnable=false;       //prs is disabled
		adcSingleConfig3.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfig3.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfig3.rep=false;              //will not repeat
		adcSingleConfig3.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfig3.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle(ADC0_BASE, &adcSingleConfig1);  //conversion init for pin C6
	ADC_InitSingle(ADC0_BASE, &adcSingleConfig2);  //conversion init for pin C8
	ADC_InitSingle(ADC0_BASE, &adcSingleConfig3);  //conversion init for C10


}


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
