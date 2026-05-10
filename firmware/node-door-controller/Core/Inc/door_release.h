#ifndef DOOR_RELEASE_H
#define DOOR_RELEASE_H


typedef enum {
	DOOR_RELEASE_INACTIVE,
	DOOR_RELEASE_ACTIVE
} DoorReleaseState_t;


void door_release_task(void);

#endif
