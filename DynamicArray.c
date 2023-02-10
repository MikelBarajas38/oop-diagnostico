#include "DynamicArray.h"

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//helper functions
bool isFull(DynamicArray *array);
void resizeDynamicArray(DynamicArray *array);
elementType *begin(DynamicArray *array);
elementType *end(DynamicArray *array);


void initDynamicArray(DynamicArray *array)
{
    array->elementCount = 0;
    array->maxElements = 0;
    array->elements = NULL;
}

void addAtTail(DynamicArray *array, elementType data)
{
    if(isFull(array)) {
        resizeDynamicArray(array);
    }

    array->elements[array->elementCount] = data;
    (array->elementCount)++;
}

void addAtFront(DynamicArray *array, elementType data)
{
    if(isFull(array)) {
        resizeDynamicArray(array);
    }


    for(elementType *iterator = end(array); iterator > begin(array); iterator--) {
        *iterator = *(iterator-1);
    }

    array->elements[0] = data;
    (array->elementCount)++;
}

int size(DynamicArray *array)
{
    return array->elementCount;
}

//logical deletion is used instead of physical deletion for better performance [ O(1) vs O(n) ]
void removeAll(DynamicArray *array) 
{
    array->elementCount = 0;
}

int getAt(DynamicArray *array, int index)
{
    if(index < 0 || index >= (int) array->elementCount){
        return ERROR_VAL;
    }

    return array->elements[index];
}

void freeDynamicArray(DynamicArray *array)
{
    free(array->elements);
}

//helper functions ----------------------------------------------------------------------------------

bool isFull(DynamicArray *array)
{
    return array->elementCount == array->maxElements;
}

void resizeDynamicArray(DynamicArray *array)
{
    if(array->maxElements > 0) {
        array->maxElements *= 2;
    } else {
        array->maxElements = 1;
    }

    elementType *newArray = (elementType *) realloc(array->elements, array->maxElements * sizeof(elementType));
    assert(newArray);
    array->elements = newArray;
}

elementType *begin(DynamicArray *array)
{
    return array->elements;
}

elementType *end(DynamicArray *array)
{
    return array->elements + array->elementCount;
}
