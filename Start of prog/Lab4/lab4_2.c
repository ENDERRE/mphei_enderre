#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void str_tok(char *num[],char *s[],int *len_s,int *len_n,char pm[],int *ppp){
    
    (*len_n)=0;
    (*num)=NULL;

    for (int i=(*ppp);i<*len_s;i++){
        if ((*s)[i]==(pm)[0] || (*s)[i]==(pm)[1] || (*s)[i]=='\0'){
            *ppp=i+1;
            (*num)=(char*)realloc(*num,(*len_n+1)*sizeof(char));
            (*num)[*len_n]='\0';
            break;
        }
        (*len_n)+=1;
        (*num)=(char*)realloc(*num,(*len_n)*sizeof(char));
        (*num)[*len_n-1]=(*s)[i];
        
    }
    
}



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
            }
            *len-=1;
        }
        if (i<*len-1 && (((*s)[i]=='-' && (*s)[i+1]=='-') || ((*s)[i]=='+' && (*s)[i]=='+'))){
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
    int len_n,len_pp=0,pp=0,k=0,ppp=0;

    char *num=NULL;
    str_tok(&num,&(*s),&(*len),&len_n,pm,&ppp);

    while(num!=NULL){

        len_pp+=len_n;

        charint(&num,&len_n,&asmr,&pp);

        str_tok(&num,&(*s),&(*len),&len_n,pm,&ppp);

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

    char buf[81]={0};
    char *s=NULL,*ss=NULL;
    int len=0,ff;
    int n,asmr;
    clock_t start, fin;
    double time;
    printf("Введите выражение: ");
    do{

        n=scanf("%80[^\n]",buf);

        if(n<0){
            
        }else if(n>0){
            int chunk_len=strlen(buf);
            int str_len=len+chunk_len;
            s=realloc(s,str_len+1);
            memcpy(s+len,buf,chunk_len);

            len=str_len;
        }else{
            fflush(stdin);
        }
    }while(n>0);
    s[len]='\0';
    len+=1;
    fflush(stdin);
    start=clock();
    delete_pass(&s,&len,&ff);
    while(ff==1){
        system("cls");
        print_menu();

        len=1;
        s = (char*) malloc(sizeof(char));
        printf("Есть нечитаемые символы\nВведите выражение: ");

        do{

        n=scanf("%80[^\n]",buf);

        if(n<0){
            
        }else if(n>0){
            int chunk_len=strlen(buf);
            int str_len=len+chunk_len;
            s=realloc(s,str_len+1);
            memcpy(s+len,buf,chunk_len);

            len=str_len;
        }else{
            fflush(stdin);
        }
    }while(n>0);
    s[len]='\0';
    len+=1;
        
        
        delete_pass(&s,&len,&ff);
    }
    ss=realloc(ss,len);
    memcpy(ss,s,len);

    
    inter(&s,&len,&ss,&asmr);
    

    
    system("cls");
    print_menu();
    fin=clock();
    printf("Ответ: %s=%d\n", ss, asmr);
    time=(double)(fin-start);
    printf("%f\n",time);
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
