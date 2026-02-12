#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#include "table_s.h"
#include "global.h"

void clearbuf(){
    scanf("%*s[^\n]");
}
int sorter(const void *x,const void *y){
    keyspace *xx =(keyspace*)x;
    keyspace *yy =(keyspace*)y;
    return xx->key-yy->key;

}
int check_int_input_file(int *i,FILE* file){
  

    int k=fscanf(file,"%d",&(*i));
    if(k==(EOF)){
        return EOF;
    }
    while(k==0){
    	clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        k=fscanf(file,"%d",&(*i));
        if(k==EOF){
            return EOF;
        }
    }
    return 1;
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

int isNumber(char *input) {
    int s=0,k=0;
    for (int i = 0; input[i] != '\0'; i++){

    
        if (isalpha(input[i])){
            k++;
        }
        s++;
    }
    if(s==k) return 0;  
    return 1;
}

int input_and_check(char *s,int i){
    int k,c=1;
    k=scanf("%c", s);


    if(k==(-1)) return 0;
    
    if(k==0) clearbuf();
    if(i==1){
        if((*s)=='a' || (*s)== 'b' || *s=='c'){
        c=0;
    }
    }else if(i==2){
        if((*s)=='a' || (*s)== 'b'){
        c=0;
    }
    }
   
    while (!isalpha(*s) || c==1){
        if(k == 0) clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        
        k=scanf("%s", s);

        if(i==1){
            if((*s)=='a' || (*s)== 'b' || *s=='c'){
            c=0;
            }
        }else if(i==2){
            if((*s)=='a' || (*s)== 'b'){
            c=0;
            }
    
        }else{
            c=1;
        }
        if(k==(-1)) return 0;
        
        if(k==0) clearbuf();

    }
    return 1;
}

