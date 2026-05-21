#ifndef STOP_REQUEST_H
#define STOP_REQUEST_H

#include <stdbool.h>

typedef enum {
	STATE_STOP_REQUEST_RESET,
	STATE_STOP_REQUEST_SET
} StateStopRequest_t;


void stop_request_init(void);

void stop_request_task(void);


void cmd_stop_request_set(void);

void cmd_stop_request_reset(void);


#endif
