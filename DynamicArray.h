#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

#define ERROR_VAL -1 //TODO: use better error handling

typedef int elementType;

typedef struct {

   size_t elementCount;
   size_t maxElements;
   elementType *elements;

} DynamicArray;

void initDynamicArray(DynamicArray *array);
void addAtTail(DynamicArray *array, elementType data);
void addAtFront(DynamicArray *array, elementType data);
int size(DynamicArray *array);
void removeAll(DynamicArray *array);
int getAt(DynamicArray *array, int index);
void freeDynamicArray(DynamicArray *array);

#endif
