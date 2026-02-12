#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>
#include "global.h"


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

void print_do(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Добавить вершину                       |\n");
    printf("| (b) Добавить дорогу                        |\n");
    printf("| (c) Удалить вершину                        |\n");
    printf("| (d) Удалить дорогу                         |\n");
    printf("| (e) Сменить тип                            |\n");
    printf("| (f) Вывод std                              |\n");
    printf("| (g) Вывод граф                             |\n");
    printf("| (h) Поиск Бельман                          |\n");
    printf("| (i) Поиск Уоршалл                          |\n");
    printf("| (j) Поиск в ширину                         |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}