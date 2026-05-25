/**
 * @file  input_door_release.c
 *
 * @brief Input abstraction module for the door release button.
 *
 * This module encapsulates the physical door release button input.
 *
 * Responsibilities:
 * - cyclic update of the door release button debounce state machine
 * - provision of debounced button press events
 *
 * This module does not implement application or safety logic.
 */
#include "inputs/input_door_release.h"

#include "hardware/button.h"


/**
 * @brief Internal door release button instance.
 */
static Button_t door_release_button = {
		.port = GPIOC,
		.gpio_pin = GPIO_PIN_2,
		.button_state = BUTTON_STATE_RELEASED_STABLE,
		.start_time_action = 0,
		.button_event = BUTTON_EVENT_NONE
};


/**
 * @brief Returns and consumes the current door release button event.
 *
 * @return Current button event
 */
ButtonEvent_t get_door_release_button_event(void) {
	return get_button_event(&door_release_button);
}


/**
 * @brief Cyclic task for the door release input module.
 *
 * Updates the internal debounce state machine of the door release button.
 *
 * This function shall be called cyclically by the system scheduler.
 */
void input_door_release_task(void) {
	update_button(&door_release_button);

}
