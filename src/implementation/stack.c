/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  stack c source file 
 *
 *        Version:  1.0
 *        Created:  05/09/2019 04:32:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <assert.h>

#include "../data-structure/stack.h"

void stack_new(stack* s,int elementSize,freeFunction freeFn)
{
    s->list = malloc(sizeof(list));
    list_new(s->list,elementSize,freeFn);
}

void stack_destroy(stack* s)
{
    list_destroy(s->list);
    free(s->list);
}

void stack_push(stack* s,void* element)
{
    list_prepend(s->list,element);
}

void stack_pop(stack* s,void* element)
{
    assert(stack_size(s) > 0);

    list_head(s->list,element,true);
}

void stack_peek(stack* s,void* element)
{
    assert(stack_size(s) > 0);

    list_head(s->list,element,false);
}

int stack_size(stack* s)
{
    return list_size(s->list);
}
