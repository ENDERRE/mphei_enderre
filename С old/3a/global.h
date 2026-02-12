#ifndef LIB_GLOBAL
#define LIB_GLOBAL

void clearbuf();
int sorter(const void *x,const void *y);
int check_int_input_file(int *i,FILE* file);
int check_int_input(int *i);
int isNumber(char *input);
int input_and_check(char *s,int i);



#endif