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

	StateDoorRelease_t state_door_release = get_system_state_door_release();

	StateVehicleMovement_t state_vehicle_movement = get_system_state_vehicle_movement();
	StateVehicleMovementInfo_t state_vehicle_movement_info = get_system_state_vehicle_movement_info();

	switch(state_door_release) {
		case STATE_DOOR_RELEASE_ACTIVE:
			cmd_door_release_deactivate();
			break;
		case STATE_DOOR_RELEASE_INACTIVE:
			// TODO: add station_detection
			if (state_vehicle_movement == STATE_VEHICLE_MOVEMENT_STOPPED
				&& state_vehicle_movement_info == STATE_VEHICLE_MOVEMENT_INFO_VALID) {
				cmd_door_release_activate();

			} else {
				// TODO: Can request be rejected explicitly?
				// TODO: emit warning to driver
			}
			break;
	}
}


