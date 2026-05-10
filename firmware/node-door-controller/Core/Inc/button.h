#ifndef BUTTON_H
#define BUTTON_H


#include "stm32g0xx_hal.h"

#include <stdint.h>


typedef enum {
	BUTTON_STATE_RELEASED_STABLE,
	BUTTON_STATE_PRESSED_RAW,
	BUTTON_STATE_PRESSED_STABLE,
	BUTTON_STATE_RELEASED_RAW
} ButtonState_t;

typedef enum {
	BUTTON_EVENT_NONE,
	BUTTON_EVENT_PRESSED

} ButtonEvent_t;


typedef struct {
	// found in stm32g0xx_hal_gpio.c
	GPIO_TypeDef *port;
	uint16_t gpio_pin;

	ButtonState_t button_state;

	uint32_t start_time_action;

	ButtonEvent_t button_event;
} Button_t;



void update_button(Button_t *button);

ButtonEvent_t get_button_event(Button_t *button);


#endif
