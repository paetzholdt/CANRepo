#include "supervisors/supervisor_stop_request.h"


#include "system/system_state_types.h"
#include "system/state_door_system.h"


#include "application/stop_request.h"
#include "inputs/input_stop_request.h"

void supervisor_stop_request_task(void) {
	// return if no stop request button was pressed
	ButtonEvent_t button_event = get_stop_request_button_event();
	if (button_event != BUTTON_EVENT_PRESSED) {
		return;
	}


	switch (get_system_state_stop_request()) {
		case STATE_STOP_REQUEST_RESET:
			if (get_system_state_door_opening_permission() == STATE_DOOR_OPENING_PERMISSION_GRANTED) {
				// request doors open
			} else {
				cmd_stop_request_set();
			}
			break;
		case STATE_STOP_REQUEST_SET:
			break;
	}


}
