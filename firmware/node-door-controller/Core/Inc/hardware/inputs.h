#ifndef INPUTS_H
#define INPUTS_H

#include <hardware/button.h>

void update_inputs(void);

ButtonEvent_t get_door_release_button_event(void);

ButtonEvent_t get_stop_request_button_event(void);

#endif
