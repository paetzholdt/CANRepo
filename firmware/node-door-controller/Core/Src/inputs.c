#include "inputs.h"

#include "button.h"


static Button_t door_release_button = {
		.port = GPIOC,
		.gpio_pin = GPIO_PIN_2,
		.button_state = BUTTON_STATE_RELEASED_STABLE,
		.start_time_action = 0,
		.button_event = BUTTON_EVENT_NONE
};


void update_inputs(void) {
	update_button(&door_release_button);
}

ButtonEvent_t get_door_release_button_event(void) {
	return get_button_event(&door_release_button);
}
