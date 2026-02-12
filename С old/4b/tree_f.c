#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>
#include <time.h>

#include"tree_f.h"
#include"tree_s.h"
#include"global.h"


enum se search(Node** temp,Tree* tree,int key){

    Node* cur=tree->root;

    while(cur!=NULL){
        if(cur->key==key){
            (*temp)=cur;
            return print_el;
        }else if(cur->key>key){
            cur=cur->left;
        }else if(cur->key<key){
            cur=cur->right;
        }

    }
    return no_el;

}
enum se search_s(Node** temp,Tree* tree,int key){

    Node* cur=tree->root;

    while(cur!=NULL){
        if(cur->key!=key){
            (*temp)=cur;
            return print_el;
        }
        if(cur->key>key){
            cur=cur->left;
        }else if(cur->key<key){
            cur=cur->right;
        }
        
        

    }
    return no_el;

}
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->size=1;
    newNode->value = malloc(sizeof(int));
    newNode->value[0] = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->mass=0;
    newNode->deph=0;
    return newNode;
}
int add_tree(Tree** tree){
    (*tree)=malloc(sizeof(Tree));
    if(!(*tree)) return 1;
    (*tree)->root=NULL;
    (*tree)->fir=NULL;
    return 0;
}
void norm_mass_deph(Node* temp){
    temp->mass+=1;
    if(temp->parent!=NULL){
        temp->deph=temp->parent->deph+1;


        Node* tt=temp->parent;
        while(tt!=NULL){
            tt->mass+=1;
            tt=tt->parent;
        }
    }

}
int find_goat_par(Node* newNode,Node** goat){
    if(newNode!=NULL){
        Node *temp=newNode;
        while (temp->parent!=NULL){
            if((temp->parent->mass*(const))<temp->mass){
                (*goat)=temp;
            }
            temp=temp->parent;
        }
    }
    
    if((*goat)!=NULL){
        return 1;
    }else{
        return 0;
    }

}
enum se search_iter(Node** temp,Node* goat,int key){
    Node* tt=goat;

    while (tt!=NULL){

        if(tt->key==key){
            *temp=tt;
            return print_el;
        }
        tt=tt->next;
    }
    
