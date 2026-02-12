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

int check_double_key(table *T,int key){
    int low = 0;
    int high = T->n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (T->ks[mid].key == (key) ) {
            
            return 1;
        }
        else if (T->ks[mid].key < (key)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;

}
int delete_double(table* T){
    for(int i=T->n-1;i>=0;i--){
        if(check_double_key(T,T->ks[i].key)==0){
            for(int j=i;j<T->n-1;j++){
                T->ks[j].key=T->ks[i+1].key;
                T->ks[j].info=T->ks[i+1].info;
            }
            T->n-=1;
        }

    }
    return 1;

}
int search_key(table* T,int n,int *key){

    int low = 0;
    int high = T->n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (T->ks[mid].key == (n)) {
            *key=mid;
            return 1;
        }
        else if (T->ks[mid].key < (n)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;

}
int erase(table* T,int key){
    int i;
    if(search_key(T,key,&i)==0){
        return 0;
    }
    free(T->ks[i].info);
    for (int k=i;k<T->n-1;k++){
        T->ks[k].key=T->ks[k+1].key;
        T->ks[k].info=T->ks[k+1].info;
    }
    T->n--;
    return 1;

}