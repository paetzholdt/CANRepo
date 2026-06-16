#include "hardware/potentiometer.h"

#include <stdio.h>
#include <stdint.h>

#include "main.h"

extern ADC_HandleTypeDef hadc1;

static uint32_t adc_value;
static HAL_StatusTypeDef adc_status; // are adc readings currently possible?
static uint32_t last_attempted_sample_tick; // last system time when reading was attempted
static uint32_t last_valid_sample_tick; // last system time when reading was successful

static PotentiometerStatus_t potentiometer_status;


static PotentiometerStatus_t read_potentiometer(void) {
	last_attempted_sample_tick = HAL_GetTick();

	adc_status = HAL_ADC_Start(&hadc1);
	if (adc_status != HAL_OK) { // simplified check whether adc_status is working
		return POTENTIOMETER_STATUS_ERROR;
	}

	adc_status = HAL_ADC_PollForConversion(&hadc1, 5); // TODO: 5 is a magic value, replace with a standardized, reasoned value
	if (adc_status != HAL_OK) {
		HAL_ADC_Stop(&hadc1); // adc reading needs to be stopped prematurely
		return POTENTIOMETER_STATUS_ERROR;
	}

	adc_value = HAL_ADC_GetValue(&hadc1);
	printf("ADC-Wert ist: %lu\r\n", adc_value); // only for learning purposes


	adc_status = HAL_ADC_Stop(&hadc1);
	if (adc_status != HAL_OK) {
		return POTENTIOMETER_STATUS_ERROR;
	}
	last_valid_sample_tick = HAL_GetTick();

	return POTENTIOMETER_STATUS_OK;
}


PotentiometerStatus_t potentiometer_init(void) {
	adc_status = HAL_ADCEx_Calibration_Start(&hadc1);
	if (adc_status != HAL_OK) {
		printf("Error during adc-calibration in potentiometer-initialization");
		return POTENTIOMETER_STATUS_ERROR;
	}

	return POTENTIOMETER_STATUS_OK;
}

PotentiometerStatus_t get_potentiometer_value(uint32_t *value) {
	if (potentiometer_status == POTENTIOMETER_STATUS_OK) {
		*value = adc_value;
	}
	return potentiometer_status;
}

PotentiometerStatus_t potentiometer_task(void) {
	potentiometer_status = read_potentiometer();

	if (potentiometer_status != POTENTIOMETER_STATUS_OK) {
		printf("Error during potentiometer task\r\n");
	}
	return POTENTIOMETER_STATUS_OK;
}

