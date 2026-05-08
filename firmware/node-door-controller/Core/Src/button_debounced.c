#include "main.h"

#include <stdbool.h>

#define DEBOUNCE_TIME 20U // 20ms unsigned


typedef enum {
	RELEASED_STABLE,
	PRESSED_RAW,
	PRESSED_STABLE,
	RELEASED_RAW
} ButtonState_t;


static bool is_button_pressed = false;
static ButtonState_t button_state = RELEASED_STABLE;
static uint32_t start_time_button_action = 0;


void ButtonDebounce_Task(void) {
	is_button_pressed = (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) == GPIO_PIN_RESET); // true, if button is pressed

	switch (button_state) {
		case RELEASED_STABLE:
			if (is_button_pressed) {
				start_time_button_action = HAL_GetTick(); // get current time
				button_state = PRESSED_RAW;
			}
			break;

		case PRESSED_RAW:
			if (!is_button_pressed) {
				button_state = RELEASED_STABLE;
				break;
			}

			if ((HAL_GetTick() - start_time_button_action) >= DEBOUNCE_TIME) {
				button_state = PRESSED_STABLE;
				// TODO: hier Signal ausgeben
			}
			break;

		case PRESSED_STABLE:
			if (!is_button_pressed) {
				start_time_button_action = HAL_GetTick();
				button_state = RELEASED_RAW;
			}
			break;

		case RELEASED_RAW:
			if (is_button_pressed) {
				button_state = PRESSED_STABLE;
				break;
			}

			if ((HAL_GetTick() - start_time_button_action) >= DEBOUNCE_TIME) {
				button_state = RELEASED_STABLE;
			}
			break;
	}
}
