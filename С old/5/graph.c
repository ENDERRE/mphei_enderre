
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>


#include"global.h"
#include "graph_s.h"
#include "graph.h"



int add_graph(graph** G){
    (*G)=malloc(sizeof(graph));
    if(!(*G)) return 0;
    (*G)->enter=NULL;
    (*G)->size=0;
    (*G)->matrix=NULL;

    return 1;
}
int search_room(graph* G,char* info){
    if(G->enter==NULL) return 0;

    for(int i=0;i<G->size;i++){
        if(strcmp(G->enter[i]->name,info)==0){
            return i+1;
        }
    }
    return 0;
}
int add_room(graph* G,char* info, enum ro type){
    if(search_room(G,info)!=0)return 0;

    room* new=NULL;
    new=malloc(sizeof(room));

    if(!new) return 0;
    new->name=info;
    new->type=type;

    G->size+=1;
    if(G->size==1){
        G->matrix=NULL;
        G->matrix=malloc(sizeof(int*)*2);
        if(!G->matrix) return 0;

        G->matrix[0]=NULL;
        G->matrix[0]=malloc(sizeof(int));
        if(!G->matrix[0]) return 0;
        G->matrix[0][0]=0;

        G->enter=NULL;
        G->enter=malloc(sizeof(room*));
        if(!G->enter) return 0;
        G->enter[0]=new;

    }else{
        G->matrix=realloc(G->matrix,sizeof(int*)*G->size);
        G->matrix[G->size-1]=calloc(G->size,sizeof(int));
        for(int i=0;i<G->size-1;i++){
            G->matrix[i]=realloc(G->matrix[i],sizeof(int)*G->size);
            G->matrix[i][G->size-1]=0;
        }

        G->enter=realloc(G->enter,sizeof(room*)*G->size);
        G->enter[G->size-1]=new;

    }

    return 1;
}
int add_road(graph* G, char* fo, char* to,int si){
    int st,end;
    if((st=search_room(G,fo))==0){
        return 0;        
    }
    if((end=search_room(G,to))==0){
        return 0;        
    }

    G->matrix[st-1][end-1]=si;
    return 1;

}
int print_graph(graph* G){
    FILE *fp;
    fp = fopen("graph.dot", "w");

    if(fp == NULL) {
        
        return 0;
    }
    fprintf(fp, "digraph G {\n");

    for(int i=0;i<G->size;i++){
        fprintf(fp, "%d [label=\"%s %d\"];\n",i,G->enter[i]->name, G->enter[i]->type);
    }
    for(int i=0;i<G->size;i++){
        for(int j=0;j<G->size;j++){
            if(G->matrix[i][j]!=0){
                fprintf(fp,"%d->%d [label=\" %d \"];\n",i,j,G->matrix[i][j]);
            }
        }
    }

    fprintf(fp, "}\n");
    fclose(fp);
    system("dot -Tpng graph.dot -o graph.png");
    return 1;

}
void free_graph(graph* G){
    for(int i=0;i<G->size;i++){
        free(G->matrix[i]);
        free(G->enter[i]->name);
        free(G->enter[i]);
    }
    free(G->enter);
    free(G->matrix);
}
int del_room(graph* G,char* name){
    int kk;
    if((kk=search_room(G,name))==0) return 0;

    room* temp=G->enter[kk-1];
    G->size-=1;
    for(int i=kk-1;i<G->size;i++){
        G->enter[i]=G->enter[i+1];
    }
    free(temp->name);
    free(temp);
    G->enter=realloc(G->enter,G->size*sizeof(room));
    free(G->matrix[kk-1]);
    for(int i=kk-1;i<G->size;i++){
        G->matrix[i]=G->matrix[i+1];
    }
    G->matrix=realloc(G->matrix,G->size*sizeof(int*));
    for(int i=0;i<G->size;i++){
        for(int j=kk-1;j<G->size;j++){
            G->matrix[i][j]=G->matrix[i][j+1];
        }
    }

    return 1;
}
int dell_road(graph* G,char* fo,char* to){
    int st,end;
    if((st=search_room(G,fo))==0){
        return 0;        
    }
    if((end=search_room(G,to))==0){
        return 0;        
    }

    G->matrix[st-1][end-1]=0;
    return 1;
}
void print_matrix(graph* G){
    printf("\n\n");
    for(int i=0;i<G->size;i++){
        printf("%s  ",G->enter[i]->name);
        for(int j=0;j<G->size;j++){
            if(G->matrix[i][j]!=0)
                printf("%s ",G->enter[j]->name);
        }
        printf("\n");
    }
}
void print_type(){
    printf("\n\n");
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (1) ENTER                                  |\n");
    printf("| (2) CORIDOR                                |\n");
    printf("| (3) EXIT                                   |\n");
    printf("|____________________________________________|\n");
}
int change_room(graph* G,char* name,enum ro pp){
    int pos;
    if((pos=search_room(G,name))==0) return 0;


    G->enter[pos-1]->type=pp-1;
    return 1;
}
int print_enter(graph* G){
    int k=0;
    for(int i=0;i<G->size;i++){
        if(G->enter[i]->type==enter){
            printf("\n%s\n",G->enter[i]->name);
            k++;
        }
    }
    if(k!=0) return 1;
    return 0;
}
int print_exit(graph* G){
    int k=0;
    for(int i=0;i<G->size;i++){
        if(G->enter[i]->type==ex){
            printf("\n%s\n",G->enter[i]->name);
            k++;
        }
    }
    if(k!=0) return 1;
    return 0;
}
void printSolution(int* dist, int n,graph* G) {
    printf("Вершина \t Расстояние от источника\n");

    if(dist[n]!=INT_MAX){
        printf("%s \t\t %d\n", G->enter[n]->name, dist[n]);
    }else{
        printf("\nno more\n");
    }
    
}


