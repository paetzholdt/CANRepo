#ifndef BUTTON_H
#define BUTTON_H


#include "main.h"
#include <stdint.h>


typedef enum {
	RELEASED_STABLE,
	PRESSED_RAW,
	PRESSED_STABLE,
	RELEASED_RAW
} ButtonState_t;


typedef struct {
	// found in stm32g0xx_hal_gpio.c
	GPIO_TypeDef *port;
	uint16_t gpio_pin;

	ButtonState_t button_state;

	uint32_t start_time_action;
} Button_t;

void button_update(Button_t *button);

#endif
