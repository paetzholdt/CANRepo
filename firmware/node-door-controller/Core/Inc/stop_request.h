#ifndef STOP_REQUEST_H
#define STOP_REQUEST_H

typedef enum {
	STOP_REQUEST_RESET,
	STOP_REQUEST_SET
} StopRequestState_t;

void stop_request_task(void);

#endif
