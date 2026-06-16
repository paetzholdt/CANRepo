#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <stdint.h>

typedef enum {
	POTENTIOMETER_STATUS_ERROR,
	POTENTIOMETER_STATUS_NOT_AVAILABLE,
	POTENTIOMETER_STATUS_INVALID_ARGUMENT,
	POTENTIOMETER_STATUS_OK
} PotentiometerStatus_t;


PotentiometerStatus_t get_potentiometer_value(uint32_t *value);
PotentiometerStatus_t get_last_attempted_sample_tick(uint32_t *last_attempted_sample_tick_out);
PotentiometerStatus_t get_last_valid_sample_tick(uint32_t *last_valid_sample_tick_out);

PotentiometerStatus_t potentiometer_init(void);
PotentiometerStatus_t potentiometer_task(void);

#endif
