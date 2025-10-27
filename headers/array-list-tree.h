#include <stdlib.h>
#include <stdint.h>
#define N 128

typedef struct element_T {
    element_T * parent;
    element_T * child_0;
    element_T * child_1;
    int32_t * data; // size array_length
} element_T;



typedef struct alt_T {
    size_t length;
    size_t array_length;
    element_T * entry;
} alt_T;