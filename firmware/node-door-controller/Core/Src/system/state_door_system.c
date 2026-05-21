#include "system/state_door_system.h"
#include "system/state_door_system_internal.h"


#include "application/stop_request.h"
#include "application/door_release.h"

static StateStopRequest_t system_state_stop_request;
static StateDoorRelease_t system_state_door_release;


StateStopRequest_t get_system_state_stop_request(void) {
	return system_state_stop_request;
}

void set_system_state_stop_request(StateStopRequest_t state_stop_request) {
	system_state_stop_request = state_stop_request;
}
