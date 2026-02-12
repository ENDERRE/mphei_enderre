#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>
#include <time.h>

#include "tree_s.h"
#include"tree_f.h"
#include"global.h"








int main(){
    srand(time(0));
    Node *goat=NULL;
    Node* newNode=NULL;

     Tree* tree=NULL;
    if(add_tree(&tree)==1) return 1;
    char* name=NULL;
    int key;
    Node* ser=NULL;
    enum se pr=none;
    char l;
    do{
        print_do();
        printf("\n");
        switch (pr){
            case del_er:
                printf("Такого не бывает\n");

                break;
            case no_el:
                printf("Элемент не найден\n");

                break;
            case print_el:
                printf("%d ",ser->key);
                for(int i=0;i<ser->size;i++){
                    printf("%d ",ser->value[i]);
                }
                break;
            case print_t:
                print_tree(tree);

                break;
            default:
                break;
        }
        printf("\n");
        pr=none;
        ser=NULL;
        printf("Ввод: ");
         if(input_and_check(&l,"abcdefghij")==0) {
            free_tree(tree);
            free(tree);
            return 0;
        }
        scanf("%*c");
        

        switch(l){
            case 'a':
                int k,val;
                printf("Кол-во элементов: ");
                if(check_int_input(&k)==0) {
                    free_tree(tree);
                    free(tree);
                    return 0;
                }
                for(int i=0;i<k;i++){
                    printf("Ввод key: ");
                    if(check_int_input(&key)==0) {
                        free_tree(tree);
                        free(tree);
                        return 0;
                    }
                    printf("Ввод value: ");
                    if(check_int_input(&val)==0) {
                        free_tree(tree);
                        free(tree);
                        return 0;
                    }
                    

                
                    insert(tree,key,val,&newNode);
                    if(find_goat_par(newNode,&goat)==1){
                        if(goat->parent!=NULL){
                            goat=goat->parent;

                        }
                        norm_tree(tree,goat);
                        goat=NULL;

                    }
                    iter_post(tree);
                }
                scanf("%*c");
                break;
            case 'b':
                free_tree(tree);

                name=readline("Ввод имени файла: ");

                if(input_txt(tree,name)==0){
                    printf("Ошибка при открытии файла: %s\n", strerror(errno));
                }
                free(name);
                break;
            case 'c':
                
                name=readline("Ввод имени файла: ");
                scanf("%*C");
                if(out_file(tree,name)==0){
                    printf("Ошибка при создании файла: %s\n", strerror(errno));
                }

                free(name);

                break;
            case 'd':

                printf("Ввод key: ");
                check_int_input(&key);

                scanf("%*C");
                pr=delete(tree,key);
                
                if(find_goat_tree(tree,&goat)==1){
                    if(goat->parent!=NULL){
                        goat=goat->parent;

                    }
                    norm_tree(tree,goat);
                    goat=NULL;

                }
                iter_post(tree);
                break;
            case 'e':
                int key;
                
                printf("Ввод key: ");
                check_int_input(&key);
                scanf("%*C");
        
                pr=search(&ser,tree,key);
                
                break;
            case 'f':
                printf("Ввод key: ");
                check_int_input(&key);
                scanf("%*C");
        
                pr=search_s(&ser,tree,key);
                break;
             case 'g':
                pr=print_t;
                break;
            case 'h':

                if(print_tree_png(tree)==0){
                    printf("Ошибка при открытии файла: %s\n", strerror(errno));
                }
                break;
            case 'i':

                search_time(tree);
                break;
            case 'j':

                dell_time(tree);
                break;


        }




    }while(1);
    free_tree(tree);
    free(tree);

    return 1;



}