#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "game.h"
#include "game_l.h"
#include "game_global.h"


#include "Vector/Vec.h"
#include "Stack/Stack.h"

int main(){
    srand(time(0));
    char En;
    printf("Нажмите Enter чтобы начать:");
    int f=scanf("%c",&En);
    if(En!='\n' && f!=(-1)){
        clearbuf();
    }
    chek_enter(&En,&f);
    if(f!=(-1)){
        char a;
        print_start();
        printf("Ввод: ");
        if(input_and_check(&a)==0){
            return 0;
        }
        
            int size;
            printf("Введите сложность: ");
            check_int_input(&size);
            cube_check(&size);
            puzzle* cube =NULL;
            cube=malloc(sizeof(puzzle));
            if(!cube){
                return 0;
            }
            cube->si=size;
            cube_do(cube);
            
            num_cube(cube);

            print_cube(cube);

            switch (a){
                case 'a':

                   if(go_vector(cube)==0){
                    cube_free(cube);
                    return 0;
                   }
                    break;
                case 'b':
                    
                    if(go_struct(cube)==0){
                        cube_free(cube);
                        return 0;
                    }
                default:
                    break;
            }
        cube_free(cube);
        

    

       

    
    }

}