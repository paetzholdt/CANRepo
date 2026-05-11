// NOTE: this module will grow step by step with each new module, that is relevant to the topic of door-safety (e.g. fallback door release, station detection)
// TODO: evaluate if this module should take care of every door-related feedback-LED?

#include "door_control.h"

#include "door_release.h"
#include "stop_request.h"

#include <stdbool.h>


bool is_valid_open_door_request(void) {
	return (is_door_release_active() && is_stop_request_set());
}