    return no_el;

}
void iter_post_goat(Node* goat,Node** fir){
    Node *cur = NULL;
    Node* prevr=NULL;
    Node* prev=NULL;

    Node* go=NULL;

    cur = goat;
    
    while(cur ->left!=NULL || cur->right!=NULL){
        if(cur->left!=NULL)  {
            cur = cur->left;
        }else if(cur->right!=NULL){
            cur=cur->right;
        }
    }

    (*fir)=cur;

    go=cur;
    go->next=NULL;

    while (cur!=goat){

        if(go!=cur){
            Node* ll=NULL;
            if(search_iter(&ll,goat,cur->key)==no_el){
                go->next=cur;
                cur->prev=go;
                go=cur;
                go->next=NULL;
            }
            
        }
        

        cur=cur->parent;

        if(cur->right!=prev &&cur->right!=prevr && cur->right!=NULL){

            while(cur->right!=NULL){
                cur=cur->right;
                
                if(cur->left!=NULL){
                    while(cur ->left!=NULL || cur->right!=NULL){
                        if(cur->left!=NULL)  {
                            cur = cur->left;
                        }else if(cur->right!=NULL){
                            cur=cur->right;
                        }
                    }
                    break;
                }else{
                    prevr=cur;

                }
            }
        }else{
            prev=cur;

        }
    }
    go->next=cur;
    cur->prev=go;
    cur->next=NULL;

}
int insert(Tree* tree, int key, int value,Node** new) {
    Node* parent = NULL;
    if (search(&parent,tree,key)==print_el){

        parent->size+=1;
        parent->value=realloc(parent->value,parent->size*sizeof(int));
        parent->value[parent->size-1]=value;
        (*new)=NULL;
        return 1;
    }

    Node* newNode = createNode(key, value);

    Node* current = tree->root;
    

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == NULL) {
        tree->root = newNode;
    } else if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    norm_mass_deph(newNode);
    (*new)=newNode;
    

    return 1;
}
void free_goat(Node* goat){
    while(goat!=NULL){
        Node* f=goat;
        goat=goat->next;
        free(f->value);
        free(f);
    }

}
int check_mid(int mid,Node* min,Node* temp){
    int mid_m=mid-min->key;
    int mid_t=mid-temp->key;

    if(mid_m<0){
        mid_m*=(-1);
    }
    if(mid_t<0){
        mid_t*=(-1);
    }

    if(mid_t<mid_m){
        return 1;
    }else{
        return 0;
    }



}
void norm_tree(Tree* tree,Node* goat){
    Node** koll=malloc(goat->mass*sizeof(Node*));
    
    Node* temp=NULL;
    iter_post_goat(goat,&temp);

    int i=0;
    Node* last;

    Node* fir=temp;
    while(temp!=NULL){
        koll[i]=temp;
        i++;
        last=temp;
        temp=temp->next;
        
    }
    temp=last;
    if(temp->parent!=NULL){
        if(temp->parent->left==temp){
            temp->parent->left=NULL;
        }else if(temp->parent->right==temp){
            temp->parent->right=NULL;
        }
    }else{
        tree->root=NULL;
        tree->fir=NULL;
    }



    int mid_i;
    int mid=0;
    for(int j=0;j<i;j++){
        mid+=koll[j]->key;                                      
    }
    mid=mid/goat->mass;

    Node* min=NULL;

    for(int j=0;j<i;j++){
        if(min==NULL){
            min=koll[j];
            mid_i=j;
        }else if(check_mid(mid,min,koll[j])==1){
            min=koll[j];
            mid_i=j;
    
        }
    }
    Node* new=NULL;
    for(int j=0;j<min->size;j++){
        insert(tree,min->key,min->value[j],&new);
    }
    mid=min->key;

    
    for(int j=mid_i;j<i-1;j++){

        koll[j]=koll[j+1];
    }
    i--;

    int mid_max=koll[0]->key,mid_min=koll[0]->key;
   
    
    for(int j=0;j<i;j++){
        if(koll[j]->key>mid_max){
            mid_max=koll[j]->key;
        }
        if(koll[j]->key<mid_min){
            mid_min=koll[j]->key;
        }
    }
    
    int middle;
    int k=0;
    mid_max=mid;
        for(int j=0;j<i;j++){
        if(koll[j]->key>mid){
            mid_max+=koll[j]->key;
            k+=1;
        }

    }
    k+=1;
    middle=mid_max/k;
    k=0;
    while(mid_max-mid!=0){
        min=NULL;
        
        for(int j=0;j<i;j++){
            if(koll[j]->key>mid){
                if(min==NULL ){
                    min=koll[j];
                    mid_i=j;
                }else if(check_mid(middle,min,koll[j])==1){
                    min=koll[j];
                    mid_i=j;

            
                }
            }
            
        }
        if(min==NULL){
            break;
        }

        Node* new=NULL;
        for(int j=0;j<min->size;j++){
            insert(tree,min->key,min->value[j],&new);
        }

        
        for(int j=mid_i;j<i-1;j++){

            koll[j]=koll[j+1];
        }
        i--;

        mid_max=mid;
        for(int j=0;j<i;j++){
        if(koll[j]->key>mid){
            mid_max+=koll[j]->key;
            k+=1;
        }

    }
    k+=1;
    middle=mid_max/k;
    k=0;
    }
    mid_max=mid;
        for(int j=0;j<i;j++){
        if(koll[j]->key<mid){
            mid_min+=koll[j]->key;
            k+=1;
        }

    }
    k+=1;
    middle=mid_min/k;
    k=0;
    while(mid-mid_min!=0){
        min=NULL;
        for(int j=0;j<i;j++){
            if(min==NULL){
                min=koll[j];
                mid_i=j;
            }else if(check_mid(middle,min,koll[j])==1){
                min=koll[j];
                mid_i=j;
        
            }
        }
        Node* new=NULL;
        if(min==NULL) {
            free_goat(fir);
            free(koll);
            return;
        }
        for(int j=0;j<min->size;j++){
            insert(tree,min->key,min->value[j],&new);
        }

        
        for(int j=mid_i;j<i-1;j++){
            koll[j]=koll[j+1];
        }
        i--;

        mid_max=mid;
        for(int j=0;j<i;j++){
        if(koll[j]->key<mid){
            mid_min+=koll[j]->key;
            k+=1;
        }

    }
    k+=1;
    middle=mid_min/k;
    k=0;
    }

    free_goat(fir);
    free(koll);
    return;
}


