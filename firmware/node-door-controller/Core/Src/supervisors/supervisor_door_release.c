#include "supervisors/supervisor_door_release.h"

#include "system/state_door_system.h"

#include "application/door_release.h"
#include "inputs/input_door_release.h"

void supervisor_door_release_task(void) {
	// return, if door release button was not pressed
	ButtonEvent_t button_event = get_door_release_button_event();
	if (button_event != BUTTON_EVENT_PRESSED) {
		return;
	}


	switch(get_system_state_door_release()) {
		case STATE_DOOR_RELEASE_ACTIVE:
			cmd_door_release_deactivate();
			break;
		case STATE_DOOR_RELEASE_INACTIVE:
			// TODO: add vehicle_movement and station_detection
			cmd_door_release_activate();
			break;
	}
}


