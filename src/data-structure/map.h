/*
 * =====================================================================================
 *
 *       Filename:  map.h
 *
 *    Description:  map head file 
 *
 *        Version:  1.0
 *        Created:  05/09/2019 02:45:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __CDS_MAP_H
#define __CDS_MAP_H 

#include <stdbool.h>
#include "common.h"

typedef struct _mapNode {
    char* key;
    void* value;
    struct _mapNode* left;
    struct _mapNode* right;
}mapNode;

typedef struct {
    int logicalLength;
    int elementSize;
    mapNode* root;
    freeFunction freeFn;
}map;

void map_new(map* map,int elementSize,freeFunction freeFn);
void map_destroy(map* map);
bool map_constains_key(map* map,const char* key);
void map_set(map* map,const char* key,void* element);
void map_get(map* map,const char* key,void* element);
int map_size(map* map);

#endif
