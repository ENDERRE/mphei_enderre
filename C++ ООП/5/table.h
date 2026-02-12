#ifndef LIB_TABLE
#define LIB_TABLE
#include "table_s.h"

int add_table(table** T,int p);
void free_table(table* T);
void print_table(table*T);
int hash(int key,int size);
int search_double_info_list(node* Node,int info);
int add_info(node* NODE,int info);
int search_double_key(int key,keyspace* temp);
int add_el(table* T,int key,int info);
int search_1_el_key(table* T,int key);
int search_1_el_ver(table* T,int key,int ver);
enum se search_and_delete(table* T);
int delete_1_key(table* T,int key);
int delete_1_ver(table* T,int key,int ver);


#endif