// this module is based on the file docs/models/requirements/node_door_controller/state_door_opening_permission_interlock
// TODO: add fallback_door_release, station_detection and vehicle_movement

#include "supervisors/supervisor_door_opening_permission.h"

#include "system/state_door_system.h"
#include "system/state_door_system_internal.h"


// default shall be safe state
static StateDoorOpeningPermission_t state_door_opening_permission = STATE_DOOR_OPENING_PERMISSION_REVOKED;


void supervisor_door_opening_permission_task(void) {
	// TODO: fallback_door_release, station_detection and vehicle_movement will be added
	if (get_system_state_door_release() == STATE_DOOR_RELEASE_ACTIVE) {
		state_door_opening_permission = STATE_DOOR_OPENING_PERMISSION_GRANTED;
	} else {
		state_door_opening_permission = STATE_DOOR_OPENING_PERMISSION_REVOKED;
	}

	set_system_state_door_opening_permission(state_door_opening_permission);

}
