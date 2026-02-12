#ifndef LIB_I_OUT
#define LIB_I_OUT
#include "table_s.h"

int import_from_std_arg(table* T, char *argv,int argc);
int import_from_std(table* T);
int import_from_bin(table* T,char *name);
int push_to_bin(table* T,char* name);


#endif