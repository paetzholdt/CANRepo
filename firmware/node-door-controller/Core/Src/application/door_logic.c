// NOTE: this module will grow step by step with each new module, that is relevant to the topic of door-safety (e.g. fallback door release, station detection)

#include "application/door_logic.h"
#include "application/door_release.h"
#include "application/stop_request.h"
#include "application/door.h"

#include <stdbool.h>


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

}
