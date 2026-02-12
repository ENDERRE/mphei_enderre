#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef enum {debug, info, warn, error, fatal} LogLevel;

typedef struct {
    int id;
    LogLevel level;
    char text[100];
} LogEntry;


int comupid(const void *x,const void *y){
    LogEntry *xx =(LogEntry*)x;
    LogEntry *yy =(LogEntry*)y;
    return (xx)->id-yy->id;

}
int comdownid(const void *x,const void *y){
    LogEntry *xx =(LogEntry*)x;
    LogEntry *yy =(LogEntry*)y;
    return (yy)->id-xx->id;

}
int comuplevel(const void *x,const void *y){
    LogEntry *xx =(LogEntry*)x;
    LogEntry *yy =(LogEntry*)y;
    return (xx)->level-yy->level;

}
int comdownlevel(const void *x,const void *y){
    LogEntry *xx =(LogEntry*)x;
    LogEntry *yy =(LogEntry*)y;
    return (yy)->level-xx->level;

}
int comuptext(const void *x,const void *y){
    LogEntry *xx =(LogEntry*)x;
    LogEntry *yy =(LogEntry*)y;
    return strcmp((xx)->text, (yy)->text);

}
int comdowntext(const void *x,const void *y){
    LogEntry *xx =(LogEntry*)x;
    LogEntry *yy =(LogEntry*)y;
    return strcmp((yy)->text, (xx)->text);

}

void outputLogArray(LogEntry* array, int size) {
    printf("\n\n");
    for (int i = 0; i < size; i++) {
        printf("id: %d, level: %d, text: %s\n", array[i].id, array[i].level, array[i].text);
    }
    printf("\n");
}
void print_updown(){
    printf("\n1) UP\n");
    printf("2) Down\n");

}
void gnomeSort(LogEntry* *array, int size,int op,int ap) {
    int index = 0;
    LogEntry temp;


    switch (ap){
        case 1:
            //UP
            switch (op){
                case 1:
                    //id
                        while (index < size) {
                            if (index == 0 || (*array)[index].id >= (*array)[index - 1].id) {
                                index++;
                            } else {
                                temp=(*array)[index];
                                (*array)[index]=(*array)[index-1];
                                (*array)[index-1]=temp;

                                index--;
                            }
                        }
                    break;
                case 2:
                    //varn
                        while (index < size) {
                            if (index == 0 || (*array)[index].level >= (*array)[index - 1].level) {
                                index++;
                            } else {
                                temp=(*array)[index];
                                (*array)[index]=(*array)[index-1];
                                (*array)[index-1]=temp;

                                index--;
                            }
                        }
                    break;
                case 3:
                    //txt
                        while (index < size) {
                            if (index == 0 || strcmp((*array)[index].text, (*array)[index-1].text) < 0) {
                                index++;
                            } else {
                                temp=(*array)[index];
                                (*array)[index]=(*array)[index-1];
                                (*array)[index-1]=temp;

                                index--;
                            }
                        }
                        break;
        default:
            break;
    }
            break;
        case 2:
            //DOWN
            switch (op){
                case 1:
                    //id
                        while (index < size) {
                            if (index == 0 || (*array)[index].id <= (*array)[index - 1].id) {
                                index++;
                            } else {
                                temp=(*array)[index];
                                (*array)[index]=(*array)[index-1];
                                (*array)[index-1]=temp;

                                index--;
                            }
                        }
                    break;
                case 2:
                    //varn
                        while (index < size) {
                            if (index == 0 || (*array)[index].level <= (*array)[index - 1].level) {
                                index++;
                            } else {
                                temp=(*array)[index];
                                (*array)[index]=(*array)[index-1];
                                (*array)[index-1]=temp;

                                index--;
                            }
                        }
                    break;
                case 3:
                    //txt
                        while (index < size) {
                            if (index == 0 || (strcmp((*array)[index].text, (*array)[index-1].text) > 0)) {
                                index++;
                            } else {
                                temp=(*array)[index];
                                (*array)[index]=(*array)[index-1];
                                (*array)[index-1]=temp;

                                index--;
                            }

                        }
                        break;
        default:
            break;
    }

    }
}




