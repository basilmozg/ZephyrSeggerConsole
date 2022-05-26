#include "seggerDebug.h"
#include "parseHelper.h"

char input[comm_max_length] = {0};
uint8_t len = 0;
uint8_t prog_num = 0;
char prog_call[comm_max_count][comm_max_length] = {0};
void *prog[comm_max_count] = {NULL};
char end_of_line, separator;

int Segger_init(void *program_, const char *call)
{
    if(prog_num == comm_max_count) return -1;
    memcpy(&prog_call[prog_num][0], call, strlen(call));
    prog[prog_num] = program_;
    prog_num++;
    return 0;
}

void Segger_Pool()
{
    int r = SEGGER_RTT_GetKey();
    if(r != -1) 
    {
        while(r != -1 && r != end_of_line)
        {
            input[len] = r;
            len++;
            r = SEGGER_RTT_GetKey();
        }
        if(r == end_of_line || len == comm_max_length) 
        {
            uint8_t params_num = 0;
            int segger_params[data_max_count] = {0};
            for(uint8_t i = 0; i < prog_num; i++)
                if(ParseCharArray(input, &prog_call[i][0], segger_params, &params_num, separator))
                {
                    void (*fun_ptr)(char*, int*, uint8_t) = prog[i];
                    (*fun_ptr)(input, segger_params, params_num);
                }
            memset(input, 0, len);
            len = 0;
        }
    }
}

K_WORK_DEFINE(Segger_work, Segger_Pool);

void Segger_timer_handler(struct k_timer *dummy)
{
    k_work_submit(&Segger_work);
}

K_TIMER_DEFINE(Segger_timer, Segger_timer_handler, NULL);

void Segger_start(char end_of_line_, char separator_)
{
    end_of_line = end_of_line_;
    separator = separator_;
    k_timer_start(&Segger_timer, K_MSEC(200), K_MSEC(200));
}