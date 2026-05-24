// !!! temporary development mock, not for production/safety use
// TODO: replace when CAN-communication for vehicle movement is available


#include "communication/source_station_detection.h"

#include "system/system_state_types.h"
#include "system/state_door_system_internal.h"

void mock_station_detection_task(void) {
	set_system_state_station_detection(STATE_STATION_DETECTION_DETECTED);
	set_system_state_station_detection_info(STATE_STATION_DETECTION_INFO_VALID);
}
