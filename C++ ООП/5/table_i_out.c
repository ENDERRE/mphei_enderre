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

int import_from_std_arg(table* T, char *argv,int argc){

    int n=argc;

    int key,info;
    for (int i=1;i<n;i++){
        key=atoi(&(argv)[i]);
        info=(argv)[i];

        add_el(T,key,info);

}

    return 1;
}
int import_from_std(table* T){

    int n;
    printf("Сколько элементов добавить:  ");
    if(check_int_input(&n)==0) return 0;

    int key,info;
    for (int i=0;i<n;i++){
        printf("Ввод key: ");
        check_int_input(&key);
        
        printf("Ввод int: ");
        check_int_input(&info);

        add_el(T,key,info);

}
    scanf("%*c");
    return 1;
}

int import_from_bin(table* T,char *name){
    FILE* file=fopen(name,"rb");
    if (file == NULL) {
        
        return 0;
    }
    int key,info;
    
    while(fread(&key,sizeof(int),1,file)){
        fread(&info,sizeof(int),1,file);
        add_el(T,key,info);
    }
    fclose(file);
    return 1;
}
int push_to_bin(table* T,char* name){
    if(T->size==0) return 0;

    FILE* file=NULL;
    file=fopen(name,"wb");

    if (file == NULL) {
        
        return 0;
    }

    for (int i=0;i<T->size;i++){
        if(T->ks[i]!=NULL){
            keyspace* kk=T->ks[i];
            while(kk!=NULL){
                node* nn=kk->list;
                while(nn!=NULL){
                    fwrite(&(kk->key),sizeof(int),1,file);
                    fwrite(&(nn->info),sizeof(int),1,file);
                    nn=nn->next;
                }
                kk=kk->next;
            }
            
        }
    }
    fclose(file);
    return 1;

}