#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *process(char *text){
    if (text == NULL){
        return NULL;
    }
    int len=strlen(text);
    char *res=NULL;
    res=(char*)malloc(len*2*sizeof(char));
    char *ss=strdup(text);
    printf("%d\n",len);
    while(ss[0]==' '){
        for (int i=0;i<len-1;i++){
            ss[i]=ss[i+1];
        }
        len-=1;
    }
    ss=realloc(ss,len+1*sizeof(char));
    ss[len]='\0';
    printf("%d\n%s\n",len,ss);

    char *w=strtok(ss," ");
    int k=1;
    int ts=0;
    int lenw;
    while (w!=NULL){
        if (k%2==0){
            lenw=strlen(w);
            memcpy(res + ts,w,lenw);
            ts+=lenw;
            res[ts]=' ';
            ts+=1;
            
        }
        lenw=strlen(w);
        memcpy(res + ts,w,lenw);
        ts+=lenw;
        res[ts]=' ';
        ts+=1;
        w=strtok(NULL," ");
        k+=1;
        printf("%s\n",res);
        printf("%s\n",w);
    }

    printf("%s\n%d\n",res,ts);

    res=realloc(res,ts);

    

    res[ts-1]='\0';
    
    


    free(ss);
    free(w);
    return res;
}

int main(){
    char *text = calloc(300, sizeof(char));
    strcpy(text, "      Mama papa Mama    Ada Sasha  Mama Nina Toma");
    char *text_pro = calloc(100, sizeof(char));
    text_pro = process(text);
    printf("%s\n", text_pro);
    free(text);
    free(text_pro);
}
