#include "application/stop_request.h"

#include "system/state_door_system_internal.h"
#include "hardware/leds.h"

#include <stdbool.h>


static StateStopRequest_t state_stop_request;


void stop_request_init(void) {
	state_stop_request = STOP_REQUEST_RESET;
	set_system_state_stop_request(state_stop_request);
	set_stop_request_led(false);
}



void cmd_stop_request_set(void) {
	state_stop_request = STOP_REQUEST_SET;
	set_system_state_stop_request(state_stop_request);
}

void cmd_stop_request_reset(void) {
	state_stop_request = STOP_REQUEST_RESET;
	set_system_state_stop_request(state_stop_request);
}

// TODO: remove LED-management from FSM?
void stop_request_task(void) {
	switch (state_stop_request) {
		case STOP_REQUEST_RESET:
			set_stop_request_led(false);
			break;

		case STOP_REQUEST_SET:
			set_stop_request_led(true);
			break;
	}
}
