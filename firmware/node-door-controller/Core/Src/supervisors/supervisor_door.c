#include "supervisors/supervisor_door.h"

#include <stdio.h>
#include <stdint.h>

#include "stm32g0xx_hal.h"

#include "system/door_requests.h"
#include "system/state_door_system.h"

static uint32_t timestamp_begin_of_doors_open = 0;
static const uint32_t duration_of_open_doors_ms = 5000U;

static void process_door_request(StateDoors_t state_doors) {
	bool is_rqst_doors_open = consume_rqst_doors_open();

		if (!is_rqst_doors_open) {
			return;
		}

		StateDoorOpeningPermission_t state_door_opening_permission = get_system_state_door_opening_permission();

		switch (state_door_opening_permission) {
			case STATE_DOOR_OPENING_PERMISSION_GRANTED:
				if (state_doors == STATE_DOORS_CLOSED) {
					timestamp_begin_of_doors_open = HAL_GetTick();
					cmd_doors_open();
				} else {
					// reset timer, if doors are open already
					timestamp_begin_of_doors_open = HAL_GetTick();

				}
				break;
			case STATE_DOOR_OPENING_PERMISSION_REVOKED:
				// TODO: further implement what to do in case doors are open already, e.g. force_shut, alert, ...?
				printf("Warning: Doors are not allowed to open\r\n");
				break;
			}
}

static void check_door_timer(StateDoors_t state_doors) {
	// Note: if a real door was modeled, this logic needed to be refined, since it would spam to close doors repeatedly, while the doors are closing
	if (state_doors == STATE_DOORS_CLOSED) {
		return;
	}

	// Note: if further door_logic is implemented like (cmd_central_doors_open or emergency_doors_open or similar, this logic needs to be refined
	if ((HAL_GetTick() - timestamp_begin_of_doors_open) >= duration_of_open_doors_ms) {
			cmd_doors_close();
	}
}


void supervisor_door_task(void) {

	StateDoors_t state_doors = get_system_state_doors();

	process_door_request(state_doors);
	check_door_timer(state_doors);
}


