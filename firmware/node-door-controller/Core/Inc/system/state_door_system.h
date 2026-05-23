#ifndef STATE_DOOR_SYSTEM_H
#define STATE_DOOR_SYSTEM_H

#include "application/stop_request.h"
#include "application/door_release.h"
#include "application/door.h"


typedef enum {
	STATE_DOOR_OPENING_PERMISSION_GRANTED,
	STATE_DOOR_OPENING_PERMISSION_REVOKED
} StateDoorOpeningPermission_t;


StateStopRequest_t get_system_state_stop_request(void);

StateDoorRelease_t get_system_state_door_release(void);

StateDoors_t get_system_state_doors(void);

StateDoorOpeningPermission_t get_system_state_door_opening_permission(void);


#endif
