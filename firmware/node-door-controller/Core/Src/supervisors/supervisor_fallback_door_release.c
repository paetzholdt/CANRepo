#include "supervisors/supervisor_fallback_door_release.h"

#include <stdio.h>

#include "system/state_door_system.h"

#include "application/fallback_door_release.h"
#include "inputs/input_fallback_door_release.h"

void supervisor_fallback_door_release_task(void) {
	// return, if fallback door release button was not pressed
	ButtonEvent_t button_event = get_fallback_door_release_button_event();
	if (button_event != BUTTON_EVENT_PRESSED) {
		return;
	}

	// button was pressed
	StateFallbackDoorRelease_t state_fallback_door_release = get_system_state_fallback_door_release();

	StateVehicleMovement_t state_vehicle_movement = get_system_state_vehicle_movement();
	StateVehicleMovementInfo_t state_vehicle_movement_info = get_system_state_vehicle_movement_info();


	switch(state_fallback_door_release) {
	case STATE_FALLBACK_DOOR_RELEASE_ACTIVE:
		cmd_fallback_door_release_deactivate();
		break;
	case STATE_FALLBACK_DOOR_RELEASE_INACTIVE:
		// TODO create specific interlock for vehicle movement and info?
		if (state_vehicle_movement == STATE_VEHICLE_MOVEMENT_STOPPED
			&& state_vehicle_movement_info == STATE_VEHICLE_MOVEMENT_INFO_VALID) {
			cmd_fallback_door_release_activate();

		} else {
			// TODO: Can request be rejected explicitly?
			printf("Warning: F-Door-Release rejected\r\n"); // will be redirected to UART-output
		}
		break;
	}
}
