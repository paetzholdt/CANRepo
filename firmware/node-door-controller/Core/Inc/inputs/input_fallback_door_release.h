#ifndef INPUT_FALLBACK_DOOR_RELEASE_H
#define INPUT_FALLBACK_DOOR_RELEASE_H

#include "hardware/button.h"

ButtonEvent_t get_fallback_door_release_button_event(void);

void input_fallback_door_release_task(void);

#endif
