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

int main(){
    table* T=NULL;
    int p;
    printf("Размер таблицы: ");

    if(check_int_input(&p)==0){
        return 0;
    }
    scanf("%*c");
    add_table(&T,p);

    int gg=0;
    char l;
    
    int p1=0;

    enum op p2=none;
    int k;
    do{
        print_do();

        if(p1==1){
            if(print_el(T)==0){
                printf("Ключь не найден\n");
            }
            p1=0;
        }
        if(p2==error){
            printf("Ошибка вывода в файл\n");
            p2=none;
        }else if(p2==pr_t){
            print_table(T);
            p2=none;
        }else if(p2==pr_g){
            k=0;
            print_group(T,&k);
            p2=none;
        }

        printf("Ввод: ");
        if(input_and_check(&l,1)==0) {
            free_table(T);
            return 0;
        }
        scanf("%*c");

        switch(l){
            case 'a':
                import(&T);
                scanf("%*c");
                break;
            case 'b':
                int hh=output_1();
                
                if(hh==2){
                    p1=1;
                }else if(hh==3){

                    int key;
                    printf("Введите ключ: ");
                    check_int_input(&key);
                    char* txt;
                    txt=readline("Введите текст: ");
                    if(import_key(&T,key,txt)==0){
                        printf("Ключ не добавлен\n");
                        free(txt);
                    }
                    
                }else if(hh==4){
                    int key;
                    printf("Введите ключ:");
                    check_int_input(&key);
                    if(erase(T,key)==0) printf("Элемента нет\n");

                }else if(hh==0){
                free_table(T);
                return 0;
                }
                scanf("%*c");
                break;
            case 'c':
                p2=output(T);
                scanf("%*c");
                break;
            default:
                break;
        }

    }while(gg!=1);
    free_table(T);
    return 1;

}