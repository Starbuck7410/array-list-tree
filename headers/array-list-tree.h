#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct element_T element_T;

struct element_T {
    element_T * parent;
    element_T * child_0;
    element_T * child_1;
    int32_t * data; // size array_length
};



typedef struct alt_T {
    size_t length;
    size_t array_length;
    element_T * entry_0;
    element_T * entry_1;
} alt_T;

alt_T new_alt(size_t length, size_t array_length);
element_T * new_element(element_T * parent, size_t array_length);
element_T * check_element_and_create(element_T * parent, int child_idx, size_t array_length);
element_T * traverse_alt(alt_T * alt, size_t index);
element_T * traverse_create_alt(alt_T * alt, size_t index);
int add_element_to_alt(alt_T * alt, size_t index, int32_t value);
int32_t get_element_from_alt(alt_T * alt, size_t index);