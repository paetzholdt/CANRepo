#include "application/door_release.h"

#include "hardware/inputs.h"
#include "hardware/leds.h"

#include <stdbool.h>



static DoorReleaseState_t door_release_state = DOOR_RELEASE_INACTIVE;


bool is_door_release_active(void) {
	return door_release_state == DOOR_RELEASE_ACTIVE;
}

void door_release_task(void) {
	switch (door_release_state) {
		case DOOR_RELEASE_INACTIVE:
			set_door_release_led(false);
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				door_release_state = DOOR_RELEASE_ACTIVE;
			}
			break;

		case DOOR_RELEASE_ACTIVE:
			set_door_release_led(true);
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				door_release_state = DOOR_RELEASE_INACTIVE;
			}
			break;
	}
}
