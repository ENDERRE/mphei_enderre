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


void print_table(table* T){
    printf("KEY  TEXT\n");
    for(int i=0;i<T->n;i++){
        printf("|");
        printf("%d | ",T->ks[i].key);
        printf("%s",T->ks[i].info);
        printf("|\n");
    }
}

int print_el(table* T){
    int i;
    int key;
    printf("Введите ключь: ");
    check_int_input(&key);
    if(search_key(T,key,&i)==0){
        return 0;
    }
    printf("KEY  INFO\n");
    printf("|%d ",T->ks[i].key);
    printf("| %s|\n",T->ks[i].info);
    return 1;
    
}

void print_group(table *T,int *k){
    printf("Ввод 1 ключа: ");
    int n1;
    check_int_input(&n1);
    printf("Ввод 2 ключа: ");
    int n2;
    check_int_input(&n2);
    *k=0;
    for (int i=0;i<T->n;i++){
        if(T->ks[i].key<=n2 && T->ks[i].key>=n1){
            (*k)++;
            if(*k==1){
                printf("KEY  INFO\n");

            }
            
            printf("|%d | ",T->ks[i].key);
            printf("%s|\n",T->ks[i].info);
        }
    }
    scanf("%*c");
}
void free_table(table* T){
    for (int i=0;i<(T)->n;i++){
        if((T)->ks[i].info!=NULL){
            free((T)->ks[i].info);
        }
    }
    if((T)->ks!=NULL) free((T)->ks);
    free(T);

}


int push_to_file(table* T,char* name){
    if(T->size==0) return 0;

   
    
    FILE* file;
    file=fopen(name,"w");
    if (file == NULL) {
        
        return 0;
    }
    fprintf(file, "%d\n", T->size);
    for (int i=0;i<T->n;i++){
    fprintf(file, "%d\n", T->ks[i].key);
    fprintf(file, "%s\n", T->ks[i].info);
    }
    fclose(file);

    return 1;

}

