#ifndef INPUT_STOP_REQUEST_H
#define INPUT_STOP_REQUEST_H

#include "hardware/button.h"

/**
 * @brief Returns and consumes the current stop request button event.
 *
 * @return Current button event
 */
ButtonEvent_t get_stop_request_button_event(void);


/**
 * @brief Cyclic task of the stop request input module.
 *
 * Updates the internal debounce state machine of the stop request button.
 *
 * This function shall be called cyclically.
 */
void input_stop_request_task(void);

#endif
