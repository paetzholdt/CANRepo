#ifndef DOOR_RELEASE_H
#define DOOR_RELEASE_H

#include <stdbool.h>


typedef enum {
	STATE_DOOR_RELEASE_INACTIVE,
	STATE_DOOR_RELEASE_ACTIVE
} StateDoorRelease_t;


void door_release_init(void);

void door_release_task(void);


void cmd_door_release_activate(void);

void cmd_door_release_deactivate(void);


#endif
