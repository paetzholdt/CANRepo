#include "hardware/potentiometer.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"

extern ADC_HandleTypeDef hadc1;

static uint32_t potentiometer_value;
static uint32_t last_attempted_sample_tick; // last system time when reading was attempted
static uint32_t last_valid_sample_tick; // last system time when reading was successful
static bool is_available_last_attempted_sample_tick;
static bool is_available_last_valid_sample_tick;

static PotentiometerStatus_t potentiometer_status = POTENTIOMETER_STATUS_NOT_AVAILABLE;


PotentiometerStatus_t get_potentiometer_value(uint32_t *value) {
	if (value == NULL) {
		return POTENTIOMETER_STATUS_INVALID_ARGUMENT;
	}

	if (potentiometer_status == POTENTIOMETER_STATUS_OK) {
		*value = potentiometer_value;
	}
	return potentiometer_status;
}

// shall only be called if potentiometer value was tried to be read
PotentiometerStatus_t get_last_attempted_sample_tick(uint32_t *last_attempted_sample_tick_out) {
	if (last_attempted_sample_tick_out == NULL) {
		return POTENTIOMETER_STATUS_INVALID_ARGUMENT;
	}

	if (!is_available_last_attempted_sample_tick) {
		// potentiometer_task() was never called
		return POTENTIOMETER_STATUS_NOT_AVAILABLE;
	}
	*last_attempted_sample_tick_out = last_attempted_sample_tick;
	return POTENTIOMETER_STATUS_OK;
}

PotentiometerStatus_t get_last_valid_sample_tick(uint32_t *last_valid_sample_tick_out) {
	if (last_valid_sample_tick_out == NULL) {
		return POTENTIOMETER_STATUS_INVALID_ARGUMENT;
	}

	if (!is_available_last_valid_sample_tick) {
		// potentiometer_task() was never called successfully
		return POTENTIOMETER_STATUS_NOT_AVAILABLE;
	}
	*last_valid_sample_tick_out = last_valid_sample_tick;
	return POTENTIOMETER_STATUS_OK;
}


PotentiometerStatus_t potentiometer_init(void) {
	HAL_StatusTypeDef adc_status;
	adc_status = HAL_ADCEx_Calibration_Start(&hadc1);
	if (adc_status != HAL_OK) {
		printf("Error during adc-calibration in potentiometer-initialization");
		return POTENTIOMETER_STATUS_ERROR;
	}

	return POTENTIOMETER_STATUS_OK;
}

static PotentiometerStatus_t read_potentiometer(void) {
	HAL_StatusTypeDef adc_status; // are adc readings currently possible?

	last_attempted_sample_tick = HAL_GetTick();
	is_available_last_attempted_sample_tick = true; // written every time read_potentiometer is called - TODO: check if this is professional

	adc_status = HAL_ADC_Start(&hadc1);
	if (adc_status != HAL_OK) { // simplified check whether adc_status is working
		return POTENTIOMETER_STATUS_ERROR;
	}

	adc_status = HAL_ADC_PollForConversion(&hadc1, 5); // TODO: 5 is a magic value, replace with a standardized, reasoned value
	if (adc_status != HAL_OK) {
		HAL_ADC_Stop(&hadc1); // adc reading needs to be stopped prematurely
		return POTENTIOMETER_STATUS_ERROR;
	}

	potentiometer_value = HAL_ADC_GetValue(&hadc1);
	printf("ADC-Wert ist: %lu\r\n", potentiometer_value); // only for learning purposes


	adc_status = HAL_ADC_Stop(&hadc1);
	if (adc_status != HAL_OK) {
		return POTENTIOMETER_STATUS_ERROR;
	}
	last_valid_sample_tick = HAL_GetTick();
	is_available_last_valid_sample_tick = true; // currently written every time - TODO: check if this is professional

	return POTENTIOMETER_STATUS_OK;
}


PotentiometerStatus_t potentiometer_task(void) {
	potentiometer_status = read_potentiometer();

	if (potentiometer_status != POTENTIOMETER_STATUS_OK) {
		printf("Error during potentiometer task\r\n");
	}
	return potentiometer_status;
}

