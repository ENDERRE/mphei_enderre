#include <stdio.h>
#include <stdlib.h>
void print_array(int si, int array[si][si]){
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
int main(){
    int array[9][9];
    int si=9;
    for (int i=0;i<si;i++){
        for (int j=0;j<si;j++){
            array[i][j]=(rand()%100);
        }
    }
    printf("Изначальный массив\n");
    print_array(si, array);

    rev(si,array);
    printf("Новый массив\n");
    print_array(si, array);


}