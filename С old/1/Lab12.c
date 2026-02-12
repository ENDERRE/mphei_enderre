#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <readline/readline.h>

#include "matrix2.h"

  

int main() {
    char s;
    char *name=NULL;
    name=NULL;
    name=malloc(sizeof(char));
    if(!name) return 0;
    int flag=0;
    int pp=0;

    do{
        print_menu();
        clearBUF();
        if(pp==1){
            read_the_file(name);
            pp=0;
        }
        printf("Ввод: ");
        if(scanf("%c",&s)==EOF){s='f';
        }else if(s=='f'){s='h';}


        switch(s){
            case 'a':
                name=readline("Введите имя файла: ");
                break;

            case 'b':
                write_to_file(name);
                break;
            
            case 'c':
                edit_file(name);
                break;
            
            case 'd':
                pp=1;
                break;
            
            case 'f':
                flag=1;
                break;
            default:
                break;
        
        
        }
        clearBUF();
        

    }while(flag==0);
    free(name);




}
