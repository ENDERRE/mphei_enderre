#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>

#include "table_s.h"
#include "table_i.h"
#include "table_g.h"
#include "table_out.h"
#include "global.h"
#include "tablets.h"
#include "table_d.h"


enum op output(table* T){
    print_output();
    char l;

    printf("Ввод: ");
    input_and_check(&l,1);

    switch(l){
        case 'a':
            char *name=NULL;

            name=readline("Введите имя файла: ");
            if(push_to_file(T,name)==0) {
                free(name);
                printf("Ошибка при создании файла: %s\n", strerror(errno));
                return none;
            }
            free(name);
            return error;
            
        case 'b':

            return pr_t;
            
        case 'c':

            return pr_g;
            
    }
    return none;
}
int output_1(){

    char l;


    print_out_1();


    printf("Ввод: ");
    if(input_and_check(&l,1)==0) return 0;

    switch(l){
        case 'a':
        
            
            return 2;
            break;
        case 'b':
            
            return 3;
        break;
            case 'c':
            return 4;
    }
    return 1;
}
int import(table** T){

    char l;


    print_import();


    printf("Ввод: ");
    input_and_check(&l,2);

    switch(l){
        case 'a':
            if(0==import_from_std(*T)) return 0;
            scanf("%*c");
            break;
        case 'b':
            char *name=NULL;
            name=readline("Введите имя файла: ");
            if(import_from_txt(T,name)==0) {
                free(name);
                return 0;
            }
            free(name);
            break;

        default:
            break;
    }



    return 1;
}