#include "application/door.h"

#include "system/state_door_system_internal.h"

#include "hardware/leds.h"
#include "stm32g0xx_hal.h"


static StateDoors_t state_doors;

void doors_init(void) {
	state_doors = STATE_DOORS_CLOSED;
	set_system_state_doors(state_doors);
	set_green_loop_led(true);
}


// TODO: outsource LED-logic?
void doors_task(void) {
	switch (state_doors) {
		case STATE_DOORS_CLOSED:
			set_green_loop_led(true);
			break;

		case STATE_DOORS_OPEN:
			set_green_loop_led(false);
			break;
	}
}

void cmd_doors_open(void) {
	// command opening of doors
	// TODO: is there a chance of representing hardware or more software as doors?
	state_doors = STATE_DOORS_OPEN;
	set_system_state_doors(state_doors);
}

void cmd_doors_close(void) {
	state_doors = STATE_DOORS_CLOSED;
	set_system_state_doors(state_doors);
}
