/*
 * targetFunctions.c
 *
 *  Created on: Oct 10, 2019
 *      Author: jdoe8
 */

#include "em_system.h"
#include "em_adc.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "hal-config.h"
#include "infrastructure.h"
#include "si7013.h"
#include "native_gecko.h"
#include "gatt_db.h"



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

	//PINS ARE FOUND ON PAGE 72 OF BGM111 DATA SHEET
	ADC_InitSingle_TypeDef adcSingleConfigPC6=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin PC6
		adcSingleConfigPC6.posSel=adcPosSelAPORT1XCH6;       //Positive is Pin PC6

		adcSingleConfigPC6.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfigPC6.diff=false;            //single ended input
		adcSingleConfigPC6.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfigPC6.leftAdjust=false;      //right adjusted
		adcSingleConfigPC6.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfigPC6.prsEnable=false;       //prs is disabled
		adcSingleConfigPC6.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfigPC6.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfigPC6.rep=false;              //will not repeat
		adcSingleConfigPC6.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfigPC6.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfigPC7=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin PC7
		adcSingleConfigPC7.posSel=adcPosSelAPORT1YCH7;       //Positive is Pin PC7

		adcSingleConfigPC7.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfigPC7.diff=false;            //single ended input
		adcSingleConfigPC7.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfigPC7.leftAdjust=false;      //right adjusted
		adcSingleConfigPC7.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfigPC7.prsEnable=false;       //prs is disabled
		adcSingleConfigPC7.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfigPC7.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfigPC7.rep=false;              //will not repeat
		adcSingleConfigPC7.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfigPC7.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfigPC8=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin C8
		adcSingleConfigPC8.posSel=adcPosSelAPORT1XCH8;       //Positive is Pin C8

		adcSingleConfigPC8.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfigPC8.diff=false;            //single ended input
		adcSingleConfigPC8.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfigPC8.leftAdjust=false;      //right adjusted
		adcSingleConfigPC8.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfigPC8.prsEnable=false;       //prs is disabled
		adcSingleConfigPC8.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfigPC8.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfigPC8.rep=false;              //will not repeat
		adcSingleConfigPC8.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfigPC8.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfigPC9=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin C9
		adcSingleConfigPC9.posSel=adcPosSelAPORT1YCH9;       //Positive is Pin C9

		adcSingleConfigPC9.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfigPC9.diff=false;            //single ended input
		adcSingleConfigPC9.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfigPC9.leftAdjust=false;      //right adjusted
		adcSingleConfigPC9.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfigPC9.prsEnable=false;       //prs is disabled
		adcSingleConfigPC9.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfigPC9.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfigPC9.rep=false;              //will not repeat
		adcSingleConfigPC9.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfigPC9.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfigPC10=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin C10
		adcSingleConfigPC10.posSel=adcPosSelAPORT1XCH10;       //Positive is Pin C10

		adcSingleConfigPC10.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfigPC10.diff=false;            //single ended input
		adcSingleConfigPC10.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfigPC10.leftAdjust=false;      //right adjusted
		adcSingleConfigPC10.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfigPC10.prsEnable=false;       //prs is disabled
		adcSingleConfigPC10.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfigPC10.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfigPC10.rep=false;              //will not repeat
		adcSingleConfigPC10.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfigPC10.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle_TypeDef adcSingleConfigPC11=ADC_INITSINGLE_DEFAULT;  //initializaion variables for single conversion on Pin C11
		adcSingleConfigPC11.posSel=adcPosSelAPORT1YCH11;       //Positive is Pin C11

		adcSingleConfigPC11.acqTime=adcAcqTime1;   //aquire after 1 clock cycle
		adcSingleConfigPC11.diff=false;            //single ended input
		adcSingleConfigPC11.fifoOverwrite=false;   //excess data is thrown out
		adcSingleConfigPC11.leftAdjust=false;      //right adjusted
		adcSingleConfigPC11.negSel=adcNegSelVSS;   //Negative select is Vss
		adcSingleConfigPC11.prsEnable=false;       //prs is disabled
		adcSingleConfigPC11.prsSel=adcPRSSELCh0;  //prs channel 0
		adcSingleConfigPC11.reference=adcRefVDD;   //referance is VDD should be ~3V
		adcSingleConfigPC11.rep=false;              //will not repeat
		adcSingleConfigPC11.resolution=adcRes8Bit;  //8 bit resolution
		adcSingleConfigPC11.singleDmaEm2Wu=true;    //DMA is enabled when in EM2

	ADC_InitSingle(ADC0, &adcSingleConfigPC6);  //conversion init for pin C6
	ADC_InitSingle(ADC0, &adcSingleConfigPC7);  //conversion init for pin C7
	ADC_InitSingle(ADC0, &adcSingleConfigPC8);  //conversion init for C8
	ADC_InitSingle(ADC0, &adcSingleConfigPC9);  //conversion init for C9
	ADC_InitSingle(ADC0, &adcSingleConfigPC10);  //conversion init for C10
	ADC_InitSingle(ADC0, &adcSingleConfigPC11);  //conversion init for C11
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
