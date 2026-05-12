#include "door.h"

#include "stm32g0xx_hal.h"
#include "stm32g0xx_hal_gpio.h"
#include "door_control.h"


/* TODO: do not insert door control logic into door.c
 * - the doors shall not know, which dependencies they have
 * - the door shall only know, if there is a valid door opening request
 * - the door will return an answer, when the doors have been successfully opened AND another, when they are closed
 */


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
			if (is_valid_open_door_command()) {

				// command opening of doors
				// TODO: is there a chance of representing hardware or more software as doors?
				timestamp_begin_of_doors_open = HAL_GetTick();
				door_state = DOORS_OPEN;
			}
			break;
		case DOORS_OPEN:

			if (is_valid_open_door_command()) {
				timestamp_begin_of_doors_open = HAL_GetTick();
			}

			if ((HAL_GetTick() - timestamp_begin_of_doors_open) >= duration_of_open_doors_ms) {
				door_state = DOORS_CLOSED;
			}

			break;
	}
}
