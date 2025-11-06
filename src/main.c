#include <stdio.h>
#include "../headers/array-list-tree.h"
#define N 128

int main(){
    size_t test_index = 1000;
    alt_T alt = new_alt(100, N);
    printf("alt child 0 address: %llx\n", alt.entry_0);
    add_element_to_alt(&alt, test_index, 666);
    int32_t value =  get_element_from_alt(&alt, test_index);
    printf("Element number %d is... %d!\n", test_index, value);
    return 0;
}