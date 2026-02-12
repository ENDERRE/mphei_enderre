#include <stdio.h>
#include <stdlib.h>
 
 typedef struct Node{
     int data;
     struct Node *next;
 }Node;
 
 typedef struct List{
     Node *head;
 }List;
 
 void process(List *list){
     Node *item = list->head;
     int flag = 4;
     int n = 0;
     Node *last_item;
     Node *new_start;
     Node *new_finish;
     Node *last_start;
     while (item != NULL){
        if (n == flag){
            new_start = item;
            new_finish = last_item;
            last_start = list->head;
        }
        last_item = item;
        item = item->next;
        n += 1;
     }
     last_item->next = list->head;
     list->head = new_start;
     new_finish->next = NULL;
         
     item = list->head;
     while (item != NULL){
        printf("%3d", item->data);
        item = item->next;
    }
}
 
 int main(){
     int array[6] = {1, -2, 3, 4, -5, 6};
     int len = 6;
     Node *first = (Node*)malloc(sizeof(Node));
     first->data = array[0];
     first->next = NULL;
     List *list = (List*)malloc(sizeof(List));
     list->head = first;
     Node *prev = first;
     for (int i = 1; i < len; ++i){
        Node *elem = (Node*)malloc(sizeof(Node));
        elem->data = array[i];
        prev->next = elem;
        //printf("%d %d\n", prev->data, elem->data);
        prev = elem;
     }
     process(list);
     free(first);
     free(list);
 }
