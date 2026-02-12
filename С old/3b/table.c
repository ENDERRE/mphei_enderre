#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>


#include "table_s.h"
#include "global.h"
#include "table_i_out.h"
#include "table.h"


int add_table(table** T,int p){
    
    *T=malloc(sizeof(table));
    if(!*T){
        return 0;
    }
    
   
    (*T)->ks=NULL;
    (*T)->ks=malloc(sizeof(keyspace**)*p);
    if(!(*T)->ks) return 0;
    
    for (int i=0;i<p;i++){
        (*T)->ks[i]=NULL;
    }

    (*T)->size=p;
    scanf("%*c");
    

    return 1;
}
void free_table(table* T){
    for (int i=0;i<T->size;i++){
        if(T->ks[i]!=NULL){
            keyspace* kk=T->ks[i];
            while(kk!=NULL){
                node* nn=kk->list;
                while(nn!=NULL){
                    node* f=nn;
                    nn=nn->next;
                    free(f);
                }
                keyspace*ff=kk;
                kk=kk->next;
                free(ff);
            }
            
        }
    }
    free(T->ks);
}
void print_table(table*T){
    printf("KEY | REALISE | INFO\n");
    for (int i=0;i<T->size;i++){
        if(T->ks[i]!=NULL){
            keyspace* kk=T->ks[i];
            while(kk!=NULL){
                node* nn=kk->list;
                while(nn!=NULL){
                    printf("%d | %d | %d\n",kk->key,nn->release,nn->info);
                    nn=nn->next;
                }
                kk=kk->next;
            }
            
        }
    }
}
int hash(int key,int size){
    return key%size;
}

int search_double_info_list(node* Node,int info){
    node* temp=Node;
    while(temp){
        if(temp->info==info){
            return 1;
        }else{
            temp=temp->next;
        }
    }
    return 0;
}

int search_last_r(node*temp){
    int m=temp->release;

    while(temp!=NULL){
        if(temp->release>m){
            m=temp->release;
        }
        temp=temp->next;
    }
    return m;
}

int add_info(node* NODE,int info){
    printf("Такое значенке info уже есть\n");
    printf("Ввод: ");
    if(check_int_input(&info)==0) return 0;
    while(search_double_info_list(NODE,info)==1){
        printf("Такое значенке info уже есть\n");
        printf("Ввод: ");
        if(check_int_input(&info)==0) return 0;
    }
    NODE->info=info;
    return 1;
}

int search_double_key(int key,keyspace* temp){
    if(temp==NULL) return 0;
    while(temp!=NULL){
        if(temp->key==key){
            return 1;
        }
        temp=temp->next;
    }
    return 0;


}

int add_el(table* T,int key,int info){
    if((T)->size==0) return 0;
    int h=hash(key,(T)->size);

    if((T)->ks[h]==NULL){
        (T)->n+=1;
    }

    keyspace* temp=(T)->ks[h];
    if(search_double_key(key,temp)==0){
        temp=NULL;
        temp=malloc(sizeof(keyspace));
        if(!temp) return 0;

        
        temp->list=NULL;
        temp->next=(T)->ks[h];
        (T)->ks[h]=temp;
        temp->key=key;
    }

    



    node* Node=NULL;
    Node=malloc(sizeof(node));
    if(!Node) return 0;

    Node->next=NULL;
    Node->info=info;

    if(temp->list==NULL){
        Node->release=1;
        temp->list=Node;
        printf("ll");
    }else{
        if(search_double_info_list(temp->list,info)==1){

            add_info(temp->list,info);
        }
        node* t=temp->list;
        Node->release=search_last_r(temp->list)+1;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=Node;


    }
    
    return 1;
}

int search_1_el_key(table* T,int key){
    int h=hash(key,T->size);

    if(T->ks[h]==NULL) return 0;
    keyspace* temp=T->ks[h];

    while(temp!=NULL && temp->key!=key){
        temp=temp->next;
    }
    if(temp==NULL) return 0;
    
    printf("\nKEY: %d\n",key);
    printf("VER | INFO\n");
    node* Node=temp->list;

    while(Node!=NULL){
        printf("%d | %d\n",Node->release,Node->info);
        Node=Node->next;
    }
    return 1;
}

int search_1_el_ver(table* T,int key,int ver){
    int h=hash(key,T->size);

    if(T->ks[h]==NULL) return 0;
    keyspace* temp=T->ks[h];

    while(temp!=NULL && temp->key!=key){
        temp=temp->next;
    }
    if(temp==NULL) return 0;


    node* Node=temp->list;

    while(Node!=NULL && Node->release!=ver){
        Node=Node->next;
    }
    if(Node==NULL) return 0;

    printf("\nKEY | VEER | INFO\n");
    printf("%d | %d | %d\n",key,ver,Node->info);
    return 1;
}

enum se search_and_delete(table* T){
        char l;


        printf("Ввод: ");
        if(input_and_check(&l,"abcd")==0) {
            free_table(T);
            free(T);
            return error;
        }
        scanf("%*c");

        switch(l){
            case 'a':;
                return pr_key;
                break;
            case 'b':
                return pr_ver;
                break;
            case 'c':
                return del_key;
                break;
            case 'd':
                return del_ver;
                break;
        }
    return none;
}

int delete_1_key(table* T,int key){
    int h=hash(key,T->size);

    if(T->ks[h]==NULL) return 0;
    keyspace* temp=T->ks[h];
    keyspace* prev=temp;
    while(temp!=NULL && temp->key!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL) return 0;

    node* Node=temp->list;
    while(Node!=NULL){
        node* ff=Node;
        Node=Node->next;
        free(ff);
    }

    if(T->ks[h]==temp){
        T->ks[h]=temp->next;
    }else{
        prev->next=temp->next;
    }
    free(temp);
    return 1;

}

int delete_1_ver(table* T,int key,int ver){
    int h=hash(key,T->size);

    if(T->ks[h]==NULL) return 0;
    keyspace* temp=T->ks[h];

    while(temp!=NULL && temp->key!=key){
        temp=temp->next;
    }
    if(temp==NULL) return 0;


    node* Node=temp->list;
    node*prev=NULL;
    while(Node!=NULL && Node->release!=ver){
        prev=Node;
        Node=Node->next;
    }
    if(Node==NULL) return 0;

    if(temp->list==Node){
        temp->list=Node->next;
    }else{
        prev->next=Node->next;
    }
    free(Node);
    return 1;

}