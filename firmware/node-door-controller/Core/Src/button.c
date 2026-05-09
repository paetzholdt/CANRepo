#include "button.h"

#include <stdbool.h>


#define DEBOUNCE_TIME 20U // 20ms unsigned


void button_update(Button_t *button) {
	bool is_button_pressed = (HAL_GPIO_ReadPin(button->port, button->gpio_pin) == GPIO_PIN_RESET); // true, if button is pressed

	switch (button->button_state) {
		case RELEASED_STABLE:
			if (is_button_pressed) {
				button->start_time_action = HAL_GetTick(); // get current time
				button->button_state = PRESSED_RAW;
			}
			break;

		case PRESSED_RAW:
			if (!is_button_pressed) {
				button->button_state = RELEASED_STABLE;
				break;
			}

			if ((HAL_GetTick() - button->start_time_action) >= DEBOUNCE_TIME) {
				button->button_state = PRESSED_STABLE;
				// TODO: hier Signal ausgeben
			}
			break;

		case PRESSED_STABLE:
			if (!is_button_pressed) {
				button->start_time_action = HAL_GetTick();
				button->button_state = RELEASED_RAW;
			}
			break;

		case RELEASED_RAW:
			if (is_button_pressed) {
				button->button_state = PRESSED_STABLE;
				break;
			}

			if ((HAL_GetTick() - button->start_time_action) >= DEBOUNCE_TIME) {
				button->button_state = RELEASED_STABLE;
			}
			break;
	}
}
