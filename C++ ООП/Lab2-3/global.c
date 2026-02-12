#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void print_array_s(int si, int array[si][si]){
    for (int i=0;i<si;i++){
        for (int j=0;j<si;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void rev(int si, int (*array)[si]){
    int new[si][si];
    for (int i=0;i<si;i++){
        for (int j=0;j<si;j++){
            new[j][i]=(array)[i][j];
            
        }
    }
    for (int i=0;i<si;i++){
        for (int j=0;j<si;j++){
            array[i][si-j-1]=new[i][j];
            
        }
    }
}
void stat(){
    int array[9][9];
    int si=9;
    for (int i=0;i<si;i++){
        for (int j=0;j<si;j++){
            array[i][j]=(rand()%100);
        }
    }
    printf("Изначальный массив\n");
    print_array_s(si, array);

    rev(si,array);
    printf("Новый массив\n");
    print_array_s(si, array);


}


void print_array(int si, int** array){
    for (int i=0;i<si;i++){
        for (int j=0;j<si;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}
void free_array(int si, int*** array){
    for (int i=0;i<si;i++){
        free((*array)[i]);
    }
    free((*array));

}
void mod(int si, int ***array){
    int **array_e=(int**)malloc(sizeof(int*)*si);
    for (int i=0;i<si;i++){
        array_e[i]=malloc(sizeof(int)*si);
    }
    for (int i=0;i<si;i++){
        for(int j=0;j<si;j++){
            array_e[si-i-1][si-j-1]=(*array)[i][j];
        }
    }

    int **temp=(*array);
    (*array)=array_e;
    
    free_array(si,&temp);
    
}
void non_stat(){

    int si=11;
    int **array=(int**)malloc(sizeof(int*)*si);
    for (int i=0;i<si;i++){
        array[i]=malloc(sizeof(int)*si);
    }
    for (int i=0;i<si;i++){
        for(int j=0;j<si;j++){
            array[i][j]=rand()%100;
        }
    }
    printf("Изначальный массив\n");
    print_array(si,array);
    mod(si,&array);
    printf("\nНовый массив\n");
    print_array(si,array);
    free_array(si,&array);
}
void print_menu(){
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Работа со статическим массивом         |\n");
    printf("| (b) Работа с динамическим массивом         |\n");
    printf("|____________________________________________|\n");
}
