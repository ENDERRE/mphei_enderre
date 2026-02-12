#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>

int replaceWord(char *name, char *oldWord, char *newWord) {
    FILE* file=NULL;
    file=fopen(name,"r+");
    if (file == NULL) {
        return 0;
    }
    char* tempn="temp.txt";
    if (name==tempn){
        tempn="temp1.txt";
    }
    FILE *tempfile = NULL;
    tempfile=fopen(tempn, "w");
    if (!tempfile) {
        fclose(file);
        return 0;
    }


    char *buffer=NULL;
    size_t len;

    while(getline(&buffer,&len,file)!=EOF){
        char *pos;

        while ((pos = strstr(buffer, oldWord)) != NULL) {
            fwrite(buffer, sizeof(char), pos - buffer, tempfile);
            fputs(newWord, tempfile);
            strcpy(buffer, pos + strlen(oldWord));
        }
        fputs(buffer, tempfile);
    }
    remove(name);
    rename(tempn,name);
    fclose(tempfile);
    free(buffer);
    return 1;
}

void print_menu(){
    printf(" ____________________________________________ \n");
    printf("| Нажать ENTER чтобы продолжить              |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}
void clearbuf(){
    scanf("%*s[^\n]");
}
int input_and_check(char *s,char str[]){
    int k,c=1;
    char *ss=NULL;
    k=scanf("%c", s);


    if(k==(-1)) return 0;
    
    if(k==0) clearbuf();

    ss=strchr(str,*s);
    if(ss!=NULL){
        c=0;
        ss=NULL;
    }
    while (!isalpha(*s) || c==1){
        if(k == 0) clearbuf();
        printf("Ошибка ввода\n");
        printf("Ввод: ");
        
        k=scanf("%s", s);

        ss=strchr(str,*s);
        if(ss!=NULL){
            c=0;
           
        }else{
            c=1;
            
        }
        ss=NULL;
        if(k==(-1)) return 0;
        
        if(k==0) clearbuf();

    }
    return 1;
}
int main() {     
    char choice;
    char *name = NULL;
    char *oldw=NULL, *neww=NULL; 
    int k=0;
    do {
        print_menu();
        printf("Ввод: ");
        if(input_and_check(&choice,"\n")==0) {
            return 0;
        }
        switch (choice) {
            case '\n': 
                name=readline("Ввод имени файла: ");
                oldw=readline("Ввод заменяемого слова: ");
                neww=readline("Ввод слова для замены: ");
                if(replaceWord(name,oldw,neww)==0){
                    printf("Ошибка при открытии файла: %s\n", strerror(errno));
                }
                free(name);
                break;
    

        }

        
    } while (1);
}



