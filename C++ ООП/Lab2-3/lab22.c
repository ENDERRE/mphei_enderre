#include <stdio.h>
#include <stdlib.h>

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
int main(){

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
}