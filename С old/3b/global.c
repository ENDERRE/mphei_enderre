#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>


#include "global.h"
#include "table_s.h"
#include "table_i_out.h"
#include "table.h"


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


    if(k==(-1)) return 0;
    
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
        if(k==(-1)) return 0;
        
        if(k==0) clearbuf();

    }
    return 1;
}

void print_do(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Ввод таблицы std                       |\n");
    printf("| (b) Ввод из бинаного файла                 |\n");
    printf("| (c) Вывод в бинарный файл                  |\n");
    printf("| (d) Удаление и вывод элементов             |\n");
    printf("| (e) Вывод таблицы                          |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}
void print_import(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Вывод по ключу                         |\n");
    printf("| (b) Вывод по ключу и релизу                |\n");
    printf("| (c) Удаление по ключу                      |\n");
    printf("| (d) Удаление по ключу и релизу             |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}