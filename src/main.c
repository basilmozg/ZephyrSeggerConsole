/*
 * J-Link RTT viewer debug helper
 * set "Send on enter"
 * set "End of line" CR or LF and set Segger_start('\n') or Segger_start('\r');
 */

#include "seggerDebug.h"
#include <logging/log.h>

#define LOG_MODULE_NAME SeggerDebug
LOG_MODULE_REGISTER(LOG_MODULE_NAME);

void call_1(char *com, int *data, uint8_t num)
{
    LOG_INF("call_1 feedback \"%s\"", log_strdup(com));
    LOG_INF("Params:");
    for(uint8_t i = 0; i < num; i++)
        LOG_INF("param %d = %d", i, *(data + i));
    LOG_INF("You can do something here");
}

void call_2(char *com, int *data, uint8_t num)
{
    LOG_INF("call_2 feedback \"%s\"", log_strdup(com));
    LOG_INF("Params:");
    for(uint8_t i = 0; i < num; i++)
        LOG_INF("param %d = %d", i, *(data + i));
    LOG_INF("You can do something here");
}

void call_3(char *com, int *data, uint8_t num)
{
    LOG_INF("call_3 feedback \"%s\"", log_strdup(com));
    LOG_INF("Params:");
    for(uint8_t i = 0; i < num; i++)
        LOG_INF("param %d = %d", i, *(data + i));
    LOG_INF("You can do something here");
}

void main() 
{
    int err;

    LOG_INF("* J-Link RTT viewer debug helper");
    LOG_INF("* set \"Send on enter\"");
    LOG_INF("* set \"End of line\" CR or LF and set Segger_start('\\n') or Segger_start('\\r') ");
/* Set callback handler for keyword "calibration"
*/
    err = Segger_init(&call_1, "end");

/* Set callback handler for keyword "reset"
*/
    err = Segger_init(&call_2, "reset");

/* Set callback handler for keyword "start"
*/
    err = Segger_init(&call_3, "start");

/* Check for overflow
*/
    if(err) LOG_ERR("overflow of the number of keywords");

/*Start RTT debug for '\n' end char of line
 *Set separator char for data stream
*/
    Segger_start('\n', ' ');
}