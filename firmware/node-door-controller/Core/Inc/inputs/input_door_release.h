#ifndef INPUT_DOOR_RELEASE_H
#define INPUT_DOOR_RELEASE_H

#include "hardware/button.h"


/**
 * @brief Returns and consumes the current door release button event.
 *
 * @return Current button event
 */
ButtonEvent_t get_door_release_button_event(void);


/**
 * @brief Cyclic task of the door release input module.
 *
 * Updates the internal debounce state of the door release button.
 *
 * This function shall be called cyclically
 */
void input_door_release_task(void);


#endif
