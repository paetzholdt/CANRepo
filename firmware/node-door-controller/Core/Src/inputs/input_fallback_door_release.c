#include "inputs/input_fallback_door_release.h"

#include "hardware/button.h"

// TODO define hardware in MX and implement here
static Button_t fallback_door_release_button = {

};


ButtonEvent_t get_fallback_door_release_button_event(void) {
	return get_button_event(&fallback_door_release_button);
};

void input_fallback_door_release_task(void) {
	update_button(&fallback_door_release_button);
}
