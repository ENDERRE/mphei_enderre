#ifndef LIB_MATRIX
#define LIB_MATRIX
 
#include "game_l.h"

void chek_enter(char *c,int*f);
int cube_check(int *c);
int cube_do(puzzle *cube);
int getRandomNumber(int min, int max); 
int num_cube(puzzle *cube );

void print_start();
#endif