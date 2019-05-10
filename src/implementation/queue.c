/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  queue c source file 
 *
 *        Version:  1.0
 *        Created:  05/09/2019 04:27:04 PM
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

#include "../data-structure/queue.h"

void queue_new(queue* q,int elementSize,freeFunction freeFn)
{
    q->list = malloc(sizeof(list));
    list_new(q->list,elementSize,freeFn);
}

void queue_destroy(queue* q)
{
    list_destroy(q->list);
    free(q->list);
}

void queue_enqueue(queue* q,void* element)
{
    list->append(q->list,element);
}

void queue_dequeue(queue* q,void* element)
{
    list->head(q->list,element,true);
}

void queue_peek(queue* q,void* element)
{
    list->head(q->list,element,false);
}

int queue_size(queue* q)
{
    return list_size(q->list);
}
