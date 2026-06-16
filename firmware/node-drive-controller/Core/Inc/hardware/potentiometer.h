#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <stdint.h>

typedef enum {
	POTENTIOMETER_STATUS_OK,
	POTENTIOMETER_STATUS_ERROR
} PotentiometerStatus_t;

void potentiometer_init(void);

PotentiometerStatus_t get_potentiometer_value(uint32_t *value);

void potentiometer_task(void);

#endif
