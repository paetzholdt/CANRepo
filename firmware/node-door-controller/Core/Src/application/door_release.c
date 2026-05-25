#include "application/door_release.h"

#include "system/state_door_system_internal.h"
#include "inputs/input_door_release.h"
#include "hardware/leds.h"


static StateDoorRelease_t state_door_release;


void door_release_init(void) {
	state_door_release = STATE_DOOR_RELEASE_INACTIVE;
	set_system_state_door_release(state_door_release);
	set_door_release_led(false);
}

// TODO: remove LED-management from FSM?
void door_release_task(void) {
	switch (state_door_release) {
		case STATE_DOOR_RELEASE_INACTIVE:
			set_door_release_led(false);
			break;

		case STATE_DOOR_RELEASE_ACTIVE:
			set_door_release_led(true);
			break;
	}
}


void cmd_door_release_activate(void) {
	state_door_release = STATE_DOOR_RELEASE_ACTIVE;
	set_system_state_door_release(state_door_release);
}

void cmd_door_release_deactivate(void) {
	state_door_release = STATE_DOOR_RELEASE_INACTIVE;
	set_system_state_door_release(state_door_release);
}
