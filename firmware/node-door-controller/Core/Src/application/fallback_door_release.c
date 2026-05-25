#include "application/fallback_door_release.h"

#include "system/state_door_system_internal.h"
#include "inputs/input_fallback_door_release.h"
#include "hardware/leds.h"


static StateFallbackDoorRelease_t state_fallback_door_release;


void fallback_door_release_init(void) {
	state_fallback_door_release = STATE_FALLBACK_DOOR_RELEASE_INACTIVE;
	set_system_state_fallback_door_release(state_fallback_door_release);
	set_fallback_door_release_led(false);
}

void fallback_door_release_task(void) {
	switch(state_fallback_door_release) {
		case STATE_FALLBACK_DOOR_RELEASE_INACTIVE:
			set_fallback_door_release_led(false);
			break;
		case STATE_FALLBACK_DOOR_RELEASE_ACTIVE:
			set_fallback_door_release_led(true);
			break;
	}
}


void cmd_fallback_door_release_activate(void) {
	state_fallback_door_release = STATE_FALLBACK_DOOR_RELEASE_ACTIVE;
	set_system_state_fallback_door_release(state_fallback_door_release);
}

void cmd_fallback_door_release_deactivate(void) {
	state_fallback_door_release = STATE_FALLBACK_DOOR_RELEASE_INACTIVE;
	set_system_state_fallback_door_release(state_fallback_door_release);
}
