#include "../headers/array-list-tree.h"

alt_T new_alt(size_t length, size_t array_length){
    
    alt_T alt;
    alt.length = length; 
    alt.array_length = array_length;
    int num_elements = (length == 0)? 0 : (length / array_length) + 1;
    
    alt.entry_0 = new_element(NULL, array_length);
    alt.entry_1 = new_element(NULL, array_length);
    if(num_elements > 2){
        traverse_create_alt(&alt, length);
    }
    return alt;
}

element_T * new_element(element_T * parent, size_t array_length){
    element_T * element = malloc(sizeof(element_T) + sizeof(int32_t) * array_length);
    element->data = (int32_t *)(element + 1);
    element->child_0 = NULL;
    element->child_1 = NULL;
    return element;
}

element_T * check_element_and_create(element_T * parent, int child_idx, size_t array_length){
    if (parent == NULL){
        printf("Dude what the hell? This guy is NULL.\n");
        return NULL;
    }
    element_T * child = (child_idx == 0)? parent->child_0 : parent->child_1;
    if (child == NULL){
        child == new_element(parent, array_length);
    }
    return child;
}

element_T * traverse_alt(alt_T * alt, size_t index){
    int array_length = alt->array_length;
    index /= array_length;
    element_T * current_element;

    if (index & 1 == 0){
        current_element = alt->entry_0;
    }else{
        current_element = alt->entry_1;
    }
    index >>= 1;

    while(index > 0){
        if (index & 1 == 0){
            current_element = current_element->child_0;
        }else{
            current_element = current_element->child_1;
        }
        index >>= 1;
    }
    return current_element;
}

element_T * traverse_create_alt(alt_T * alt, size_t index){
    int array_length = alt->array_length;
    index /= array_length;
    element_T * current_element;
    
    if (index & 1 == 0){
        current_element = alt->entry_0;
    }else{
        current_element = alt->entry_1;
    }
    index >>= 1;

    while(index > 0){
        current_element = check_element_and_create(current_element, index & 1, array_length);
        index >>= 1;
    }
    return current_element;
}

int add_element_to_alt(alt_T * alt, size_t index, int32_t value){
    if(index < alt->array_length){
        element_T * element = traverse_alt(alt, index);
        int index_in_element = index % alt->array_length;
        element->data[index_in_element] = value;
        return 0;
    }
    return 1;
}

int32_t get_element_from_alt(alt_T * alt, size_t index){
    if(index < alt->array_length){
        element_T * element = traverse_alt(alt, index);
        int index_in_element = index % alt->array_length;
        return element->data[index_in_element];
    }
    return 0;
}