void pairInsertionSort(LogEntry* *arr, int n,int op,int ap) {
    LogEntry key;
    LogEntry keym;
    int p;


    switch (ap){
        case 1:
            //UP
            switch (op){
                case 1:
                    //id
                        for (int i = 1; i < n; i += 2) {
                            if((*arr)[i].id>(*arr)[i-1].id){
                                keym=(*arr)[i];
                                key=(*arr)[i-1];
                            }else{
                                key=(*arr)[i];
                                keym=(*arr)[i-1];
                            }
                        p=i;
                        while(p-2>=0 && (*arr)[p-2].id>keym.id){
                                (*arr)[p]=(*arr)[p-2];
                                p--; 
                        }
                        (*arr)[p]=keym;
                        
                        while(p-1>0 && (*arr)[p-1].id>key.id){
                                (*arr)[p-1]=(*arr)[p-2];
                                p--;
                        }
                        (*arr)[p-1]=key;
                        } 
                        p=n-1;
                        key=(*arr)[p];
                        while(p>0 && (*arr)[p-1].id>key.id){
                                (*arr)[p]=(*arr)[p-1];
                                p--;
                        }
                    break;
                case 2:
                    //varn
                        for (int i = 1; i < n; i += 2) {
                            if((*arr)[i].level>(*arr)[i-1].level){
                                keym=(*arr)[i];
                                key=(*arr)[i-1];
                            }else{
                                key=(*arr)[i];
                                keym=(*arr)[i-1];
                            }
                        p=i;
                        while(p-2>=0 && (*arr)[p-2].level>keym.level){
                                (*arr)[p]=(*arr)[p-2];
                                p--; 
                        }
                        (*arr)[p]=keym;
                        
                        while(p-1>0 && (*arr)[p-1].level>key.level){
                                (*arr)[p-1]=(*arr)[p-2];
                                p--;
                        }
                        (*arr)[p-1]=key;
                        } 
                        p=n-1;
                        key=(*arr)[p];
                        while(p>0 && (*arr)[p-1].level>key.level){
                                (*arr)[p]=(*arr)[p-1];
                                p--;
                        }
                    break;
                case 3:
                    //txt
                        for (int i = 1; i < n; i += 2) {
                            if(strcmp((*arr)[i].text, (*arr)[i-1].text) < 0){
                                keym=(*arr)[i];
                                key=(*arr)[i-1];
                            }else{
                                key=(*arr)[i];
                                keym=(*arr)[i-1];
                            }
                        p=i;
                        while(p-2>=0 && strcmp((*arr)[p-2].text, keym.text) < 0 ){
                                (*arr)[p]=(*arr)[p-2];
                                p--; 
                        }
                        (*arr)[p]=keym;
                        
                        while(p-1>0 && strcmp((*arr)[p-1].text, key.text) < 0 ){
                                (*arr)[p-1]=(*arr)[p-2];
                                p--;
                        }
                        (*arr)[p-1]=key;
                        } 
                        p=n-1;
                        key=(*arr)[p];
                        while(p>0 && strcmp((*arr)[p-1].text, key.text) < 0 ){
                                (*arr)[p]=(*arr)[p-1];
                                p--;
                        }
                    break;
                default:
                    break;
                }
            break;
        case 2:
            //DOWN
            switch (op){
                case 1:
                    //id
                        for (int i = 1; i < n; i += 2) {
                            if((*arr)[i].id<(*arr)[i-1].id){
                                keym=(*arr)[i];
                                key=(*arr)[i-1];
                            }else{
                                key=(*arr)[i];
                                keym=(*arr)[i-1];
                            }
                        p=i;
                        while(p-2>=0 && (*arr)[p-2].id<keym.id){
                                (*arr)[p]=(*arr)[p-2];
                                p--; 
                        }
                        (*arr)[p]=keym;
                        
                        while(p-1>0 && (*arr)[p-1].id<key.id){
                                (*arr)[p-1]=(*arr)[p-2];
                                p--;
                        }
                        (*arr)[p-1]=key;
                        } 
                        p=n-1;
                        key=(*arr)[p];
                        while(p>0 && (*arr)[p-1].id<key.id){
                                (*arr)[p]=(*arr)[p-1];
                                p--;
                        }
                    break;
                case 2:
                    //varn
                        for (int i = 1; i < n; i += 2) {
                            if((*arr)[i].level<(*arr)[i-1].level){
                                keym=(*arr)[i];
                                key=(*arr)[i-1];
                            }else{
                                key=(*arr)[i];
                                keym=(*arr)[i-1];
                            }
                        p=i;
                        while(p-2>=0 && (*arr)[p-2].level<keym.level){
                                (*arr)[p]=(*arr)[p-2];
                                p--; 
                        }
                        (*arr)[p]=keym;
                        
                        while(p-1>0 && (*arr)[p-1].level<key.level){
                                (*arr)[p-1]=(*arr)[p-2];
                                p--;
                        }
                        (*arr)[p-1]=key;
                        } 
                        p=n-1;
                        key=(*arr)[p];
                        while(p>0 && (*arr)[p-1].level<key.level){
                                (*arr)[p]=(*arr)[p-1];
                                p--;
                        }
                    break;
                case 3:
                    //txt
                        for (int i = 1; i < n; i += 2) {
                            if(strcmp((*arr)[i].text, (*arr)[i-1].text) > 0){
                                keym=(*arr)[i];
                                key=(*arr)[i-1];
                            }else{
                                key=(*arr)[i];
                                keym=(*arr)[i-1];
                            }
                        p=i;
                        while(p-2>=0 && strcmp((*arr)[p-2].text, keym.text) > 0 ){
                                

                                (*arr)[p]=(*arr)[p-2];
                                p--; 
                                                                
                                
                        }
                        (*arr)[p]=keym;
                                                     
                        
                        while(p-1>0 && strcmp((*arr)[p-1].text, key.text) > 0 ){
                                (*arr)[p-1]=(*arr)[p-2];
                                p--;
                        }
                        (*arr)[p-1]=key;
                        } 
                        p=n-1;
                        key=(*arr)[p];
                        while(p>0 && strcmp((*arr)[p-1].text, key.text) > 0 ){
                                (*arr)[p]=(*arr)[p-1];
                                p--;
                        }
                    break;
                default:
                    break;
                }
            break;
        default:
            break;
    }

    (*arr)[p]=key;
}


