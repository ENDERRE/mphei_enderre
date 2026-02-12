
#ifndef LIB_GLOBAL
#define LIB_GLOBAL
#include "game_l.h"

void undo(vectr* VV);
int MAX(int a,int b);
int MIN(int a,int b);
void cube_free(puzzle*cube);
void clearbuf();
int check_int_input();
int check_cube_int_input(int *i,puzzle* cube,int k,int h);
void print_cube(puzzle *cube );
void swap_cube(puzzle* cube,pos tmp);
void print_do();
int isNumber(char *input);
int input_and_check(char *s);
int cube_switch_vec(puzzle* cube,vectr *VV);
int check_win(puzzle*cube);
int go_vector(puzzle* cube);
int go_struct(puzzle* cube);



#endif