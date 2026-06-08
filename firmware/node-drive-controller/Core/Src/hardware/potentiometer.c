#include "hardware/potentiometer.h"

#include <stdio.h>
#include <stdint.h>

#include "main.h"

extern ADC_HandleTypeDef hadc1;

static HAL_StatusTypeDef adc_status;
static uint32_t adc_value;

static PotentiometerStatus_t potentiometer_status;

static PotentiometerStatus_t read_potentiometer(void) {
	// instructions for ADC found in Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_adc.c at line 137 ff.
	// TODO: implement check for errors
	adc_status = HAL_ADC_Start(&hadc1);

	adc_status = HAL_ADC_PollForConversion(&hadc1, 5);
	if (adc_status != HAL_OK) {
		printf("Error during adc-poll\r\n");
		HAL_ADC_Stop(&hadc1);
		return POTENTIOMETER_STATUS_ERROR;

	} else {
		adc_value = HAL_ADC_GetValue(&hadc1);
		printf("ADC-Wert ist: %lu\r\n", adc_value);
	}

	HAL_ADC_Stop(&hadc1);

	return POTENTIOMETER_STATUS_OK;
}


void potentiometer_init(void) {
	adc_status = HAL_ADCEx_Calibration_Start(&hadc1);
	if (adc_status != HAL_OK) {
		printf("Error during adc-calibration in potentiometer-initialization");
	}

	potentiometer_status = read_potentiometer();
	if (potentiometer_status == POTENTIOMETER_STATUS_ERROR) {
		printf("Error during initialization of potentiometer\r\n");
	}
}

PotentiometerStatus_t get_adc_value(uint32_t *value) {
	if (potentiometer_status == POTENTIOMETER_STATUS_OK) {
		*value = adc_value;
	}
	return potentiometer_status;
}

void potentiometer_task(void) {
	potentiometer_status = read_potentiometer();

	if (potentiometer_status == POTENTIOMETER_STATUS_ERROR) {
		printf("Error during reading of potentiometer\r\n");
	}
}