int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int getRandomLevel() {
    int level = getRandomNumber(1, 5);
    return level;
}

void getRandomMessage(char *message) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int length = getRandomNumber(1, 52);
    int i;
    for (i = 0; i < length; i++) {
        message[i] = letters[getRandomNumber(0, strlen(letters) - 1)];
    }
    message[i] = '\0';
}
void print_sort(){
    printf("\n1) Gnome\n");
    printf("2) Two pair\n");
    printf("3) qsort\n");
}
void print_h(){
    printf("\n1) id\n");
    printf("2) varn\n");
    printf("3) txt\n");

}
int main() {
        double time;
        clock_t start, fin;
    int km,size,ss=0,option,ilt;
                            int ap;

    LogEntry* logArray = (LogEntry*) malloc(sizeof(LogEntry));
    do{

        printf("%f\n",time);
        printf("0) Начать сортировать\n");
        printf("1) Стоп\n");
        printf("ENTER: ");
    scanf("%d",&ss);
    if (ss==0){

    printf("Введите количество массивов: ");
    scanf("%d",&km);
    printf("Введите количество cтруктур в массивах: ");
    scanf("%d",&size);


                print_sort();
                printf("Enter: ");
                scanf("%d",&option);
                printf("\n\n");


    logArray = realloc(logArray,(size)*sizeof(LogEntry));   
        if (logArray == NULL) {
        printf("Ошибка выделения памяти\n");

    }
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&ilt);
                        print_updown();
                        printf("Enter: ");

                        scanf("%d",&ap);
                        printf("\n\n");
                        

    for (int t=0;t<km;t++){
                    for (int i = 0; i < size; i++) {
        logArray[i].id = getRandomNumber(1, 100);
        logArray[i].level = getRandomLevel();
        getRandomMessage(logArray[i].text);
    }
    start=clock();
                switch (option){
                    case 1:
                        //gnome sort
                        
                        gnomeSort(&logArray,size,ilt,ap);
                        break;
                    case 2:
                        //pair sort

                        pairInsertionSort(&logArray,size,ilt,ap);
                        break;
                    case 3:
                        //qsort


                        switch (ap){
                            case 1:
                                //UP
                                switch (ilt){
                                    case 1:
                                        //id
                                        qsort(logArray,size,sizeof(LogEntry),comupid);
                                        break;
                                    case 2:
                                        //varn
                                        qsort(logArray,size,sizeof(LogEntry),comuplevel);
                                        break;
                                    case 3:
                                        //txt
                                        qsort(logArray,size,sizeof(LogEntry),comuptext);
                                            break;
                            default:
                                break;
                        }
                                break;
                            case 2:
                                //DOWN
                                switch (ilt){
                                    case 1:
                                        //id
                                        qsort(logArray,size,sizeof(LogEntry),comdownid);
                                        break;
                                    case 2:
                                        //varn
                                        qsort(logArray,size,sizeof(LogEntry),comdownlevel);
                                        break;
                                    case 3:
                                        //txt
                                        qsort(logArray,size,sizeof(LogEntry),comdowntext);
                                        break;
                                default:
                                break;
                        }
                        }

                        break;
                                                            
                    default:
                        break;
                    }
                


    }

    }
        fin=clock();
        time=(double)(fin-start);

    }while(ss==0);





    free(logArray);

    return 0;
}