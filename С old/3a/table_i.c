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

int add_table(table** T,int p){

    *T=malloc(sizeof(table));
    if(!*T){
        return 0;
    }
    (*T)->ks=NULL;
    
    

    (*T)->ks=malloc(sizeof(keyspace)*p);
    if(!(*T)->ks) return 0;
    (*T)->size=p;

    (*T)->n=0;

    return 1;
}

int get_line(FILE* file,char* s[]){
    char c;
    int n=0;
    while ((c = getc(file)) != EOF) {

        n++;
        *s=realloc(*s,sizeof(char)*n);
        (*s)[n-1]=c;
        if( c=='\n') return 1;
    }
    return 0;
}
int import_from_txt(table** T,char *name){
    
    FILE* file=fopen(name,"r");
    if (file == NULL) {
        printf("Ошибка при открытии файла: %s\n", strerror(errno));
        return 0;
    }




    char *line=malloc(sizeof(char));

    int k;
    (*T)->size=0;
    check_int_input_file(&k,file);
    

    (*T)->size=k;


    
    if((*T)->size==0) return 0;
    int linelen;
    int size=0;
    if((*T)->ks!=NULL) free((*T)->ks);
    (*T)->ks=NULL;
    (*T)->ks = malloc((*T)->size*sizeof(keyspace));

    if(!(*T)->ks) return 0;
    (*T)->n=0;
    while (check_int_input_file(&k,file)!=EOF) {
            fscanf(file,"%*c");
            size+=1;

                if((*T)->n==0){

                    int j=(*T)->n;
                    get_line(file,&line);
                    (*T)->ks[j].key= k;
                (*T)->ks[j].info=NULL;
                linelen=strcspn(line,"\n");
                (*T)->ks[j].info=malloc(sizeof(char)*(linelen+1));
                if(!(*T)->ks[j].info) {
                    free_table(*T);
                    return 0;
                }
                strncpy((*T)->ks[j].info, line, (linelen+1)*sizeof(char));
                (*T)->ks[j].info[linelen]='\0';


                
                }else if( check_double_key(*T,k)==0){
                     

                get_line(file,&line);

                linelen=strcspn(line,"\n");
                int j=(*T)->n;

                
            for (int c=j-1;c>=0 ;c--){
                if(k<(*T)->ks[c].key){
                    (*T)->ks[c+1].key=(*T)->ks[c].key;
                    (*T)->ks[c+1].info=(*T)->ks[c].info;
                    j--;
                }else{
                    break;
                }

            }
            
                (*T)->ks[j].key= k;
                (*T)->ks[j].info=NULL;
                (*T)->ks[j].info=malloc(sizeof(char)*(linelen+1));
                if(!(*T)->ks[j].info) {
                    free_table(*T);
                    return 0;
                }
                strncpy((*T)->ks[j].info, line, (linelen+1)*sizeof(char));
                (*T)->ks[j].info[linelen]='\0';
                }else{
                    get_line(file,&line);
                }
                (*T)->n++;

               
                
        

    }
    (*T)->n=size;

    free(line);
    fclose(file);
    return 1;
}
int import_from_std(table* T){

    T->n=0;
    int s;
    printf("Сколько заполняем: ");
    check_int_input(&s);
    
    while(s>T->size || s<0){
         printf("Сколько заполняем: ");
        check_int_input(&s);
    }

    for (int i=0;i<s;i++){
        printf("Ввод key: ");
        int n;
        check_int_input(&(n));
        
        
        if(i!=0){

            while(check_double_key(T,n)==1){
                printf("Дубликат ключа\n");
                printf("Ввод key: ");
                check_int_input(&(n));
        }
            
            int j=i;
            for (int k=i-1;k>=0 ;k--){
                if(n<T->ks[k].key){
                    T->ks[k+1].key=T->ks[k].key;
                    T->ks[k+1].info=T->ks[k].info;
                    j--;
                }else{
                    break;
                }

            }
            T->ks[j].key=n;
            T->ks[j].info=NULL;
            printf("Ввод text:");
        
            (T->ks[j].info)=readline("");
        }else{
            T->ks[i].key=n;
            T->ks[i].info=NULL;
            printf("Ввод text:");
        
            (T->ks[i].info)=readline("");
        }
        T->n++;
        
        
}

    return 1;
}


int import_key(table **T,int key,char* txt){
    
    if((*T)->n==(*T)->size) return 0;
    if(check_double_key(*T,key)==1) return 0;


    
    int i=(*T)->n;
    for (int k=i-1;k>=0 ;k--){
                if(key<(*T)->ks[k].key){
                    (*T)->ks[k+1].key=(*T)->ks[k].key;
                    (*T)->ks[k+1].info=(*T)->ks[k].info;
                    i--;
                }else{
                    break;
                }
    }
    (*T)->n++;
    (*T)->ks[i].key=key;
    (*T)->ks[i].info=txt;
    

    return 1;
}