void iter_post(Tree* tree){
    if(tree->root==NULL) return;
    Node *cur = NULL;
    Node* prevr=NULL;
    Node* prev=NULL;

    Node* go=NULL;

    cur = tree->root;
    
    while(cur ->left!=NULL || cur->right!=NULL){
        if(cur->left!=NULL)  {
            cur = cur->left;
        }else if(cur->right!=NULL){
            cur=cur->right;
        }
    }

    tree->fir=cur;
    go=cur;
    go->next=NULL;

    while (cur!=tree->root){

        if(go!=cur){
            Node* ll=NULL;
            if(search_iter(&ll,tree->fir,cur->key)==no_el){
                go->next=cur;
                cur->prev=go;
                go=cur;
                go->next=NULL;
            }
            
        }
        

        cur=cur->parent;

        if(cur->right!=prev &&cur->right!=prevr && cur->right!=NULL){

            while(cur->right!=NULL){
                cur=cur->right;
                
                if(cur->left!=NULL){
                    while(cur ->left!=NULL || cur->right!=NULL){
                        if(cur->left!=NULL)  {
                            cur = cur->left;
                        }else if(cur->right!=NULL){
                            cur=cur->right;
                        }
                    }
                    break;
                }else{
                    prevr=cur;

                }
            }
        }else{
            prev=cur;

        }
    }
    go->next=cur;
    cur->prev=go;
    cur->next=NULL;

}
int print_tree_png(Tree* tree){
    FILE *fp;
    fp = fopen("graph.dot", "w");

    if(fp == NULL) {
        
        return 0;
    }
    fprintf(fp, "graph G {\n");
    Node* tt=tree->fir;
    while(tt!=NULL){
        
        if(tt->left!=NULL){
            fprintf(fp, "    %d -- %d;\n",tt->key,tt->left->key);
        }
        if(tt->right!=NULL){
            fprintf(fp, "    %d -- %d;\n",tt->key,tt->right->key);
        }
         
        tt=tt->next;

        
    }


    

    
    fprintf(fp, "}\n");
    fclose(fp);
    system("dot -Tpng graph.dot -o graph.png");
    return 1;

}
void print_tree(Tree* tree){
    Node* temp=tree->fir;
    printf("\n\n");
    while(temp!=NULL){
        printf("%d ",temp->key);
        for (int i=0;i<temp->size;i++){
            printf("%d ",temp->value[i]);
        }
        printf("\n");
        temp=temp->next;

    }
}
enum se delete(Tree* tree,int key) {

    if(tree->fir==NULL || tree->root==NULL) return no_el;
    Node* tt=NULL;
    if(search(&tt,tree,key)==print_el){
        if(tt->size==1){
                if(tt->left==NULL){
                    if(tt->parent==NULL && tt->right==NULL){
                        tree->root=NULL;
                        tree->fir=NULL;

                    }else if(tt->parent==NULL){

                        tree->root=tt->right;
                        if(tt->right!=NULL) tt->right->parent=NULL;
                        Node* ff=tree->fir;
                        while(ff!=NULL){
                            ff->deph--;
                            ff=ff->next;
                        }
                        

                    }else {
                        
                        Node* par=tt->parent;
                        
                        if(par->right==tt){
                            par->right=tt->right;
                            
                        }else{
                            par->left=tt->right;   
                        }
                        if(tt->right!=NULL) tt->right->parent=par;
                        while(par!=NULL){
                            par->mass--;
                            par=par->parent;
                        }
                    }
                    if(tt->prev!=NULL) tt->prev->next=tt->next;
                        if(tt->next!=NULL) tt->next->prev=tt->prev;
                        if(tree->fir==tt){
                            tree->fir=tt->next;
                        }
                    free(tt->value);
                    free(tt);
                    return none;
                }
                Node* kk=NULL;
                kk=tt->left;
                while(kk->right!=NULL){
                    kk=kk->right;
                }
                Node* par=kk->parent;
                while(par!=NULL){
                    par->mass--;
                    par=par->parent;
                }
                
                par=kk->parent;
                
                if(par->right==kk){
                    par->right=kk->left;
                    
                    if(kk->left!=NULL){
                        kk->left->parent=par;
                    }
                    
                }else{
                    par->left=kk->left;
                    if(kk->left!=NULL){
                        kk->left->parent=par;
                    }
                    
                }
                tt->key=kk->key;
                
                free(tt->value);
                tt->value=kk->value;
                tt->size=kk->size;
                
                
                if(kk->prev!=NULL) kk->prev->next=kk->next;
                if(kk->next!=NULL) kk->next->prev=kk->prev;
                if(tree->fir==kk) tree->fir=kk->next;

                free(kk);
                return none;
                }else{
                for(int i=0;i<tt->size-1;i++){
                    tt->value[i]=tt->value[i+1];
                }
                tt->size-=1;
                tt->value=realloc(tt->value,tt->size*sizeof(int));
                return none;
                }
    }else{
        return no_el;
    }

}

