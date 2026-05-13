#ifndef DOOR_RELEASE_H
#define DOOR_RELEASE_H

#include <stdbool.h>


typedef enum {
	DOOR_RELEASE_INACTIVE,
	DOOR_RELEASE_ACTIVE
} DoorReleaseState_t;


void door_release_init(void);

void door_release_task(void);

bool is_door_release_active(void);

#endif
