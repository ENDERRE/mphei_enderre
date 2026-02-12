#include <stdio.h>
#include <stdlib.h>
#include "matrix1.h"
#include <ctype.h>



int main() {
    matrix* M = NULL;
    M=malloc(sizeof(matrix));
    if(!M){
        return 0;
    }
    matrix* L=NULL;
    L=malloc(sizeof(matrix));
    if(!L){
        free(M);
        return 0;
    }
    M->lines=0;
    L->lines=0;
        char s;
        int flag = 0;
        int pp = 0;
        int wr=0;

        do {
            print_menu();
            
            if (pp == 1) {
                if(M->lines!=0){
                    if(check_zero(M)==1){
                        printf("Матрица 1\n");
                        print_matrix(M);
                    }
                }
                if(L->lines!=0){
                    if(check_zero(L)==1){
                        printf("Матрица 2\n");
                        print_matrix(L);
                    }
                }
                pp = 0;
            }
            if(wr==1){
                printf("Ошибка ввода\n");
                wr=0;
            }
            printf("Ввод: ");
            s = input_and_check();            
            

            switch (s) {
            case 'a':
                safe_matrix(M,L);
                break;

            case 'b':

                change_and_safe(M,L);
                break;

            case 'c':
                pp = 1;
                break;


            case 'f':
                flag = 1;
                break;
            default:
                wr=1;
                break;

            

            }
            

        } while (flag == 0);
}
