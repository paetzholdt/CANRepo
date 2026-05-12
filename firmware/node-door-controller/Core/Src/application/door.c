// TODO: write door_init()

#include "application/door.h"

#include "application/door_logic.h"
#include "hardware/leds.h"

#include "stm32g0xx_hal.h"

#include <stdbool.h>

static DoorState_t door_state = DOORS_CLOSED;

static const uint32_t duration_of_open_doors_ms = 5000U;

static uint32_t timestamp_begin_of_doors_open = 0;




bool are_all_doors_closed(void) {
	return (door_state == DOORS_CLOSED);
}

void door_task(void) {
	switch (door_state) {
		case DOORS_CLOSED:
			set_green_loop_led(true);
			if (is_valid_open_door_command()) {
				// command opening of doors
				// TODO: is there a chance of representing hardware or more software as doors?
				timestamp_begin_of_doors_open = HAL_GetTick();
				door_state = DOORS_OPEN;
			}
			break;

		case DOORS_OPEN:
			set_green_loop_led(false);

			if (is_valid_open_door_command()) {
				timestamp_begin_of_doors_open = HAL_GetTick();
			}

			if ((HAL_GetTick() - timestamp_begin_of_doors_open) >= duration_of_open_doors_ms) {
				door_state = DOORS_CLOSED;
			}

			break;
	}
}
