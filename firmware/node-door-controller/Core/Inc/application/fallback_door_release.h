#ifndef FALLBACK_DOOR_RELEASE_H
#define FALLBACK_DOOR_RELEASE_H

typedef enum {
	STATE_FALLBACK_DOOR_RELEASE_INACTIVE,
	STATE_FALLBACK_DOOR_RELEASE_ACTIVE
} StateFallbackDoorRelease_t;


void fallback_door_release_init(void);

void fallback_door_release_task(void);


void cmd_fallback_door_release_activate(void);

void cmd_fallback_door_release_deactivate(void);

#endif
