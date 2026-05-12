#ifndef LEDS_H
#define LEDS_H

#include "stm32g0xx_hal.h"


#include <stdbool.h>


typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;

	bool current_state;

} Led_t;


void set_door_release_led(bool shall_be_on);

void set_stop_request_led(bool shall_be_on);

void set_green_loop_led(bool shall_be_on);

#endif
