// NOTE: this module will grow step by step with each new module, that is relevant to the topic of door-safety (e.g. fallback door release, station detection)
// TODO: evaluate if this module should take care of every door-related feedback-LED?

#include "door_control.h"

#include "door_release.h"
#include "stop_request.h"
#include "door.h"

#include <stdbool.h>

// TODO: remove include later, when hardware output access is capsuled
#include "main.h"


static bool all_doors_closed = true;
static bool stop_request_set = false;
static bool door_release_active = false;

static bool valid_open_door_command = false;


bool is_valid_open_door_command(void) {
	return valid_open_door_command;
}

void door_control_task(void) {
	stop_request_set = is_stop_request_set();
	door_release_active = is_door_release_active();
	all_doors_closed = are_all_doors_closed();

	if (stop_request_set && door_release_active) {
		valid_open_door_command = true;
	} else {
		valid_open_door_command = false;
	}

	if (stop_request_set) {
		// TODO: hardware access will be outsourced
		HAL_GPIO_WritePin(STOP_REQUEST_LED_GPIO_Port, STOP_REQUEST_LED_Pin, GPIO_PIN_SET);

	} else {
		// TODO: hardware access will be outsourced
		HAL_GPIO_WritePin(STOP_REQUEST_LED_GPIO_Port, STOP_REQUEST_LED_Pin, GPIO_PIN_RESET);
	}

	if (all_doors_closed) {
		// TODO: hardware access will be outsourced
		// maybe to door_control.c? -> taking care of all LEDs?
		HAL_GPIO_WritePin(GREEN_LOOP_LED_GPIO_Port, GREEN_LOOP_LED_Pin, GPIO_PIN_SET);
	} else {
		// TODO: hardware access will be outsourced
		HAL_GPIO_WritePin(GREEN_LOOP_LED_GPIO_Port, GREEN_LOOP_LED_Pin, GPIO_PIN_RESET);
	}

}
