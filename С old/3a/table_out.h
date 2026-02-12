#ifndef LIB_TABLE_OUT
#define LIB_TABLE_OUT

#include "table_s.h"


void print_table(table* T);
int print_el(table* T);
void print_group(table *T,int *k);
void free_table(table* T);

int push_to_file(table* T,char *name);


#endif