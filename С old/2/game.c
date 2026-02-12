#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "game.h"
#include "game_l.h"
#include "game_global.h"


#include "Vector/Vec.h"
#include "Stack/Stack.h"



void cube_free(puzzle*cube){
    for(int i=0;i<cube->si;i++){
        free(cube->fir[i]);
    }
    free(cube->fir);
    free(cube);
}
void chek_enter(char *c,int*f){
    if((*f)!=(-1)){
        while ((*c)!='\n' && (*f)!=(-1)){
                printf("Это не Enter\n");
                printf("Нажмите Enter чтобы начать:");
                (*f)=scanf("%c",&(*c));
                if((*c)!='\n' && (*f)!=(-1)){
                    clearbuf();
                }
        }
    }
}

int cube_check(int *c){
    while((*c)<=0 || (*c)>=10){
        printf("Это не сложность: ");
        printf("Введите сложность: ");  
        if(check_int_input(&(*c))==0){
            return 0;
        }
    }
    return 1;
}
int cube_do(puzzle *cube){
    int size=cube->si;
    cube->fir=NULL;
    cube->fir=malloc(size*sizeof(int*));
    if(!cube->fir){
        return 0;
    }
    for(int i=0;i<size;i++){
        cube->fir[i]=NULL;
        cube->fir[i]=malloc(sizeof(int)*size);
        if(!cube->fir[i]){
            free(cube->fir);
            return 0;
        }
    }
    return 1;

}
int getRandomNumber(int min, int max) {
    return (min + (rand() % (max - min + 1)));
}


int num_cube(puzzle *cube ){
    
    if(cube->si>2){
        int k=cube->si;
        k*=k;
        int *num=NULL;
        num=malloc(sizeof(int)*k);
        if(!num){
            return 0;
        }
        for (int i=0;i<k;i++){
            num[i]=i;
        }     
        int in;
        int size=cube->si;
        for (int i=0;i<size;i++){

            
            for (int j=0;j<size;j++){
                in=getRandomNumber(1,k);
                cube->fir[i][j]=num[in-1];
                k-=1;
                if((num[in-1])==0){
                    cube->empt.row=i;
                    cube->empt.col=j;
                }
                for(int f=in-1;f<k;f++){
                    num[f]=num[f+1];
                }
                
            }
        }
        free(num);

        
    }else{
        cube->empt.row=0;
        cube->empt.col=0;

        cube->fir[0][0]=0;
        cube->fir[0][1]=1;
        cube->fir[1][1]=2;
        cube->fir[1][0]=3;
    }
    return 1;
}

void print_start(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Как звпоминать ходы                        |\n");
    printf("| (a) С помошью вектора                      |\n");
    printf("| (b) С помошью структур                     |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}








