/*
 * =====================================================================================
 *
 *       Filename:  vector_tests.h
 *
 *    Description:  vector_tests head file 
 *
 *        Version:  1.0
 *        Created:  05/10/2019 10:53:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "common.h"
#include "../data-structure/vector.h"

void test_vector_can_get_item_at_index()
{
    vector v;
    vector_new(&v,sizeof(int),NULL);

    int i;
    for(i = 0; i < 3; i++)
    {
        vector_add(&v,&i);
    }

    assert(vector_size(&v) == 3);

    int value;
    for(i = 0; i < 3; i++)
    {
        vector_item_at(&v,i,&value);
        assert(value == i);
    }

    vector_destroy(&v);
    PRINT_SUCCESS();
}

void test_vector_can_grow()
{
    const int vector_initial_size = 4;

    vector v;
    vector_new(&v,sizeof(int),NULL);

    int i;
    for(i = 0; i < vector_initial_size + 2; i++)
    {
        vector_add(&v,&i);
    }

    int value;
    vector_item_at(&v,vector_initial_size,&value);
    assert(value == vector_initial_size);

    vector_destroy(&v);
    PRINT_SUCCESS();
}

void test_vector_string_free(void* data)
{
    free(*(char**)data);
}

void test_vector_can_store_strings()
{
    const char* names[] = {"David","Muto","Tester"};

    vector v;
    vector_new(&v,sizeof(char*),test_vector_string_free);

    int i;
    char* name;

    for(i = 0; i < 3; i++)
    {
        name = strdup(names[i]);
        vector_add(&v,&name);
    }

    for(i = 0; i < 3; i++)
    {
        vector_item_at(&v,i,&name);
        assert(strcmp(name,names[i]) == 0);
    }

    vector_destroy(&v);
    PRINT_SUCCESS();
}

void test_vector_can_insert_values()
{
    int initLength = 10;

    vector v;
    vector_new(&v,sizeof(int),NULL);

    int i;
    for(i = 0; i < initLength; i++)
    {
        vector_add(&v,&i);
    }

    int value = 1000;
    vector_insert_at(&v,0,&value);

    value = 500;
    vector_insert_at(&v,5,&value);

    value = 0;
    vector_insert_at(&v,v.logicalLength,&value);

    vector_item_at(&v,0,&value);
    assert(value == 1000);

    vector_item_at(&v,5,&value);
    assert(value == 500);

    vector_item_at(&v,v.logicalLength - 1,&value);
    assert(value == 0);

    vector_destroy(&v);
    PRINT_SUCCESS();
}

void test_vector_can_remove_values()
{
    int initLength = 10;

    vector v;
    vector_new(&v,sizeof(int),NULL);

    int i;
    for(i = 0; i < initLength; i++)
    {
        vector_add(&v,&i);
    }

    int value;
    vector_remove_at(&v,0);
    vector_item_at(&v,0,&value);
    assert(vector_size(&v) == initLength - 1);
    assert(value == 1);

    vector_remove_at(&v,vector_size(&v) - 1);
    vector_item_at(&v,vector_size(&v) - 1,&value);
    assert(vector_size(&v) == initLength - 2);
    assert(value == 8);

    vector_remove_at(&v,4);
    vector_item_at(&v,4,&value);
    assert(vector_size(&v) == initLength - 3);
    assert(value == 6);

    vector_destroy(&v);
    PRINT_SUCCESS();
}

void test_vector_operations()
{
    test_vector_can_get_item_at_index();
    test_vector_can_grow();
    test_vector_can_store_strings();
    test_vector_can_insert_values();
    test_vector_can_remove_values();
}
