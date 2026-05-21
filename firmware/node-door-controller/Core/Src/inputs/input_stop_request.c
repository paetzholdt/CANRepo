/**
 * @file input_stop_request.c
 *
 * @brief Input abstraction module for the stop request button.
 *
 * This module encapsulates the physical stop request input device and provides debounced button events to the application layer.
 *
 * Responsibilities:
 * - cyclic update of the stop request button debounce state machine
 * - provision of debounced button press events
 *
 * This module does not implement application or safety logic.
 */

#include "hardware/button.h"
#include "inputs/input_stop_request.h"


/**
 * @brief Internal stop request button instance.
 */
static Button_t stop_request_button = {
		.port = GPIOB,
		.gpio_pin = GPIO_PIN_10,
		.button_state = BUTTON_STATE_RELEASED_STABLE,
		.start_time_action = 0,
		.button_event = BUTTON_EVENT_NONE
};



/**
 * @brief Returns and consumes the current stop request button event.
 *
 * @return Current button event
 */
ButtonEvent_t get_stop_request_button_event(void) {
	return get_button_event(&stop_request_button);
}


/**
 * @brief Cyclic task for the stop request input module.
 *
 * Updates the internal debounce state machine of the stop request button.
 *
 * This function shall be called cyclically by the system scheduler.
 */
void input_stop_request_task(void) {
	update_button(&stop_request_button);
}
