#ifndef STATE_DOOR_SYSTEM_INTERNAL_H
#define STATE_DOOR_SYSTEM_INTERNAL_H

#include "application/stop_request.h"
#include "application/door_release.h"

void set_system_state_stop_request(StateStopRequest_t state_stop_request);

void set_system_state_door_release(StateDoorRelease_t state_door_release);

#endif
