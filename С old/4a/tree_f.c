#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>


#include "tree_s.h"
#include "tree_f.h"
#include "global.h"




enum se search(Node** temp,Tree* tree,int key){
    Node* tt=tree->fir;

    while (tt!=NULL){

        if(tt->key==key){
            *temp=tt;
            return print_el;
        }
        tt=tt->next;
    }
    
    return no_el;

}
void iter_post(Tree* tree){
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
            if(search(&ll,tree,cur->key)==no_el){
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
    return newNode;
}
int add_tree(Tree** tree){
    (*tree)=malloc(sizeof(Tree));
    if(!(*tree)) return 1;
    (*tree)->root=NULL;
    (*tree)->fir=NULL;
    return 0;
}


int insert(Tree* tree, int key, int value) {
    Node* parent = NULL;
    if (search(&parent,tree,key)==print_el){

        parent->size+=1;
        parent->value=realloc(parent->value,parent->size*sizeof(int));
        parent->value[parent->size-1]=value;

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
    
    iter_post(tree);

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

 
enum se delete(Tree* tree,int key, int num) {
    if(num<=0) return del_er;

    Node* tt=tree->fir;

    while(tt!=NULL){
        
        if(tt->key==key){
            
            if(num==1 && tt->size==1){
                if(tt->left==NULL){
                    if(tt->parent==NULL && tt->right==NULL){
                        tree->root=NULL;
                        tree->fir=NULL;

                    }else if(tt->parent==NULL){
                        tt->prev->next=tt->next;
                        tree->root=tt->right;
                        tt->right->parent=NULL;
                        

                    }else {
                        if(tt->prev!=NULL){
                            tt->prev->next=tt->next;
                        }
                        tt->next->prev=tt->prev;
                        if(tree->fir==tt){
                            tree->fir=tt->next;
                        }
                        Node* par=NULL;
                        par=tt->parent;
                        
                        if(par->right==tt){
                            par->right=NULL;
                            
                        }else{
                            par->left=NULL;   
                        }
                        
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

                Node* par=NULL;
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
                
                kk->prev->next=kk->next;
                kk->next->prev=kk->prev;
                free(kk);


            }else{
                
                if(num>tt->size) return 1;

                for(int i=num-1;i<tt->size-1;i++){
                    tt->value[i]=tt->value[i+1];
                }
                tt->size-=1;
                tt->value=realloc(tt->value,tt->size*sizeof(int));

            }

            return none;
            
        }
        tt=tt->next;
    }
    return no_el;

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
enum se search_s(Node** temp,Tree* tree,int key){
    Node* kk=tree->fir;
    Node* max=NULL;
    while(kk!=NULL){
        if(kk->key<key){
            if(max==NULL){
                max=kk;
            }else if (kk->key>max->key){
                max=kk;
            }
        }
        kk=kk->next;
    }
    if(max==NULL) return no_el;
    (*temp)=max;
    return print_el;
}



int input_txt(Tree* tree,char* name){
    FILE* file=fopen(name,"r");
    if (file == NULL) {
        
        return 0;
    }
    int key,val;

    while(check_int_input_file(&key,file)!=EOF){
        if(check_int_input_file(&val,file)==EOF){
            break;
        }

        insert(tree,key,val);
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