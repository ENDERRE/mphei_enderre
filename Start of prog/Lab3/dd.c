#include <stdio.h>
#include <stdlib.h>
void print_array(int *s[],int *len_s){
    printf("my array: ");
    for (int i=0;i<*len_s;i++){
        printf("%d ", (*s)[i]);
    }
    printf("\n");
}

void start_array(int *s[],int *len_s){
    
    printf("print len: ");
    scanf("%d",&*len_s);
    printf("print elements: ");
    *s=(int*)realloc(*s,(*len_s)*sizeof(int));
    for(int i=0;i<*len_s;i++){
    scanf("%d",&(*s)[i]);
    
    }
}
void new_element(int *s[],int *len_s){
    int i;
    printf("Enter position: ");
    scanf("%d",&i);
    *len_s+=1;
    *s=(int*)realloc(*s,(*len_s)*sizeof(int));
    print_array(&(*s),&(*len_s));
    (*s)[*len_s-1]=2;
    printf("%d\n",(*s)[*len_s-1]);
    print_array(&(*s),&(*len_s));
    for(int k=(*len_s-1);k>=i;k--){
        printf("%d\n",(*s)[k]);
        (*s)[k]=(*s)[k-1];
    }
    printf("Enter element: ");
    scanf("%d",&(*s)[i-1]);
    

} 
int main(){
    char u;
    int len_s=0, flag=1,scan=0;
    int *s=(int*)malloc(0);
    char w,t;
    scanf("%c",&flag);
    printf("%c\n",flag);
    if(scanf("%d",&scan)==00){
        printf("%d\n",scan);
        printf("Dood\n");
    }else{
        printf("%d\n",scan);
        printf("No\n");
    }
    start_array(&s, &len_s);
}