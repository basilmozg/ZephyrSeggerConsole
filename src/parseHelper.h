#include <stdint.h>
#include <inttypes.h>

void ArrayRevers(void *inputArrayVoid, uint8_t len, uint8_t type_size);
uint8_t ParseCharArray(char *input_array, char *compare_char_array, int *data_array, uint8_t *data_number, char data_separator);