/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main source file 
 *
 *        Version:  1.0
 *        Created:  05/09/2019 11:02:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "tests/tests.h"

int main (int argc,char* argv[])
{
    test_vector_operations();
    test_list_operations();
    test_stack_operations();
    test_queue_operations();
    test_map_operations();

    printf("All tests passed.\n");

    return 0;
}
