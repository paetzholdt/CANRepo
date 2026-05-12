#include "application/door_logic.h"
#include "application/stop_request.h"

#include "hardware/inputs.h"
#include "main.h"


static StopRequestState_t stop_request_state = STOP_REQUEST_RESET;

bool is_stop_request_set(void) {
	return (stop_request_state == STOP_REQUEST_SET);
}

void stop_request_task(void) {
	switch (stop_request_state) {
		case STOP_REQUEST_RESET:
			if (get_stop_request_button_event() == BUTTON_EVENT_PRESSED) {
				stop_request_state = STOP_REQUEST_SET;
			}
			break;

		case STOP_REQUEST_SET:
			// TODO: implement state change
			if (is_valid_open_door_command()) {
				stop_request_state = STOP_REQUEST_RESET;
			}
			break;
	}

}
