#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


 #include "game_global.h"
 #include "game_l.h"
#include "Vector/Vec.h"
#include "Stack/Stack.h"
void undo(vectr* VV){
    for (int i=0;i<VV->g-1;i++){
        VV->vec[i]=VV->vec[i+1];
    }
}
int MAX(int a, int b){
    if(a>b){
        return a;

    }else{
        return b;
    }

}
int MIN(int a,int b){
    if(a<b){
        return a;

    }else{
        return b;
    }
}
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


int check_cube_int_input(int *i,puzzle* cube,int k,int h){

    if((k)==(-1)){
        return 0;
    }

    while((k)==0 || (*i)<0 || (*i)>(cube->si)){

        if(h==1){
            printf("Ошибка ввода row\n");
        }else{
            printf("Ошибка ввода col\n");
        }
        
        printf("Ввод: ");
        (k)=scanf("%d",&(*i));
        if(k==0){
            clearbuf();
        }
        if((k)==(-1)){
            return 0;
        }
    }
    return 1;
}

void print_cube(puzzle *cube ){
    printf("\n");
    int size=cube->si;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if(cube->fir[i][j]==0){
                printf("  ");
            }else{
                printf("%d ",cube->fir[i][j]);
            }
        }
        printf("\n");
    }
}

 void swap_cube(puzzle* cube,pos tmp){
    cube->fir[cube->empt.row][cube->empt.col] = cube->fir[tmp.row][tmp.col];
    cube->fir[tmp.row][tmp.col]=0;
    cube->empt=tmp;

}




