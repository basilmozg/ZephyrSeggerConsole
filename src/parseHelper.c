#include "parseHelper.h"
#include "math.h"
#include <string.h>

void ArrayRevers(void *inputArrayVoid, uint8_t len, uint8_t type_size)
{
    int *inputArray = inputArrayVoid;
    int temp_data_array[len];
    for(uint8_t i = 0; i < len; i++)
        temp_data_array[i] = *(inputArray + len - i - 1);
    memcpy(inputArray, temp_data_array, len * type_size);
}

uint8_t ParseCharArray(char *input_array, char *compare_char_array, int *data_array, uint8_t *data_number, char data_separator)
{
    if(memcmp(input_array, compare_char_array, strlen(compare_char_array)) == 0)
    {
        uint8_t digit = 0;
        for(uint8_t x = strlen(input_array); x > 0; x--)
        {
            if(input_array[x] > 47 && input_array[x] < 58)
            {
                *(data_array + *data_number) += (int) (*(input_array + x) - 48) * pow(10, digit);
                digit++;
            }
            if(*(input_array + x) == data_separator && digit != 0) {digit = 0; (*(data_number))++;}
        }
        ArrayRevers(data_array, *(data_number), (uint8_t) sizeof(data_array));
        return 1;
    } 
    else return 0;
}