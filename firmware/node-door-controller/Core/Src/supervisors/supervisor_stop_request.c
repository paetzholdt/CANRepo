#include "supervisors/supervisor_stop_request.h"

#include <stdio.h>


#include "system/state_door_system.h"
#include "system/door_requests.h"


#include "application/stop_request.h"
#include "inputs/input_stop_request.h"


static void process_stop_request_button_event(StateStopRequest_t state_stop_request) {
	StateDoorOpeningPermission_t state_door_opening_permission = get_system_state_door_opening_permission();

	switch (state_door_opening_permission) {
		case STATE_DOOR_OPENING_PERMISSION_GRANTED:
				rqst_doors_open();
			break;
		case STATE_DOOR_OPENING_PERMISSION_REVOKED:
			if (state_stop_request == STATE_STOP_REQUEST_RESET) {
				cmd_stop_request_set();
			} else {
				printf("Ignore duplicate stop request\r\n");
			}
			break;
	}
}

static void check_conditions_state_stop_request(void) {
	StateStopRequest_t state_stop_request = get_system_state_stop_request();

	// return if stop request is not set
	if (state_stop_request == STATE_STOP_REQUEST_RESET) {
		return;
	}

	StateDoorRelease_t state_door_release = get_system_state_door_release();
	StateFallbackDoorRelease_t state_fallback_door_release = get_system_state_fallback_door_release();


	if (state_door_release == STATE_DOOR_RELEASE_ACTIVE || state_fallback_door_release == STATE_FALLBACK_DOOR_RELEASE_ACTIVE) {
		StateDoors_t state_doors = get_system_state_doors();

		if (state_doors == STATE_DOORS_CLOSED) {
			rqst_doors_open();
		} else {
			cmd_stop_request_reset();
		}
	}
}


void supervisor_stop_request_task(void) {
	// return if no stop request button was pressed
	ButtonEvent_t button_event = get_stop_request_button_event();
	StateStopRequest_t state_stop_request = get_system_state_stop_request();

	if (button_event == BUTTON_EVENT_PRESSED) {
		process_stop_request_button_event(state_stop_request);
	}

	if (state_stop_request == STATE_STOP_REQUEST_SET) {
		check_conditions_state_stop_request();
	}
}

