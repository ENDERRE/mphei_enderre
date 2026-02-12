#ifndef LIB_TABLE_I
#define LIB_TABLE_I

#include "table_s.h"


int add_table(table** T,int p);
int get_char(FILE* file,char *s[]);
int import_from_txt(table** T,char* name);
int import_from_std(table* T);
int import_key(table **T,int key,char* txt);



#endif