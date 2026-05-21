#include "supervisors/supervisor_stop_request.h"

#include "system/state_door_system.h"
#include "application/stop_request.h"
#include "inputs/input_stop_request.h"

#include <stdbool.h>

void supervisor_stop_request_task(void) {
	// return if no stop request button was pressed
	if (!(get_stop_request_button_event() == BUTTON_EVENT_PRESSED)) {
		return;
	}


	switch (get_system_state_stop_request()) {
		case STATE_STOP_REQUEST_RESET:
			break;
		case STATE_STOP_REQUEST_SET:
			break;
	}


}
