#ifndef STATE_DOOR_SYSTEM_INTERNAL_H
#define STATE_DOOR_SYSTEM_INTERNAL_H

#include "application/stop_request.h"
#include "application/door_release.h"
#include "application/door.h"

#include "system/state_door_system.h"

void set_system_state_stop_request(StateStopRequest_t state_stop_request);

void set_system_state_door_release(StateDoorRelease_t state_door_release);

void set_system_state_doors(StateDoors_t state_doors);

void set_system_state_door_opening_permission(StateDoorOpeningPermission_t state_door_opening_permission);

#endif
