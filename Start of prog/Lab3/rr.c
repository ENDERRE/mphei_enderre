#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(){
    char w;
    int flag=0,mathp=0;
    
    

    do{
        system("cls");
        print_menu();
        if(mathp==1){
            
            math();
            mathp=0;
            
        }
        


    printf("Что мне делать: ");
    if(scanf("%c",&w)==EOF){w='f';
        }else if (w=='f'){
            w='p';
        }      
    fflush(stdin);
    while(w!='f' && w!='\n'){
        system("cls");
        print_menu();
        printf("я не могу распознать такое\n");
        printf("Введите один из вариантов: ");
        if(scanf("%c",&w)==EOF){w='f';
        }else if (w=='f'){
            w='p';
        }      
        fflush(stdin);
    }
    switch (w)
    {
        case 'f':
            flag=1; break;

        default:
            mathp=1; break;
        }

    }while(flag==0);
   
    return 0;
}
