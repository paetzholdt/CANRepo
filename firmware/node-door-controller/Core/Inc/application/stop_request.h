#ifndef STOP_REQUEST_H
#define STOP_REQUEST_H

#include <stdbool.h>

typedef enum {
	STOP_REQUEST_RESET,
	STOP_REQUEST_SET
} StopRequestState_t;

void stop_request_task(void);

bool is_stop_request_set(void);

#endif
