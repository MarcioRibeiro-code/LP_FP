#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t size;
} Array;

/* Initialise an empty array */
void Array_Init(Array *array) {
    int *int_pointer;

    int_pointer = (int *) malloc(sizeof (int));

    if (int_pointer == NULL) {
        printf("Unable to allocate memory, exiting.\n");
        free(int_pointer);
        exit(0);
    } else {
        array->array = int_pointer;
        array->size = 0;
    }
}

/* Dynamically add to end of an array */
void Array_Add(Array *array, int item) {
    int *int_pointer;

    array->size += 1;

    int_pointer = (int *) realloc(array->array, array->size * sizeof (int));

    if (int_pointer == NULL) {
        printf("Unable to reallocate memory, exiting.\n");
        free(int_pointer);
        exit(0);
    } else {
        array->array = int_pointer;
        array->array[array->size - 1] = item;
    }
}

/* Delete from a dynamic array */
void Array_Delete(Array *array, int index) {
    int i;
    Array temp;
    int *int_pointer;

    Array_Init(&temp);

    for (i = index; i < array->size; i++) {
        array->array[i] = array->array[i + 1];
    }

    array->size -= 1;

    for (i = 0; i < array->size; i++) {
        Array_Add(&temp, array->array[i]);
    }

    int_pointer = (int *) realloc(temp.array, temp.size * sizeof (int));

    if (int_pointer == NULL) {
        printf("Unable to reallocate memory, exiting.\n");
        free(int_pointer);
        exit(0);
    } else {
        array->array = int_pointer;
    }
}

/* Free an array */
void Array_Free(Array *array) {
    free(array->array);
    array->array = NULL;
    array->size = 0;
}

int main(int argc, char** argv) {
    Array pointers;
    int i;

    Array_Init(&pointers);

    for (i = 0; i < 60; i++) {
        Array_Add(&pointers, i);
    }

    Array_Delete(&pointers, 3);

    Array_Delete(&pointers, 6);

    Array_Delete(&pointers, 30);

    for (i = 0; i < pointers.size; i++) {
        printf("Value: %d Size:%d \n", pointers.array[i], pointers.size);
    }

    Array_Free(&pointers);

    return (EXIT_SUCCESS);
}