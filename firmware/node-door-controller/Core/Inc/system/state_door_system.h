#ifndef STATE_DOOR_SYSTEM_H
#define STATE_DOOR_SYSTEM_H


#include "system/system_state_types.h"

#include "application/stop_request.h"
#include "application/door_release.h"
#include "application/door.h"


StateStopRequest_t get_system_state_stop_request(void);

StateDoorRelease_t get_system_state_door_release(void);

StateDoors_t get_system_state_doors(void);

StateDoorOpeningPermission_t get_system_state_door_opening_permission(void);


#endif
