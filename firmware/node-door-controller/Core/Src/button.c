#include "button.h"

#include "stm32g0xx_hal_gpio.h"
#include "stm32g0xx_hal.h"

#include <stdbool.h>


#define DEBOUNCE_TIME 20U // 20ms unsigned


void update_button(Button_t *button) {
	bool is_button_pressed = (HAL_GPIO_ReadPin(button->port, button->gpio_pin) == GPIO_PIN_RESET); // true, if button is pressed

	switch (button->button_state) {
		case BUTTON_STATE_RELEASED_STABLE:
			if (is_button_pressed) {
				button->start_time_action = HAL_GetTick(); // get current time
				button->button_state = BUTTON_STATE_PRESSED_RAW;
			}
			break;

		case BUTTON_STATE_PRESSED_RAW:
			if (!is_button_pressed) {
				button->button_state = BUTTON_STATE_RELEASED_STABLE;
				break;
			}

			if ((HAL_GetTick() - button->start_time_action) >= DEBOUNCE_TIME) {
				button->button_state = BUTTON_STATE_PRESSED_STABLE;

				// Signal ausgeben
				// TODO: what, if Event is triggered again, before BUTTON_EVENT_PRESSED was consumed
				// --> old button_event would be overwritten
				button->button_event = BUTTON_EVENT_PRESSED;
			}
			break;

		case BUTTON_STATE_PRESSED_STABLE:
			if (!is_button_pressed) {
				button->start_time_action = HAL_GetTick();
				button->button_state = BUTTON_STATE_RELEASED_RAW;
			}
			break;

		case BUTTON_STATE_RELEASED_RAW:
			if (is_button_pressed) {
				button->button_state = BUTTON_STATE_PRESSED_STABLE;
				break;
			}

			if ((HAL_GetTick() - button->start_time_action) >= DEBOUNCE_TIME) {
				button->button_state = BUTTON_STATE_RELEASED_STABLE;
			}
			break;
	}
}

ButtonEvent_t get_button_event(Button_t *button) {
	if (button->button_event == BUTTON_EVENT_PRESSED) {
		button->button_event = BUTTON_EVENT_NONE;
		return BUTTON_EVENT_PRESSED;
	}
	return BUTTON_EVENT_NONE;
}
