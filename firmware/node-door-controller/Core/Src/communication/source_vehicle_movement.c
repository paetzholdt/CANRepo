// !!! temporary development mock, not for production/safety use
// TODO: replace when CAN-communication for vehicle movement is available

#include "communication/source_vehicle_movement.h"

#include "system/system_state_types.h"
#include "system/state_door_system_internal.h"


void mock_vehicle_movement_task(void) {
	set_system_state_vehicle_movement(STATE_VEHICLE_MOVEMENT_STOPPED);
	set_system_state_vehicle_movement_info(STATE_VEHICLE_MOVEMENT_INFO_VALID);
}
