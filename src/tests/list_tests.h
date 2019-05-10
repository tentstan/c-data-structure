/*
 * =====================================================================================
 *
 *       Filename:  list_test.h
 *
 *    Description:  list_test head file 
 *
 *        Version:  1.0
 *        Created:  05/10/2019 09:22:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "../data-structure/list.h"

void test_list_initialize()
{
    list l;
    list_new(&l,sizeof(int),NULL);

    assert(list_size(&l) == 0);
    assert(l.elementSize == sizeof(int));
    assert(l.head == NULL);
    assert(l.tail == NULL);
    assert(l.freeFn == NULL);

    list_destroy(&l);

    PRINT_SUCCESS();
}

void test_list_can_append_item()
{
    list l;
    list_new(&l,sizeof(int),NULL);

    int i ;
    for(i = 0; i < 10; i++)
    {
        list_append(&l,&i);
    }

    assert(list_size(&l) == 10);

    int value;
    list_tail(&l,&value);
    assert(value == 9);

    list_head(&l,&value,false);
    assert(value == 0);

    list_destroy(&l);

    PRINT_SUCCESS();
}

void test_list_can_prepend_item()
{
    list l;
    list_new(&l,sizeof(int),NULL);

    int i ;
    for(i = 0; i < 10; i++)
    {
        list_prepend(&l,&i);
    }

    assert(list_size(&l) == 10);

    int value;

    list_tail(&l,&value);
    assert(value == 0);

    list_head(&l,&value);
    assert(value == 9);

    list_destroy(&l);

    PRINT_SUCCESS();
}

static int IteratorCount;

bool test_list_iterator(void* data)
{
    assert(*(int*)data == IteratorCount++);
    if(IteratorCount == 5)
    {
        return false;
    }
    return true;
}

void test_list_can_iterator_over_nodes()
{
    list l;
    list_new(&l,sizeof(int),NULL);

    int i;
    int numItems = 10;
    for(i = 0; i < numItems; i++)
    {
        list_append(&l,&i);
    }

    assert(list_size(&l) == numItems);

    IteratorCount = 0;
    list_for_each(&l,test_list_iterator);
    assert(IteratorCount == 5);

    list_destroy(&l);

    PRINT_SUCCESS();
}

void test_list_operations()
{
    test_list_initialize();
    test_list_can_append_item();
    test_list_can_prepend_item();
    test_list_can_iterator_over_nodes();
}
