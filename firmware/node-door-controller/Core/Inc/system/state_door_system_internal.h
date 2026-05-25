#ifndef STATE_DOOR_SYSTEM_INTERNAL_H
#define STATE_DOOR_SYSTEM_INTERNAL_H


#include "system/system_state_types.h"

#include "application/stop_request.h"
#include "application/door_release.h"
#include "application/fallback_door_release.h"
#include "application/door.h"


void set_system_state_stop_request(StateStopRequest_t state_stop_request);

void set_system_state_door_release(StateDoorRelease_t state_door_release);

void set_system_state_fallback_door_release(StateFallbackDoorRelease_t state_fallback_door_release);

void set_system_state_doors(StateDoors_t state_doors);


void set_system_state_door_opening_permission(StateDoorOpeningPermission_t state_door_opening_permission);


void set_system_state_vehicle_movement(StateVehicleMovement_t state_vehicle_movement);
void set_system_state_vehicle_movement_info(StateVehicleMovementInfo_t state_vehicle_movement_info);

void set_system_state_station_detection(StateStationDetection_t state_station_detection);
void set_system_state_station_detection_info(StateStationDetectionInfo_t state_station_detection_info);

#endif
