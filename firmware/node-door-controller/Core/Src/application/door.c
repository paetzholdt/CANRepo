#include "application/door.h"


#include "hardware/leds.h"

#include "stm32g0xx_hal.h"

#include <stdbool.h>


static const uint32_t duration_of_open_doors_ms = 5000U;

static DoorState_t door_state;
static uint32_t timestamp_begin_of_doors_open;


void door_init(void) {
	door_state = DOORS_CLOSED;
	timestamp_begin_of_doors_open = 0;
	set_green_loop_led(true);
}



bool are_all_doors_closed(void) {
	return (door_state == DOORS_CLOSED);
}

void command_open_doors(void) {
	// command opening of doors
	// TODO: is there a chance of representing hardware or more software as doors?

	// reset timer, if doors are open already
	timestamp_begin_of_doors_open = HAL_GetTick();

	door_state = DOORS_OPEN;
}

void door_task(void) {
	switch (door_state) {
		case DOORS_CLOSED:
			set_green_loop_led(true);
			break;

		case DOORS_OPEN:
			set_green_loop_led(false);

			if ((HAL_GetTick() - timestamp_begin_of_doors_open) >= duration_of_open_doors_ms) {
				door_state = DOORS_CLOSED;
			}
			break;
	}
}