void print_do(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Сделать ход                            |\n");
    printf("| (b) Отменить ход                           |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}

int isNumber(char *input) {
    for (int i = 0; input[i] != '\0'; i++)
        if (isalpha(input[i]))
            return 0;
    return 1;
}

int input_and_check(char *s){
    int k;
    k=scanf("%c", s);
    char ff;
    if((*s)!='\n') scanf("%c",&ff);
    if(k!=(-1)){
    int c=1;

    if((*s)=='a' || (*s)== 'b'){
        c=0;
    }
    while (isNumber(&(*s))==1 || c==1){
        if(k == 0) clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        
        k=scanf("%c", s);
        if((*s)!='\n') scanf("%c",&ff);
        if((*s)=='a' || (*s)== 'b'){
        c=0;
        }else{
            c=1;
        }
        if(k==(-1)){
            return 0;
        }
    }
    }
    
    if (k==(-1)) {
        return 0;
    }
    return 1;
    
    
}
int cube_switch_vec(puzzle* cube,vectr *VV){

    pos swap;
    int k1=1,k2=1;
    int k=0,f=0;
    do{
        if(f==1) printf("Ошибка ввода\n");
        printf("Введите номер клетки: ");
        k1=scanf("%d",&(swap.row));
        k2=scanf("%d",&(swap.col));
        if(k1==0 || k2==0){
                clearbuf();
            }
        if(check_cube_int_input(&(swap.row),cube,k1,1)==0){
            return 0;
        }
        if(check_cube_int_input(&(swap.col),cube,k2,2)==0){
            return 0;
        }
        
        if(cube->empt.row==swap.row-1){
            while( MAX(cube->empt.col,swap.col-1)- MIN(cube->empt.col,swap.col-1)!=1 ){


                if(check_cube_int_input(&(swap.col),cube,0,2)==0){
                    return 0;
                }
                    

            }
            k=1;
        }else if(cube->empt.col==swap.col-1){
            while( MAX(cube->empt.row,swap.row-1)- MIN(cube->empt.row,swap.row-1)!=1 ){


                if(check_cube_int_input(&(swap.row),cube,0,1)==0){
                    return 0;
                }
                    

            }
            k=1;
        }
        f=1;
    }while(k==0);
    
    swap.row-=1;
    swap.col-=1;
    
    push(VV,cube);
    swap_cube(cube,swap);

    return 1;
}
int check_win(puzzle*cube){
    int num=1;
    for (int i=0;i<cube->si;i++){
        for (int j=0;j<cube->si;j++){
            if(cube->si==(i+1) && cube->si==(j+1) && cube->fir[i][j]==0){
                printf("\n");
                printf("ПОБЕДА!!!!!");
                return 1;

            }
            if(cube->fir[i][j]!=num){
                return 0;
            }
            num++;
        }
    }
    return 1;
}

int go_vector(puzzle* cube){
    printf("Сколько запоминаем: ");
    vectr *VV=NULL;
    if(add_vectr(&VV)==0) return 0;
    
  
    char l;
    scanf("%c",&l);
    int gg=0,k=0;
    do{
        if(check_win(cube)!=1){
        printf("\n\n");
        
        print_do();
        if(k==1){
            printf("Предыдушего хода нету");
            k=0;
        }
        print_cube(cube);
        
        printf("Ввод: ");
        
        if(input_and_check(&l)==0){
            free_vectr(&VV);
            return 0;
        }
        

        }else{
            l='f';
        }
        switch(l){
            case 'a':
                cube_switch_vec(cube,VV);
                
                scanf("%*c");
                break;
            case 'b':
                pos* tt=NULL;
                tt=malloc(sizeof(pos));
                if(!tt){
                    free_vectr(&VV);
                    return 0;
                }
                if(pop(tt,VV)==0){
                    k=1;
                }else{
                    swap_cube(cube,*tt);
                    
                }
                free(tt);
                
                break;
            case 'f':
                gg=1;
                break;
            default:

                break;
        }

    }while(gg!=1);
    free_vectr(&VV);
    return 1;

}

int go_struct(puzzle* cube){
    stack *tmp=NULL;
    if(add_stack(&tmp)==0){
        return 0;
    }
    
    scanf("%*c");
    tmp->head=NULL;
    char l;
    int gg=0;
    int ff=0;
    do{
        if(check_win(cube)!=1){
        printf("\n\n");

        print_do();
        if(ff==1){
            printf("Предыдушего хода нету");
            ff=0;
        }
        print_cube(cube);
        printf("Ввод: ");
        
        if (input_and_check(&l)==0){
            free_stack(tmp);
            return 0;
        }
        }else{
            l='f';
        }


        switch(l){
            case 'a':
               
                pos swap;
                int k1=1,k2=1;
                int k=0,f=0;
                do{
                    if(f==1) printf("Ошибка ввода\n");
                    printf("Введите номер клетки: ");
                    k1=scanf("%d",&(swap.row));
                    k2=scanf("%d",&(swap.col));
                    if(k1==0 || k2==0){
                            clearbuf();
                        }
                    if(check_cube_int_input(&(swap.row),cube,k1,1)==0){
                        return 0;
                    }
                    if(check_cube_int_input(&(swap.col),cube,k2,2)==0){
                        return 0;
                    }
                    
                    if(cube->empt.row==swap.row-1){
                        while( MAX(cube->empt.col,swap.col-1)- MIN(cube->empt.col,swap.col-1)!=1 ){


                            if(check_cube_int_input(&(swap.col),cube,0,2)==0){
                                return 0;
                            }
                                

                        }
                        k=1;
                    }else if(cube->empt.col==swap.col-1){
                        while( MAX(cube->empt.row,swap.row-1)- MIN(cube->empt.row,swap.row-1)!=1 ){


                            if(check_cube_int_input(&(swap.row),cube,0,1)==0){
                                return 0;
                            }
                                

                        }
                        k=1;
                    }
                    f=1;
                }while(k==0);

                swap.row-=1;
                swap.col-=1; 
                if(cube_switch_stack(cube,tmp)==0){
                    k=1;
                }
                swap_cube(cube,swap);
                scanf("%*c");
                break;
            case 'b':
                el *tt=NULL;
                if(cube_undo_stack(tmp,&tt)==0){
                    ff=1;
                }else{
                    swap_cube(cube,tt->p);
                    free(tt);
                }
                
                break;
            case 'f':
                gg=1;
                break;
            default:

                break;
        }

    }while(gg!=1);

    free_stack(tmp);
    return 1;
    
}
