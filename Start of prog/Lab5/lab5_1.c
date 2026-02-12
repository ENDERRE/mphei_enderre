#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void gnomeSort(LogEntry* *array, int size,int op) {
    int index = 0;
    LogEntry temp;
        int ap;
    print_updown();
    printf("Enter: ");
    scanf("%d",&ap);

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




void pairInsertionSort(LogEntry* *arr, int n,int op) {
    LogEntry key;
    LogEntry keym;
    int p;
    int ap;
    print_updown();
    printf("Enter: ");
    scanf("%d",&ap);

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


void inputLogArray(LogEntry* *array, int *size) {
    printf("Enter the size of the log array: ");
    scanf("%d", &(*size));

    *array = realloc(*array,(*size)*sizeof(LogEntry));   


    for (int i = 0; i < *size; i++) {
        printf("Enter id: ");
        scanf("%d", &(*array)[i].id);
        
        printf("Enter level (0-debug, 1-info, 2-warn, 3-error, 4-fatal): ");
        int level;
        scanf("%d", &level);
        (*array)[i].level = (LogLevel) level;
        
        printf("Enter text: ");
        scanf("%s", (*array)[i].text);
    }
}


void saveLogArrayToFile(LogEntry* array, int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    for (int i=0;i<size;i++){
    fprintf(file, "%d\n", array[i].id);
    fprintf(file, "%d\n", array[i].level);
    fprintf(file, "%s\n", array[i].text);
    }
    fclose(file);
}

void loadLogArrayFromFile(LogEntry* *array, int *size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }
    int count=0;
    char line[256];
    int linelen;
    *size=0;

    while (fgets(line, sizeof(line), file)) {
        if (count%3==0){
            *size+=1;
            count=0;
            *array = realloc(*array,(*size)*sizeof(LogEntry));
  
        }
        switch (count) {
            case 0:
                (*array)[*size-1].id = atoi(line);
                break;
            case 1:
                (*array)[*size-1].level = atoi(line);
                break;
            case 2:
                linelen=strcspn(line,"\n");

                strncpy((*array)[*size-1].text, line, linelen);
                (*array)[*size-1].text[linelen]='\0';
                break;
        }

        count++;
    }
    
    
    fclose(file);
}
void readEventFromFile(LogEntry* *array,int *size, char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }
    *size=0;
    LogEntry event;
    while (fread(&event, sizeof(LogEntry), 1, file) == 1) {
        *size+=1;
        *array = realloc(*array,(*size)*sizeof(LogEntry));
        (*array)[*size-1]=event;
    }
    fclose(file);
}
void writeEventToFile(LogEntry* event,int size, const char* filename) {
    FILE* file = fopen(filename, "ab");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }
    for(int i=0 ;i<size;i++){
    fwrite(&event[i], sizeof(LogEntry), 1, file);
    fclose(file);
    }
}
void print_1(){
    printf("\n1) Input\n");
    printf("2) Output\n");
    printf("3) Sort\n");
    printf("4) Stop\n");

}
void print_in(){
    printf("\n1) From std key\n");
    printf("2) file\n");
    printf("3) bin file\n");

}
void print_out(){
    printf("\n1) From std key\n");
    printf("2) file\n");
    printf("3) bin file\n");

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
    char textFileName[100];
    int size;
    int option;
    int ss=0;
    LogEntry* logArray = (LogEntry*) malloc(sizeof(LogEntry));
    
    do{
        print_1();
        printf("Enter: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                //in
                print_in();
                printf("Enter: ");
                scanf("%d",&option);
                switch (option){
                    case 1:
                        //std in
                        inputLogArray(&logArray, &size);
                        break;
                    case 2:
                        //text in
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        loadLogArrayFromFile(&logArray, &size, textFileName);
                        break;
                    case 3:
                        //bin in
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        readEventFromFile(&logArray,&size,textFileName);
                    break;
                    default:
                        break;
                }
                break;
            case 2:
                //out
                print_out();
                printf("Enter: ");
                scanf("%d",&option);
                switch (option){
                    case 1:
                        //std out
                        outputLogArray(logArray, size);
                        break;
                    case 2:
                        //text save
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        saveLogArrayToFile(logArray, size, textFileName);
                        break;
                    case 3:
                        //bin save
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        writeEventToFile(logArray,size,textFileName);
                        break;
                    default:
                        break;
                    }

                break;
            case 3:
                //sort
                print_sort();
                printf("Enter: ");
                scanf("%d",&option);
                switch (option){
                    case 1:
                        //gnome sort
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&option);
                        gnomeSort(&logArray,size,option);
                        break;
                    case 2:
                        //pair sort
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&option);
                        pairInsertionSort(&logArray,size,option);
                        break;
                    case 3:
                        //qsort
                        int ap;
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&option);
                        print_updown();
                        printf("Enter: ");
                        scanf("%d",&ap);
                        switch (ap){
                            case 1:
                                //UP
                                switch (option){
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
                                switch (option){
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
                break;
            case 4:
                //stop
                ss=1;
                break;
            default:
                break;
        }
    }while(ss==0);

        free(logArray);









/*
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            inputLogArray(&logArray, &size);
            break;
        case 2:
            printf("Enter the name of the text file: ");
            char textFileName[100];
            scanf("%s", textFileName);
            loadLogArrayFromFile(&logArray, &size, textFileName);
            outputLogArray(logArray,size);
            break;
        case 3:
            printf("Enter the name of the binary file: ");
            char binaryFileName[100];
            scanf("%s", binaryFileName);
            loadLogArrayFromFile(&logArray, &size, binaryFileName);
            outputLogArray(logArray,size);
            break;
        default:
            printf("Invalid option.\n");
    }
    

    printf("4. Sort ID\n");
    printf("5. Sort varn\n");
    printf("6. Sort text\n");
    

    scanf("%d", &option);
    
    switch(option) {
        case 1:
            outputLogArray(logArray, size);
            break;
        case 2:
            printf("Enter the name of the text file: ");
            char textFileName[100];
            scanf("%s", textFileName);
            saveLogArrayToFile(logArray, size, textFileName);
            break;
        case 3:
            printf("Enter the name of the binary file: ");
            char binaryFileName[100];
            scanf("%s", binaryFileName);
            saveLogArrayToFile(logArray, size, binaryFileName);
            break;
        case 4:
            gnomeSort(&logArray,size,option);
            outputLogArray(logArray,size);

            break;
        case 5:
            gnomeSort(&logArray,size,option);
            outputLogArray(logArray,size);

            break;
        case 6:
            gnomeSort(&logArray,size,option);
            outputLogArray(logArray,size);

            break;
        default:
            printf("Invalid option.\n");
    }
    
    free(logArray);
    
    return 0;
    */
}