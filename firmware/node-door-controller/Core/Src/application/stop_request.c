#include "application/stop_request.h"

#include "application/door_logic.h"
#include "hardware/inputs.h"
#include "hardware/leds.h"


static StopRequestState_t stop_request_state;


void stop_request_init(void) {
	stop_request_state = STOP_REQUEST_RESET;
	set_stop_request_led(false);
}

bool is_stop_request_set(void) {
	return (stop_request_state == STOP_REQUEST_SET);
}

void stop_request_task(void) {

	switch (stop_request_state) {
		case STOP_REQUEST_RESET:
			set_stop_request_led(false);
			if (get_stop_request_button_event() == BUTTON_EVENT_PRESSED) {
				stop_request_state = STOP_REQUEST_SET;

			}
			break;

		case STOP_REQUEST_SET:
			set_stop_request_led(true);
			if (is_valid_open_door_command()) {
				stop_request_state = STOP_REQUEST_RESET;
			}
			break;
	}

}
