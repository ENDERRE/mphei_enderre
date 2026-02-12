#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void print_menu(){
    printf(" ____________________________________________ \n");
    printf("| Привет, я умнею решать выражения используя |\n");
    printf("| операции сложения и вычитания              |\n");
    printf("|                                            |\n");
    printf("| -Enter чтобы ввести выражение              |\n");
    printf("| -Ctrl + D чтобы завершить программу        |\n");
    printf("|____________________________________________|\n\n");
}


void size_nu(char *s[],int *len){
    (*len)=0;

    while((*s)[*len]!='\0'){
        (*len)++;
    }
}
void abcd(char s,char abcde[],int *ff){
    int i=0;
    *ff=0;
    while(abcde[i]!='\0'){
        if(abcde[i]==s){
            *ff=1;
            break;
        }
        
        i++;
    }
    
}
void delete_pass(char *s[],int *len,int *ff){
    char abcde[]="qwertyipadfghjklzxcvbnmйцукенгшщзхъёфывапролджэячсмитьбю/|\0";
    for (int i=0;i<*len;i++){
        abcd((*s)[i],abcde,&(*ff));
        if((*ff)==1){
            break;
        }
        if ((*s)[i]==' '){
            for (int t=i;t<(*len)-1;t++){
                (*s)[t]=(*s)[t+1];
                i-=1;
            }
            *len-=1;
        }
        if (i<*len-1 && (((*s)[i]=='-' && (*s)[i+1]=='-') || ((*s)[i]=='+' && (*s)[i+1]=='+'))){
            for (int t=i;t<(*len)-1;t++){
                (*s)[t]=(*s)[t+1];
            }
            *len-=1;
        }
    }
    (*s)=(char*)realloc(*s,*len);
}

void charint(char *num[],int *len,int *asmr,int *pp){
    if((*pp)==0){
        for (int i=0;i<*len;i++){
            (*asmr)+=(((*num)[i]-'0')*pow(10,(*len)-i-1));
        }
    }else{
        for (int i=0;i<*len;i++){
            (*asmr)-=(((*num)[i]-'0')*pow(10,(*len)-i-1));
        }
    }
}
void inter(char *s[],int *len,char *ss[],int *amr){
    int asmr=0;
    char pm[]="+-";
    int len_n,len_pp=0,pp,k=0;
    if((*s)[0]=='-'){
        pp=1;
    }else{
        pp=0;
    }
    char *num=strtok((*s),pm);
    
    while(num!=NULL){
        size_nu(&num,&len_n);
        len_pp+=len_n;

        charint(&num,&len_n,&asmr,&pp);

        num=strtok(NULL,pm);

        if((*ss)[len_pp+k]=='+'){
            pp=0;
        }else{
            pp=1;
        }
        k++;
    }
    (*amr)=asmr;
}

void math(){
    char *s = NULL, c,*ss=NULL;
    int len ,asmr,ff=0;
    ss = (char*) malloc(sizeof(char));
    clock_t start, fin;
    double time;
    
    len=1;
    s = (char*) malloc(sizeof(char));
    printf("Введите выражение: ");

    

    while((c=getchar()) != '\n') {
        s[len - 1] = c;
        len++;

        s= (char*) realloc(s, len); 
    }
    s[len - 1] = '\0';
    fflush(stdin);
    start=clock();
    delete_pass(&s,&len,&ff);
    
    
    while(ff==1){
        system("cls");
        print_menu();

        len=1;
        s = (char*) malloc(sizeof(char));
        printf("Есть нечитаемые символы\nВведите выражение: ");

        
        
        while((c=getchar()) != '\n') {
            s[len - 1] = c;
            len++;

            s= (char*) realloc(s, len); 
        }
        s[len - 1] = '\0';
        fflush(stdin);
        
        delete_pass(&s,&len,&ff);
    }

    memcpy(ss,s,len);
    inter(&s,&len,&ss,&asmr);
    system("cls");
    print_menu();
    printf("Ответ: %s=%d\n", ss, asmr);
    fin=clock();
    time=(double)(fin-start);
    //printf("%f\n",time);
    fflush(stdin);
    free(s);
    free(ss);
}



int main(){
    char w;
    int flag=0,mathp=0;
    
    

    do{
        system("cls");
        print_menu();
        if(mathp==1){
            
            math();
            mathp=0;
            
        }
        

    fflush(stdin);
    printf("Что мне делать: ");
    if(scanf("%c",&w)==EOF){w='f';
        }else if (w=='f'){
            w='p';
        }      
    fflush(stdin);
    while(w!='f' && w!='\n'){
        system("cls");
        print_menu();
        printf("я не могу распознать такое\n");
        printf("Введите один из вариантов: ");
        if(scanf("%c",&w)==EOF){w='f';
        }else if (w=='f'){
            w='p';
        }      
        fflush(stdin);
    }
    switch (w)
    {
        case 'f':
            flag=1; break;

        default:
            mathp=1; break;
        }

    }while(flag==0);
   
    return 0;
}
