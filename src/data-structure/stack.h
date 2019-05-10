/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  stack head file 
 *
 *        Version:  1.0
 *        Created:  05/09/2019 02:56:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __CDS_STACK_H
#define __CDS_STACK_H 

#include "common.h"
#include "list.h"

typedef struct {
    list* list;
}stack;

void stack_new(stack* s,int elementSize,freeFunction freeFn);
void stack_destroy(stack* s);
void stack_push(stack* s,void* element);
void stack_pop(stack* s,void* element);
void stack_peek(stack* s,void* element);
int stack_size(stack* s);

#endif
