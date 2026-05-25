#include "inputs/input_fallback_door_release.h"

#include "hardware/button.h"

// necessary for label of button
#include "main.h"


static Button_t fallback_door_release_button = {
		.port = FALLBACK_DOOR_RELEASE_BUTTON_GPIO_Port,
		.gpio_pin = FALLBACK_DOOR_RELEASE_BUTTON_Pin,
		.button_state = BUTTON_STATE_RELEASED_STABLE,
		.start_time_action = 0,
		.button_event = BUTTON_EVENT_NONE
};


ButtonEvent_t get_fallback_door_release_button_event(void) {
	return get_button_event(&fallback_door_release_button);
};

void input_fallback_door_release_task(void) {
	update_button(&fallback_door_release_button);
}
