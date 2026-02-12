#include <stdio.h>
#include <stdlib.h>
#include "matrix1.h"
#include <ctype.h>


void clearBUF() {
    scanf("%*s[^\n]");
}
int check_zero(matrix* M){
    for (int i=0;i<M->lines;i++){
        if(M->l[i].columns!=0){
            return 1;
        }
    }
    return 0;
}
int check_int_input(int *i){
    int k=scanf("%d",&(*i));
    if(k==(-1)){
        return 0;
    }
    while(k==0){
    	clearBUF();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        k=scanf("%d",&(*i));
        if(k==(-1)){
            return 0;
        }
    }
    return 1;
}
int isNumber(char *input) {
    for (int i = 0; input[i] != '\0'; i++)
        if (isalpha(input[i]))
            return 0;
    return 1;
}
char input_and_check(){

    char s;
    int k;
    k=scanf("%c",&s);
    
    if(k!=(-1)){
    clearBUF();
    
    while (isNumber(&s)==1){
        
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        k=scanf("%c", &s);
        clearBUF();
        if(k==(-1)){
            break;
        }
    }
    }
    
    if (k==(-1)) {
        s = 'f';
        }else if (s == 'f') { s = 'h'; }
    
    
    return s;
}
int reverseDigits(int num) {
    int result = 0;
    while (num != 0) {
        result = result * 10 + num % 10;
        num /= 10;
    }
    return result;
}
int safe_matrix(matrix* M,matrix* L) {
    printf("Введите количество строк матрицы: ");
    if(0==check_int_input(&(M->lines))){
        return 0;
    }
    
    M->l=NULL;
    M->l = malloc(sizeof(line) * (M->lines));
    if(!M->l){
        return 0;
    }
    L->lines=0;

    for (int i = 0; i < M->lines; i++) {
        printf("Введите кол-во элементов в строке %d: ",i+1);
        if(0==check_int_input(&(M->l[i].columns))){
            return 0;
        }
        (M->l[i]).el=NULL;
        ((M->l[i]).el) = malloc(sizeof(int) * (M->l[i].columns));
        if(!(M->l[i]).el){
            for (int k=0;k<i;k++){
                free((M->l[i]).el);
            }
            free(M->l);
            return 0;
        }
        for (int j = 0; j < M->l[i].columns; j++) {
            if(0==check_int_input(&((M->l[i]).el[j]))){
                for (int k=0;k<=i;k++){
                free((M->l[i]).el);
                }
                free(M->l);
                return 0;
            }
            
        }
    }
    clearBUF();
    return 1;
}




void print_matrix(matrix* M) {
    
    for (int i = 0; i < M->lines; i++) {
        for (int j = 0; j < M->l[i].columns; j++) {
            printf("%d ", (((M->l[i]).el)[j]));
        }
        printf("\n");
    }

}

void change_and_safe(matrix* M,matrix* L) {
    (L->lines)=(M->lines);
    
    L->l=NULL;
    L->l = malloc(sizeof(line) * (L->lines));
    if(!L->l){
        return 0;
    }
    for (int i = 0; i < M->lines; i++) {
        (L->l[i].columns)=(M->l[i].columns);
        L->l[i].el=NULL;
        L->l[i].el=malloc(sizeof(int)*(L->l[i].columns));
        if(!L->l[i].el){
            for (int k=0;k<i;k++){
                free((L->l[i]).el);
            }
            free(L->l);
            return 0;
        }
        for (int j = 0; j < M->l[i].columns; j++) {
            L->l[i].el[j] = reverseDigits(M->l[i].el[j]);
        }
    }
}

void matrix_free(matrix* M) {
    for (int i = 0; i < M->lines; i++) {
        free((M->l[i].el));

    }
    free(M->l);
    free(M);
}
void print_menu() {
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("|                                            |\n");
    printf("| (a) Создать матрицу                        |\n");
    printf("| (b) Отредактировать и записать             |\n");
    printf("| (с) Вывод матриц                           |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");

}
