
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 

#include "../game_l.h"
#include "Stack.h"
#include "../game_global.h"


 


void free_stack(stack *tmp){
    el* head=tmp->head;
    while (head!=NULL){
        el* f=head;
        head=head->next;
        free(f);
    }
    free(tmp);
}
int add_stack(stack** tmp){
    *tmp=malloc(sizeof(stack));
    if(!*tmp){
        return 0;
    }
    (*tmp)->head=NULL;
    return 1;
}

int cube_switch_stack(puzzle* cube, stack* tmp){
    
    if(tmp->head==NULL){
        el* head=NULL;
        head=malloc(sizeof(el));
        if(!head){
            
            return 0;
        }
        head->next=NULL;
        head->p=cube->empt;
        tmp->head=head;

        
    }else{

        el* n=NULL;
        n=malloc(sizeof(el));
        if(!n){
            
            return 0;
        }
        n->next=tmp->head;
        tmp->head=n;
        n->p=cube->empt;

    }
    
    
    return 1;
}
int cube_undo_stack(stack* tmp,el** tt){
    if(tmp->head!=NULL){
        (*tt)=tmp->head;
        
        tmp->head=tmp->head->next;
        (*tt)->next=NULL;


    }else{
        return 0;
    }
    return 1;
}
