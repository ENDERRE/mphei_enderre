#ifndef _LIB_ARRAY_
#define _LIB_ARRAY_
void clearBuf(){
    fflush(stdin);
 }
void start_array(int *s[],int *len_s){
    
    printf("print len: ");
    if(scanf("%d",&*len_s)!=1){
        clearBuf();
        printf("print len: ");}
    printf("print elements: ");
    *s=(int*)realloc(*s,(*len_s)*sizeof(int));
    for(int i=0;i<*len_s;i++){
    scanf("%d",&(*s)[i]);
    
    }
}
void print_array(int *s[],int *len_s){
    printf("my array: ");
    for (int i=0;i<*len_s;i++){
        printf("%d ", (*s)[i]);
    }
    printf("\n");
}
void go_left_to(int *s[],int *len_s, int *i, int *count){
    if (*count>=2){
    for (int t=*i;t<*len_s;t++){
        (*s)[t-(*count)]=(*s)[t];
    }
    
    (*len_s)-=(*count);
    (*i)-=(*count);
    }
    *count=1;
}
void scan_to_check(int *s[], int *len_s){

    int *k=(int*)malloc((*len_s)*sizeof(int));
    int len_k=0, count=1;
    for (int i=1;i<(*len_s);i++){
        if ((*s)[i]==(*s)[i-1]){
            if (count<2){
                (k)[len_k]=(*s)[i];
                (k)[len_k+1]=(*s)[i-1];
                len_k+=2;
            }else{
                (k)[len_k]=(*s)[i];
                len_k+=1;
            }
            count+=1;
        }else{
            go_left_to(&(*s),&(*len_s),&i,&count);
        }
    }
    if (count>=2){*len_s-=count;}
    *s=(int*)realloc(*s,(*len_s)*sizeof(int));
    printf("new ");
    if(len_k>0){print_array(&k,&len_k);
    }else{printf("my array empty\n");}
    free(k);
}
void print_menu(){
    printf(" ____________________________________________ \n");
    printf("| liste de ce que je peux fair               |\n");
    printf("|                                            |\n");
    printf("| (a) Инициализация массива                  |\n");
    printf("| (b) Вставка нового элемента по номеру      |\n");
    printf("| (c) Удаление элемента                      |\n");
    printf("| (d) Индивидуальное задание                 |\n");
    printf("| (e) Вывод содержимого массива              |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}
void delete_element(int *s[],int *len_s){
    int i;
    do{
    printf("Enter position: ");
    scanf("%d",&i);
    }while(i>*len_s || i==0);
    for (i;i<*len_s;i++){
        (*s)[i-1]=(*s)[i];
    }
    *len_s-=1;
    *s=(int*)realloc(*s,(*len_s)*sizeof(int));
}

void new_element(int *s[],int *len_s){
    int i;
    do{printf("Enter position: ");
    scanf("%d",&i);
    }while(i>(*len_s) || i==0);
    *len_s+=1;
    *s=(int*)realloc(*s,(*len_s)*sizeof(int));

    for(int k=(*len_s-1);k>=i;k--){
        (*s)[k]=(*s)[k-1];
    }
    printf("Enter element: ");
    scanf("%d",&(*s)[i-1]);
    

} 

int main(){
    int len_s=0, flag=1, scan=0, prin=0;
    int *s=(int*)malloc(0);
    char w;


    do{
        system("cls");
        print_menu();
        if (scan==1){
            scan_to_check(&s,&len_s);
            scan=0;
        }
        if (len_s>0 && prin==1){
            print_array(&s,&len_s);
            prin=0;
        }
        printf("\nEnter what you want: ");
        if(scanf("%c",&w)==EOF){w='f';
        }else if(w=='f'){w='h';}
        
        
        switch(w){
            case 'a':
                start_array(&s,&len_s); break;
            case 'b':
                if(len_s>0){
                new_element(&s,&len_s);}
                break;
            case 'c':
                if(len_s>0){
                delete_element(&s,&len_s);} 
                break;
            case 'd':
                scan=1; prin=1; break ;
            case 'e':
                prin=1; break ;
            case 'f':
                flag=0; break;
            default:
                break;
        }
        clearBuf();
        
    }while(flag==1);

    system("cls");



}
#endif