void free_tree(Tree* tree){
    Node* temp=tree->fir;
    while(temp!=NULL){
        Node* f=temp;
        temp=temp->next;

        free(f->value);
        free(f);
    }
    tree->fir=NULL;
    tree->root=NULL;

}
int input_txt(Tree* tree,char* name){
    FILE* file=fopen(name,"r");
    if (file == NULL) {
        
        return 0;
    }
    int key,val;
Node* newNode=NULL;
Node* goat=NULL;
    while(check_int_input_file(&key,file)!=EOF){
        if(check_int_input_file(&val,file)==EOF){
            break;
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
    fclose(file);
    return 1;



}
int out_file(Tree* tree,char* name){
    FILE* file;
    file=fopen(name,"w");

    if (file == NULL) {
        
        return 0;
    }

    Node* tt=tree->fir;
    while(tt!=NULL){

        for(int i=0;i<tt->size;i++){
            fprintf(file, "%d\n", tt->key);
            fprintf(file, "%d\n", tt->value[i]);
        }
        tt=tt->next;
    }

    fclose(file);
    return 1;
}
int find_goat_tree(Tree* tree,Node** goat){
    Node* temp=tree->fir;
    while(temp!=NULL){
        if(temp->parent!=NULL){
            if(temp->parent->mass*const<temp->mass){
                if((*goat==NULL)){
                    (*goat)=temp;
                }else if(temp->deph<(*goat)->deph){
                    (*goat)=temp;
                }
            }
        }
        temp=temp->next;

    }
    if((*goat)!=NULL){
        return 1;
    }else{
        return 0;
    }

}
int search_time(Tree* tree){
    free_tree(tree);


    clock_t first, last;
    Node* t=NULL;
    Node* goat=NULL;
    int tt;
    int n = 10, key[10000], k, cnt = 100, i, m;
    while (n-- > 0){
    for (i = 0; i < 10000; ++i){
        key[i] = rand();
    }

    for (i = 0; i < cnt; ){
    k = rand();
    insert(tree, key[k%1000],k,&t);

    if(find_goat_par(t,&goat)==1){
        if(goat->parent!=NULL){
            goat=goat->parent;

        }
        norm_tree(tree,goat);
        goat=NULL;

    }
    iter_post(tree);
    i++;

    }
    m = 0;
    first = clock();
    for (i = 0; i < 10000; ++i){
    if (search(&t,tree, key[i])==print_el) {
        m++;
    }

    }
   
    last = clock();
    printf("%d items was found\n", m);
    tt=(int)(last-first);
    printf("test #%d, number of nodes = %d, time = %d\n", 10 - n, cnt, tt);
    cnt=(11 -n)*100;
    free_tree(tree);

    }
    return 1;
}
int dell_time(Tree* tree){
    free_tree(tree);


    clock_t first, last;
    Node* t=NULL;
    Node* goat=NULL;
    int tt;
    int n = 10, key[10000], k, cnt = 100, i, m;
       while (n-- > 0){
    for (i = 0; i < 10000; ++i){
        key[i] = rand();
    }

    for (i = 0; i < cnt; ){
    k = rand();
    insert(tree, key[k%1000],k,&t);

    if(find_goat_par(t,&goat)==1){
        if(goat->parent!=NULL){
            goat=goat->parent;

        }
        norm_tree(tree,goat);
        goat=NULL;

    }
    iter_post(tree);
    i++;

    }
    m = 0;
    first = clock();
    for (i = 0; i < 50; ++i){
    if (delete(tree,key[i])==none) {
        m++;
    }

           
        if(find_goat_tree(tree,&goat)==1){
            if(goat->parent!=NULL){
                goat=goat->parent;

            }
            norm_tree(tree,goat);
            goat=NULL;

        }
        iter_post(tree);

    }
   
    last = clock();
    printf("%d items was found\n", m);
    tt=(int)(last-first);
    printf("test #%d, number of nodes = %d, time = %d\n", 10 - n, cnt, tt);
    cnt=(11 -n)*100;
    free_tree(tree);

    }
    return 1;
}