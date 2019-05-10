/*
 * =====================================================================================
 *
 *       Filename:  vector.c
 *
 *    Description:  vector c source file 
 *
 *        Version:  1.0
 *        Created:  05/09/2019 04:40:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../data-structure/vector.h"

static void vector_grow(vector* vector)
{
    vector->allocatedLength *= 2;
    vector->elements = realloc(vector->elements,vector->elementSize * vector->allocatedLength);
    assert(vector->elements);
}

static void* vector_address(vector* vector,int index)
{
    int addr = vector->elementSize * index;
    return (char*)vector->elements + addr;
}

static void vector_copy_item(vector* vector,int sourceIndex,int destIndex)
{
    void* source = vector_address(vector,sourceIndex);
    void* dest = vector_address(vector,destIndex);
    memcpy(dest,source,vector->elementSize);
}

void vector_new(vector* vector,int elementSize,freeFunction freeFn)
{
    assert(elementSize > 0);

    vector->elementSize = elementSize;
    vector->logicalLength = 0;
    vector->allocatedLength = 2;
    vector->elements = NULL;
    vector->freeFn = freeFn;
    vector->grow(vector);
}

void vector_destroy(vector* vector)
{
    if(vector->freeFn)
    {
        int i = 0;
        for(i = 0; i < vector_size(vector);i++)
        {
            vector->freefn(vector_address(vector,i));
        }
    }

    free(vector->elements);
}

int vector_size(vector* vector)
{
    return vector->logicalLength;
}

void vector_add(vector* vector,void* element)
{
    if(vector->allocatedLength == vector->logicalLength)
    {
        vector->grow(vector);
    }

    void* target = vector_address(vector,vector->logicalLength);
    memcpy(target,element,vector->elementSize);
}

void vector_item_at(vector* vector,int index,void *target)
{
    assert(index >= 0 && index <= vector->logicalLength);

    void* source = vector_address(vector,index);
    memcpy(target,source,vector->elementSize);
}

void vector_insert_at(vector* vector,int index,void* target)
{
    assert(index >= 0 && index <= vector->logicalLength);
    vector_add(vector,target);

    if(index < vector->logicalLength)
    {
        int i;
        void* source;
        void* dest;

        for(i = vector->logicalLength - 2; i > index; i--)
        {
            source = vector_address(vector,i);
            dest = vector_address(vector,i+1);
            memcpy(dest,source,vector->elementSize);
        }

        dest = vector_address(vector,i);
        memcpy(dest,target,vector->elementSize);
    }
}

void vector_remove_at(vector* vector,int index)
{
    assert(index > 0 && index < vector->logicalLength);

    void* item = vector_address(vector,index);
    if(vector->freeFn)
    {
        vector->freeFn(item);
    }

    while(++index < vector->logicalLength)
    {
        vector_copy_item(vector,index,index - 1);
    }

    vector->logicalLength--;
}
