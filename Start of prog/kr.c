#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct List{
    Node *head;
} List;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void printList(List* list) {
    Node* head =list->head;
    Node* current = head;
    while (current != NULL) {
        if(current->data=='\n'){
            break;
        }
        printf("%c", current->data);
        current = current->next;
    }

}
void new_list(List* f,Node* head){
    Node* t=NULL;
    t=f->head;
    
    while(t->next!=NULL){
        Node* r=t;
        t=t->next;
        free(r);
    }
    f->head=NULL;
  
    Node* c=NULL;
    Node* h=NULL;
    
    

    while (( head->data!=' ') && head->data!='\n'){
        if(head==NULL){
            break;
        }
        Node* n=createNode(head->data);
        if(h==NULL){
            h=n;
            c=n;
            

        }else{
        c->next=n;
        n->prev=c;
        c=c->next;
        
                                                

        }
        head=head->next;
        
       
    }
    
    f->head=h;
}
void processString(List* list) {
    Node* head=list->head;
    Node* current = head;



    
    while (head != NULL && (head->data == ' ' || head->data == '\t')) {
        Node* temp = head;
        head = head->next;
        head->prev=NULL;
        free(temp);
    }
    list->head=head;

    current = head;
    while (current != NULL) {
        if ((current->data == ' ' || current->data == '\t') && (current->next != NULL && ((current->next)->data == ' ' || current->next->data == '\t'))) {
            Node* temp = current->next;
            current->next = temp->next;
            temp->next->prev=current;
            free(temp);
        } else {
            current = current->next;
        }
    }


    head=list->head;


    List* f=malloc(sizeof(List));
    Node* h=malloc(sizeof(Node));
    h->next=NULL;
    f->head=h;
    new_list(f,head);


    Node* pr1=head;
    while(head->data!=' '){
        head=head->next;
    }
    head=head->next;
    Node* pr2=head;
    List* f2=malloc(sizeof(List));
    Node* h2=malloc(sizeof(Node));
    h2->next=NULL;
    f2->head=h2;
    new_list(f2,head);

    
    char AA[]="qwertyuiopasdfghjklzxcvbnm";
    int ll=strlen(AA);
    int *a1=malloc(sizeof(int)*ll);
    int *a2=malloc(sizeof(int)*ll);

    for (int i=0;i<ll;i++){
        a1[i]=0;
        a2[i]=0;

    }
    Node* ht1=NULL;
    Node* ht2=NULL;
    ht1=f->head;
    ht2=f2->head;
    int fl=0;


    int flag=0;



    while(pr1->data!='\n'){
            for (int i=0;i<ll;i++){
                
                a1[i]=0;

    }
        while(ht1!=NULL){
            for (int i=0;i<ll;i++){
                if(ht1->data==AA[i]){
                    a1[i]+=1;
                    break;
                }
                
            }
            ht1=ht1->next;
        }

        
        while(f2->head->data!='\n'){
            for (int i=0;i<ll;i++){
                
                a2[i]=0;

    }
            while(ht2!=NULL){
            for (int i=0;i<ll;i++){
                if(ht2->data==AA[i]){
                    a2[i]+=1;
                    break;
                }
                
            }
            ht2=ht2->next;
        }
        
        for (int i=0;i<ll;i++){
            if(a1[i]!=a2[i]){
                fl=1;
                break;
            }
        }

        Node* tr=NULL;
        if(fl!=1){
            Node* hh2=NULL;
            hh2=f2->head;
            while (hh2!=NULL){
                printf("%c",hh2->data);
                hh2=hh2->next;
            }
            printf(" ");
            
            flag=1;
                for (int i=0;i<ll;i++){
                
                a2[i]=0;

    }

        
        
        
        tr=head;
        tr=tr->prev;
        while(head->data!=' ' && head->data!='\n'){
            Node* ffr=NULL;
            ffr=head;
            head=head->next;
            free(ffr);
        }
        if(head->data!='\n'){
        Node* ffr=NULL;
        ffr=head;
        head=head->next;
        free(ffr);
        tr->next=head;
        head->prev=tr;
        }else{
            tr=tr->prev;
            free(tr->next);
            tr->next=head;
            head->prev=tr;
        }
        }else{
            while(head->data!=' ' && head->data!='\n'){
                head=head->next;
            }
            if(head->data!='\n'){
            head=head->next;
            }
        }
        fl=0;
        if(head->data=='\n'){
            if(flag==1){

            Node* hh1=NULL;
            hh1=f->head;
            while (hh1!=NULL){
                printf("%c",hh1->data);
                hh1=hh1->next;
            }
            printf(" ");
            flag=0;
            

            Node* ttr=NULL;
            ttr=pr1;
            ttr=ttr->prev;
            while(pr1->data!=' ' && pr1->data!='\n'){
            Node* ffr=NULL;
            ffr=pr1;
            pr1=pr1->next;
            free(ffr);
        }
        
        if(pr1->data!='\n'){
        Node* fffr=NULL;
        fffr=pr1;
        pr1=pr1->next;
        free(fffr);
        
        
        }
        if(ttr!=NULL){
            
        ttr->next=pr1;
        pr1->prev=ttr;
        }else{
            pr1->prev=NULL;
        }
        

            }else{
                while(pr1->data!=' ' && pr1->data!='\n'){
                    pr1=pr1->next;
                }
                if(pr1->data!='\n'){
                    pr1=pr1->next;
                }
            }
            
            break;
        }
        
        
        new_list(f2,head);

        ht2=f2->head;

        }
        if(pr1->data=='\n'){
            break;
        }
    new_list(f,pr1);

    ht1=f->head;

    head=pr1;
    while (head->data!=' ' && head->data!='\n'){
        head=head->next;
    }
    if(head->data=='\n'){
        
        break;
    }else{
        head=head->next;
    }
    
    new_list(f2,head);

    ht2=f2->head;
    
    }
   

    while(pr1->prev!=NULL){
            pr1=pr1->prev;
        }
    list->head=pr1;


    


}



    


void delete_t(List* list,int t){
    Node* head=list->head;
    for (int i=1;i!=t;i++){
        if(head->data!=' '){
        head=head->next;
        }else{
            head=head->next;
            i--;
        }
    }
    head->next->prev=head->prev;
    head->prev->next=head->next;
    free(head);

}


int main() {
    Node* head = NULL;
    Node* current = NULL;
    char ch;
    printf("Введите строку");
    while ((ch = getchar()) != EOF) {
        Node* newNode = createNode(ch);
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            newNode->prev=current;
            current = newNode;
        }
    }

    List* list=malloc(sizeof(List)) ;
    list->head=head;
    Node* ss = NULL;

        int t;
        
    printf("Выедите константу: ");
    scanf("%d",&t);
    delete_t(list,t);

    while(head!=NULL){
        list->head=head;  
        printf("\"");                   
        processString(list);
        
        
        printList(list);
        printf("\"\n");
        head=list->head;
        while(head->data!='\n'){
            ss=head;
            head=head->next;
            free(ss);
        }
            ss=head;
            head=head->next;
            head->prev=NULL;
            free(ss);
    }
    

    /*
    // Обработка и вывод строк
    Node* currentString = head;
    Node* startOfCurrentString = head;
  
    while (currentString != NULL) {
        if (currentString->data == '\n') {
            // Завершение строки, обработка и вывод
            processString(startOfCurrentString);
            printf("\"");
            printList(startOfCurrentString);
            printf("\"\n");


        }
        prev = currentString;
        currentString = currentString->next;
    }

    // Очистка памяти после обработки последней строки
    deleteList(head);
*/
    return 0;
}