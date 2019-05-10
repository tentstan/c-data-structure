/*
 * =====================================================================================
 *
 *       Filename:  stack_tests.h
 *
 *    Description:  stack_tests head file 
 *
 *        Version:  1.0
 *        Created:  05/10/2019 10:33:10 AM
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
#include "../data-structure/stack.h"

void test_stack_initialize()
{
    stack s;
    stack_new(&s,sizeof(int),NULL);

    assert(stack_size(&q) == 0);

    stack_destroy(&s);

    PRINT_SUCCESS();
}

void test_stack_can_push_item()
{
    stack s;
    stack_new(&s,sizeof(int),NULL);

    int value = 10;
    stack_push(&s,&value);

    assert(stack_size(&s) == 1);

    stack_destroy(&s);

    PRINT_SUCCESS();
}

void test_stack_can_pop_item()
{
    stack s;
    stack_new(&s,sizeof(int),NULL);

    int value = 10;
    stack_push(&s,&value);
    assert(stack_size(&s) == 1);

    int other;
    stack_pop(&s,&other);
    assert(other == value);
    assert(stack_size(&s) == 0);

    stack_destroy(&s);
    PRINT_SUCCESS();
}

void test_stack_can_peek_item()
{
    stack s;
    stack_new(&s,sizeof(int),NULL);

    int value;
    stack_push(&s,&value);
    assert(stack_size(&s) == 1);

    int other;
    stack_peek(&s,&other);
    assert(other == value);
    assert(stack_size(&s) == 1);

    stack_destroy(&s);
    PRINT_SUCCESS();
}

void test_stack_free_string(void* data)
{
    free(*(char**)data);
}

void test_stack_can_work_with_strings()
{
    stack s;
    stack_new(&s,sizeof(char*),test_stack_free_string);

    const char* names[] = {"David","Muto","Tester"};

    int i ;
    char* name;
    for(i = 0; i < 3;i++)
    {
        name = strdup(names[i]);
        stack_push(&s,name);
    }

    assert(stack_size(&s) == 3);

    stack_pop(&s,&name);
    assert(strcmp(name,"Tester") == 0);
    free(name);

    assert(stack_size(&s) == 2);

    stack_destroy(&s);
    PRINT_SUCCESS();
}

void test_stack_operations()
{
    test_stack_initialize();
    test_stack_can_push_item();
    test_stack_can_pop_item();
    test_stack_can_peek_item();
    test_stack_can_work_with_strings();
}
