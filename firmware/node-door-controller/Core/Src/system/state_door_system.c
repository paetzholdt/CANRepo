#include "system/state_door_system.h"
#include "system/state_door_system_internal.h"


#include "application/stop_request.h"
#include "application/door_release.h"
#include "application/door.h"


static StateStopRequest_t system_state_stop_request;
static StateDoorRelease_t system_state_door_release;
static StateDoors_t system_state_doors;

static StateDoorOpeningPermission_t system_state_door_opening_permission;

static StateVehicleMovement_t system_state_vehicle_movement;
static StateVehicleMovementInfo_t system_state_vehicle_movement_info;


StateStopRequest_t get_system_state_stop_request(void) {
	return system_state_stop_request;
}

void set_system_state_stop_request(StateStopRequest_t state_stop_request) {
	system_state_stop_request = state_stop_request;
}


StateDoorRelease_t get_system_state_door_release(void) {
	return system_state_door_release;
}

void set_system_state_door_release(StateDoorRelease_t state_door_release) {
	system_state_door_release = state_door_release;
}


StateDoors_t get_system_state_doors(void) {
	return system_state_doors;
}

void set_system_state_doors(StateDoors_t state_doors) {
	system_state_doors = state_doors;
}


StateDoorOpeningPermission_t get_system_state_door_opening_permission(void) {
	return system_state_door_opening_permission;
}

void set_system_state_door_opening_permission(StateDoorOpeningPermission_t state_door_opening_permission) {
	system_state_door_opening_permission = state_door_opening_permission;
}


StateVehicleMovement_t get_system_state_vehicle_movement(void) {
	return system_state_vehicle_movement;
}

void set_system_state_vehicle_movement(StateVehicleMovement_t state_vehicle_movement) {
	system_state_vehicle_movement = state_vehicle_movement;
}


StateVehicleMovementInfo_t get_system_state_vehicle_movement_info(void) {
	return system_state_vehicle_movement_info;
}

void set_system_state_vehicle_movement_info(StateVehicleMovementInfo_t state_vehicle_movement_info) {
	system_state_vehicle_movement_info = state_vehicle_movement_info;
}
