#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>
#include <time.h>

#include"global.h"
#include "graph_s.h"
#include "graph.h"



 

int main(){
    char* add=NULL;
    graph* G=NULL;
    char l;
    int val,k;
    int pos;
    char* fir=NULL;
    char* to=NULL;
    char*  name=NULL;
    clock_t first, last;
    int tim;
    if(add_graph(&G)==0) return 0;

     do{
        print_do();

        printf("Ввод: ");
         if(input_and_check(&l,"abcdefghij")==0) {
            free_graph(G);
            free(G);
            return 0;
        }
        scanf("%*c");
        

        switch(l){
            case 'a':
                enum ro pp;
                printf("Кол-во элементов: ");
                if(check_int_input(&k)==0) {
                    free_graph(G);
                    free(G);
                    return 0;
                }
                for(int i=0;i<k;i++){
                    add=readline("Ввод txt: ");

                    print_type();
                    do{
                        printf("Ввод type: ");
                        if(check_int_input(&val)==0){
                            free_graph(G);
                            free(G);
                            return 0;
                        }

                    }while(val>3 || val<1);
                    pp=val-1;

                    add_room(G,add,pp);
                    add=NULL;

                }
                add=NULL;
                scanf("%*c");
                break;
            case 'b':
                int size;
                
                printf("Кол-во элементов: ");
                if(check_int_input(&k)==0) {
                    free_graph(G);
                    free(G);
                    return 0;
                }
                for(int i=0;i<k;i++){

                    printf("Ввод size: ");
                    if(check_int_input(&size)==0){
                        free_graph(G);
                        free(G);
                        return 0;
                    }
                    fir=readline("fir: ");
                    to=readline("add to: ");
                    add_road(G,fir,to,size);
                    free(fir);
                    free(to);
                    fir=NULL;
                    to=NULL;

                }
                break;
            case 'c':
                name=NULL;
                name=readline("Ввод txt: ");
                del_room(G,name);
                free(name);
                break;
            case 'd':
                fir=NULL,to=NULL;
                fir=readline("add fir: ");
                to=readline("add to: ");
                dell_road(G,fir,to);
                free(fir);
                free(to);
                fir=NULL;
                to=NULL;
                break;
            case 'e':
                name=NULL;

                name=readline("add name: ");
                print_type();
                    do{
                        printf("Ввод type: ");
                        if(check_int_input(&val)==0){
                            free_graph(G);
                            free(G);
                            free(name);
                            return 0;
                        }

                    }while(val>3 || val<1);
                    pp=val;
                change_room(G,name,pp);
                free(name);
                break;
            case 'f':
                print_matrix(G);
                break;
             case 'g':
                print_graph(G);
                break;
            case 'h':
                fir=NULL;
                to=NULL;
                int k=1;
                 if(print_enter(G)==1){
                    do{
                    if(fir!=NULL){
                        free(fir);
                        fir=NULL;
                    }
                    fir=readline("add fir: ");
                    if((pos=search_room(G,fir))!=0){
                        if(G->enter[pos-1]->type==enter){
                            k=0;
                        }
                    }
                }while(k==1);
                }
                k=1;
                if(print_exit(G)==1){
                    do{
                    if(to!=NULL){
                        free(to);
                        to=NULL;
                    }
                    to=readline("add to: ");
                    if((pos=search_room(G,to))!=0){
                        if(G->enter[pos-1]->type==ex){
                            k=0;
                        }
                    }
                }while(k==1);
                }
                first=clock();
                if(fir!=NULL && to!=NULL){
                    find_fast(G,fir,to);
                    
                }
                last=clock();
                if(fir!=NULL){
                        free(fir);
                        fir=NULL;
                    }
                if(to!=NULL){
                    free(to);
                    to=NULL;
                }
                tim=(int)(last-first);
                printf("time %d",tim);
                break;
            case 'i':
            int p=0;
                char* fir=NULL;
                int pos;
                 if(print_enter(G)==1){
                    do{
                    if(fir!=NULL){
                        free(fir);
                        fir=NULL;
                    }
                    fir=readline("add fir: ");
                    if((pos=search_room(G,fir))!=0){
                        if(G->enter[pos-1]->type==enter){
                            p=1;
                        }
                    }
                }while(p==0);
                }
                first=clock();
                floydWarshall(G, fir);
                if(fir!=NULL){
                        free(fir);
                        fir=NULL;
                    }
                last=clock();
                tim=(int)(last-first);
                printf("time %d",tim);
                free(fir);
                break;
            case 'j':
            int lp=0;
                 if(print_enter(G)==1){
                    do{
                    if(to!=NULL){
                        free(fir);
                        fir=NULL;
                    }
                    fir=readline("add fir: ");
                    if((pos=search_room(G,fir))!=0){
                        if(G->enter[pos-1]->type==enter){
                            lp=1;
                        }
                    }
                }while(lp==0);
                }

                first=clock();
                breadthFirstSearch((G),pos-1);
                if(fir!=NULL){
                        free(fir);
                        fir=NULL;
                    }
                last=clock();
                tim=(int)(last-first);
                printf("time %d",tim);

                break;


        }




    }while(1);



    free_graph(G);
    free(G);
    return 1;
    



}