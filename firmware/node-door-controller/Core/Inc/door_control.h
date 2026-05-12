#ifndef DOOR_CONTROL_H
#define DOOR_CONTROL_H

#include <stdbool.h>

bool is_valid_open_door_command(void);
void door_control_task(void);

#endif
