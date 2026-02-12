#ifndef LIB_TABLE_G
#define LIB_TABLE_G
#include "table_s.h"

int delete_double(table* T);
int check_double_key(table *T,int key);
int search_key(table* T,int key,int *i);
int erase(table* T,int key);


#endif