#include "inputs/input_traction_controller.h"

#include "hardware/potentiometer.h"
#include "main.h" // HAL_GetTick();

#include <stdint.h>
#include <stddef.h>


#define EMERGENCY_BRAKE_PERCENTAGE -101
#define IDLE_PERCENTAGE 0

#define TIMEOUT_MAX_MS 200

#define POTENTIOMETER_MAX_VALUE 4095U


#define IDLE_CENTER_VALUE (POTENTIOMETER_MAX_VALUE / 2U)
#define IDLE_DEADBAND_PERCENTAGE 10U

#define IDLE_DEADBAND_VALUE ((POTENTIOMETER_MAX_VALUE * IDLE_DEADBAND_PERCENTAGE) / 100)

#define IDLE_MIN_VALUE (IDLE_CENTER_VALUE - IDLE_DEADBAND_VALUE)
#define IDLE_MAX_VALUE (IDLE_CENTER_VALUE + IDLE_DEADBAND_VALUE)


#define EMERGENCY_BRAKE_MAX_PERCENTAGE 10U
#define EMERGENCY_BRAKE_MAX_VALUE ((POTENTIOMETER_MAX_VALUE * EMERGENCY_BRAKE_MAX_PERCENTAGE) / 100)

#define BRAKE_MIN_PERCENTAGE 15U
#define BRAKE_MIN_VALUE ((POTENTIOMETER_MAX_VALUE * BRAKE_MIN_PERCENTAGE) / 100)
#define BRAKE_AREA (IDLE_MIN_VALUE - BRAKE_MIN_VALUE)


#define TRACTION_AREA (POTENTIOMETER_MAX_VALUE - IDLE_MAX_VALUE)



InputTractionControllerStatus_t get_traction_controller_percentage(int8_t *percentage) {
	if (percentage == NULL) {
		return INPUT_TRACTION_CONTROLLER_STATUS_INVALID_ARGUMENT;
	}

	uint32_t potentiometer_value = 0;

	PotentiometerStatus_t potentiometer_status = get_potentiometer_value(&potentiometer_value);
	if (potentiometer_status != POTENTIOMETER_STATUS_OK) {
		return INPUT_TRACTION_CONTROLLER_STATUS_UNKNOWN;
	}

	if (potentiometer_value > POTENTIOMETER_MAX_VALUE) {
		return INPUT_TRACTION_CONTROLLER_STATUS_INVALID_INPUT;
	}


	// check for timeout
	uint32_t last_valid_potentiometer_read = 0;

	PotentiometerStatus_t last_valid_sample_tick_status = get_last_valid_sample_tick(&last_valid_potentiometer_read);
	if (last_valid_sample_tick_status != POTENTIOMETER_STATUS_OK) {
		return INPUT_TRACTION_CONTROLLER_STATUS_UNKNOWN;
	}

	uint32_t now = HAL_GetTick();
	if ((now - last_valid_potentiometer_read) > TIMEOUT_MAX_MS) {
		return INPUT_TRACTION_CONTROLLER_STATUS_TIME_OUT;
	}


	// map potentiometer value to traction controller percentage
	if (potentiometer_value <= EMERGENCY_BRAKE_MAX_VALUE) {
		// emergency braking
		*percentage = EMERGENCY_BRAKE_PERCENTAGE;

	} else if (potentiometer_value > EMERGENCY_BRAKE_MAX_VALUE && potentiometer_value < IDLE_MIN_VALUE) {
		// braking
		if (potentiometer_value <= BRAKE_MIN_VALUE) {
			*percentage = -100;
		} else {
			uint8_t value_in_range = (((IDLE_MIN_VALUE - potentiometer_value) * 99) / BRAKE_AREA) + 1; // values from 1 to 100
			*percentage = -value_in_range; // negate values
		}

	} else if (potentiometer_value >= IDLE_MIN_VALUE && potentiometer_value <= IDLE_MAX_VALUE) {
		// idle
		*percentage = IDLE_PERCENTAGE;

	} else if (potentiometer_value > IDLE_MAX_VALUE && potentiometer_value <= POTENTIOMETER_MAX_VALUE) {
		// traction
		*percentage = (((potentiometer_value - IDLE_MAX_VALUE) * 99) / TRACTION_AREA) + 1;

	} else {
		// fail safe
		*percentage = EMERGENCY_BRAKE_PERCENTAGE;
		return INPUT_TRACTION_CONTROLLER_STATUS_UNKNOWN;
	}

	return INPUT_TRACTION_CONTROLLER_STATUS_OK;
}
