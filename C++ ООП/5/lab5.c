#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#include <readline/readline.h>


#include "global.h"
#include "table_s.h"
#include "table_i_out.h"
#include "table.h"


int main(int argc, char  **argv){

    table* T=NULL;
    int p;
    if (argc!=1){
        p=argc;
    }else{
        printf("Размер таблицы: ");
        if(check_int_input(&p)==0){
            return 0;
        }
    }
    
    if(add_table(&T,p)==0) return 0;
    char l;
    enum se k=none;
    char *name=NULL;
   
    int key,ver,pr=1;
    do{
        print_do();
        
        if(k==pr_key){
            if(0==search_1_el_key(T,key)){
                printf("\nИнформайия не найдена\n");
            }
            k=none;
        }else if(k==pr_ver){
            search_1_el_ver(T,key,ver);
            k=none;
        }
        switch (k){
        case pr_key:
            pr=search_1_el_key(T,key);
            break;
        case pr_ver:
            pr=search_1_el_ver(T,key,ver);
            break;
        case del_key:
            pr=delete_1_key(T,key);
            break;
        case del_ver:
            pr=delete_1_ver(T,key,ver);
            break;   
        case error:
            return 0;
            break;   
        default:
            break;
        }
        if(pr==0){
            printf("\nИнформайия не найдена\n");
            pr=1;
        }
        if(argc!=1){
            l='a';
        }else{
            printf("Ввод: ");
            if(input_and_check(&l,"abcde")==0) {
                free_table(T);
                free(T);
                return 0;
            }
        }

        

        scanf("%*c");

        switch(l){
            case 'a':
            if(argc!=1){
                import_from_std_arg(T,*argv,argc);
                argc=1;
            }else{
                import_from_std(T);
            }
                
                break;
            case 'b':
                
                name=readline("Введите имя файла: ");
                if(import_from_bin(T,name)==0) {
                    return 0;
                }
                free(name);
                break;
            case 'c':
                
                name=readline("Введите имя файла: ");
                if(push_to_bin(T,name)==0){
                    return 0;
                } 
                free(name);
                break;
            case 'd':
                if((k=search_and_delete(T))==error) return 0;
                if(k!=none){
                    printf("Введтьк клюсь: ");
                    check_int_input(&key);
                    if(k==pr_ver || k==del_ver){
                        printf("Введите внрсию: ");
                        check_int_input(&ver);
                    }
                }
                break;
            case 'e':
                print_table(T);
                break;

        }


    }while(1);
    free_table(T);
    free(T);
}