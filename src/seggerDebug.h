
#include "SEGGER_RTT.h"
#include <string.h>

#define comm_max_length    100
#define comm_max_count     10
#define data_max_count     20

int Segger_init(void *program_, const char *call);

void Segger_Pool();

void Segger_timer_handler(struct k_timer *dummy);

void Segger_start(char end_of_line_, char separator_);