void bellmanFord(graph* G, int src, int to) {
    int size=G->size;

    int *dist=malloc(sizeof(int)*size);
     int *prev=malloc(sizeof(int)*size);
    int h=0;
    for (int i = 0; i < size; i++)
        dist[i] = INT_MAX;
    dist[src-1] = 0;
    int nn=0;

    for (int i = 0; i < size; i++) {
        for (int u = 0; u < size; u++) {
            for (int v = 0; v < size; v++) {
                if (G->matrix[u][v] && G->matrix[u][v] != 0 && dist[u]!=INT_MAX && dist[u] + G->matrix[u][v] < dist[v]){
                    dist[v] = dist[u] + G->matrix[u][v];
                    for(int k=0;k<h;k++){
                        if(u==prev[k]){
                            nn=1;
                        }
                }
                    if(nn==0) {
                        
                        
                        prev[h]=u;
                        h++;
                        
                    }
                    nn=0;
                    }
                    
            }
        }
    }

    
    for(int i=0;i<h;i++){
        printf("\n%s ",G->enter[prev[i]]->name);
    }
    printSolution(dist,to-1,G);
    free(prev);
    free(dist);
}
int find_fast(graph* G,char* fir,char* to){
    int posf,post;
    posf=search_room(G,fir);
    post=search_room(G,to);
    bellmanFord(G, posf, post);
    return 0;
}
void print_large(int ** dist,char* name,graph *G){
    int pos;
    pos=search_room(G,name);

    int min=INT_MAX;
    int k;
    for(int i=0;i<G->size;i++){

        if(G->enter[i]->type==ex){
            if(dist[pos-1][i]<min && dist[pos-1][i]!=0){
                min=dist[pos-1][i];
                k=i;
            }

        }

    }
    if(min!=INT_MAX){
        printf("len: %d %s\n",min,G->enter[k]->name);
    }else{
        printf("no more \n");
    }

}
void floydWarshall(graph* G, char* name) {
    int **dist=malloc(sizeof(int*)*G->size);
    for(int i=0;i<G->size;i++){
        dist[i]=malloc(sizeof(int)*G->size);
    }
    

    for (int i = 0; i < G->size; i++) {
        for (int j = 0; j < G->size; j++) {
            if(G->matrix[i][j]==0){
                dist[i][j]=INT_MAX;
            } else{
                dist[i][j]=G->matrix[i][j];
            }
        }
    }

    for (int k = 0; k < G->size; k++) {
        for (int i = 0; i < G->size; i++) {
            for (int j = 0; j < G->size; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    print_large(dist, name,G);
    for(int i=0;i<G->size;i++){
        free(dist[i]);
    }
    free(dist);
}







struct Queue* createQueue(graph* G) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->items=malloc(sizeof(int)*G->size);
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    if (q->rear == -1) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int value,graph* G) {
    if (q->rear == G->size - 1)
        printf("Queue is full");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty");
        return -1;
    } else {
        value = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return value;
    }
}

void breadthFirstSearch(graph* G, int startVertex) {
    int* visited=malloc(sizeof(int)*(G->size));
    for (int i = 0; i < G->size; i++) {
        visited[i] = 0;
    }

    struct Queue* q = createQueue(G);
    visited[startVertex] = 1;
    enqueue(q, startVertex,G);

    printf("BFS Traversal: ");
    int k=0;
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%s ", G->enter[currentVertex]->name);
        if( G->enter[currentVertex]->type==ex) k++;

        for (int i = 0; i < G->size; i++) {
            if (G->matrix[currentVertex][i]!=0 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i,G);
            }
        }
    }
    if(k!=0){
        printf("\nEXIT GOOD\n");
    }else{
        printf("\nno more \n");
    }
        
     
    printf("\n\n");
    free(visited);
    free(q->items);
    free(q);
}