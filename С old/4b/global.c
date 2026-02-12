


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>
#include <time.h>
#include"global.h"


void clearbuf(){
    scanf("%*s[^\n]");
}

int check_int_input(int *i){
  

    int k=scanf("%d",&(*i));
    if(k==(EOF)){
        return 0;
    }
    while(k==0){
    	clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        k=scanf("%d",&(*i));
        if(k==EOF){
            return 0;
        }
    }
    return 1;
}

int input_and_check(char *s,char str[]){
    int k,c=1;
    char *ss=NULL;
    k=scanf("%c", s);


    if(k==(EOF)) return 0;
    
    if(k==0) clearbuf();

    ss=strchr(str,*s);
    if(ss!=NULL){
        c=0;
        ss=NULL;
    }
    while (!isalpha(*s) || c==1){
        if(k == 0) clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        
        k=scanf("%s", s);

        ss=strchr(str,*s);
        if(ss!=NULL){
            c=0;
           
        }else{
            c=1;
            
        }
        ss=NULL;
        if(k==(EOF)) return 0;
        
        if(k==0) clearbuf();

    }
    return 1;
}


int check_int_input_file(int *i,FILE* file){
  

    int k=fscanf(file,"%d",&(*i));
    if(k==(EOF)){
        return EOF;
    }
    while(k==0){
    	clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        k=fscanf(file,"%d",&(*i));
        if(k==EOF){
            return EOF;
        }
    }
    return 1;
}

void print_do(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Ввод таблицы std                       |\n");
    printf("| (b) Ввод из текстового файла               |\n");
    printf("| (c) Вывод в текстовый файл                 |\n");
    printf("| (d) Удаление элемента                      |\n");
    printf("| (e) Поиск элемента                         |\n");
    printf("| (f) Поиск элемента специальный             |\n");
    printf("| (g) Вывод в std                            |\n");
    printf("| (h) Вывод графикой                         |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}
