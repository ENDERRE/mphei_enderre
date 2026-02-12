#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>


#include "matrix2.h"


void clearBUF(){
    scanf("%*s[^\n]");
}
int check_int_input(int *i){
    int k=scanf("%d",i);
    if(k==EOF) return 0;
    while(k==0){
    	clearBUF();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        k=scanf("%d",i);
        if(k==EOF) return 0;

    }
    return 1;
}
int write_to_file(char *name){
    int n,m,gg;
    FILE* file;
    file=fopen(name,"wb");
    if (file == NULL) {
        printf("Ошибка при создании файла: %s\n", strerror(errno));
        return 0;
    }
    printf("Введите кол-во строк: ");

    if(check_int_input(&n)==0) return 0;
    fwrite(&n,1,sizeof(n),file);
    for (int i=0;i<n;i++){
        printf("кол-во элементов в строке: ");
        scanf("%d",&m);
        fwrite(&m,1,sizeof(i),file);
        for(int j=0;j<m;j++){

            if(check_int_input(&gg)==0) return 0;

            fwrite(&gg,1,sizeof(gg),file);
            
        }
    }
    
    fclose(file);
    return 1;

}
int read_the_file(char *name){
    int n,m,gg;
    FILE* file;
    file=fopen(name,"rb");
    if (file == NULL) {
        printf("Ошибка при открытии файла: %s\n", strerror(errno));
        return 0;
    }
    
    fread(&n,1,sizeof(int),file);
    
    for (int i=0;i<n;i++){
        fread(&m,1,sizeof(int),file);
        printf("\n");
        for (int j=0;j<m;j++){
            fread(&gg,1,sizeof(int),file);
            printf("%d ",gg);
        }
    }
    printf("\n");
    
    fclose(file);
    return 1;

}
int reverseDigits(int num) {
    int result = 0;
    while (num != 0) {
        result = result * 10 + num % 10;
        num /= 10;
    }
    return result;

}
int edit_file(char *name){
    FILE* file;
    file = fopen(name,"r+b");
    if (file == NULL) {
        printf("Ошибка при открытии файла: %s\n", strerror(errno));
        return 0;
    }
    int n,m,gg;
    fread(&n,1,sizeof(int),file);
    for (int i=0;i<n;i++){
        fread(&m,sizeof(int),1,file);
        for (int j=0;j<m;j++){
            fread(&gg,1,sizeof(int),file);
            gg=reverseDigits(gg);
            
            fseek(file,(-1)*sizeof(int),SEEK_CUR);
            fwrite(&gg,1,sizeof(int),file);
            fseek(file,0,SEEK_CUR);
            
        }
    }
    fclose(file);
    return 1;
}
void print_menu(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("|                                            |\n");
    printf("| (a) Ввод имени файла для работы            |\n");
    printf("| (b) Записать матрицу в файл                |\n");
    printf("| (c) Отредактировать матрицу                |\n");
    printf("| (d) Вывод матрицы                          |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");

}
