#include "application/door_release.h"

#include "inputs/input_door_release.h"
#include "hardware/leds.h"

#include <stdbool.h>



static StateDoorRelease_t state_door_release;


void door_release_init(void) {
	state_door_release = DOOR_RELEASE_INACTIVE;
	set_door_release_led(false);
}

bool is_door_release_active(void) {
	return state_door_release == DOOR_RELEASE_ACTIVE;
}

void door_release_task(void) {
	switch (state_door_release) {
		case DOOR_RELEASE_INACTIVE:
			set_door_release_led(false);
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				state_door_release = DOOR_RELEASE_ACTIVE;
			}
			break;

		case DOOR_RELEASE_ACTIVE:
			set_door_release_led(true);
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				state_door_release = DOOR_RELEASE_INACTIVE;
			}
			break;
	}
}
