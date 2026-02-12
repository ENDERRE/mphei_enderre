
#ifndef LIB_MATRIX
#define LIB_MATRIX

typedef struct {
    int columns;
    int* el;
}line;

typedef struct {
    int lines;
    line* l;
} matrix;

void clearBUF() ;
int check_zero(matrix* M);
int check_int_input(int *i);
int isNumber(char *input);
char input_and_check();
int reverseDigits(int num) ;
int safe_matrix(matrix* M, matrix* L) ;
void print_matrix(matrix* M) ;
void change_and_safe(matrix* M,matrix* L) ;
void matrix_free(matrix* M) ;
void print_menu();

#endif