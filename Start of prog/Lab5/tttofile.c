#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {debug, info, warn, error, fatal} LogLevel;

typedef struct {
    int id;
    LogLevel level;
    char text[100];
} LogEntry;




void outputLogArray(LogEntry* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("id: %d, level: %d, text: %s\n", array[i].id, array[i].level, array[i].text);
    }
    printf("\n");
}

void gnomeSort(LogEntry* *array, int size,int option) {
    int index = 0;
    LogEntry temp;
    switch(option){
        case 4:
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

    case 5:
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

    case 6:
        while (index < size) {
        if (index == 0 || strcmp((*array)[index].text, (*array)[index-1].text) > 0) {
            index++;
        } else {
            temp=(*array)[index];
            (*array)[index]=(*array)[index-1];
            (*array)[index-1]=temp;

            index--;
        }
    }
    }
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


void writeEventToFile(LogEntry* event,int size, const char* filename) {
    FILE* file = fopen(filename, "ab");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }

    fwrite(&event, sizeof(LogEntry), size, file);
    fclose(file);
}
void print_menu(){
    printf("input:");
    printf("1. log array from keyboard\n");
    printf("2. log array from text file\n");
    printf("3. log array from binary file\n");

    printf("output");
    printf("4. log array to screen\n");
    printf("5. log array to text file\n");
    printf("6. log array to binary file\n");
    
    printf("Sort:");
    printf("7. sort gnome");
    printf(" ");
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
                print_in();
                printf("Enter: ");
                scanf("%d",&option);
                switch (option){
                    case 1:
                        inputLogArray(&logArray, &size);
                        break;
                    case 2:
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        loadLogArrayFromFile(&logArray, &size, textFileName);
                        break;
                    case 3:
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);

                    //bin
                    break;
                    default:
                        break;
                }
                break;
            case 2:
                print_out();
                printf("Enter: ");
                scanf("%d",&option);
                switch (option){
                    case 1:
                        outputLogArray(logArray, size);
                        break;
                    case 2:
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        saveLogArrayToFile(logArray, size, textFileName);
                        break;
                    case 3:
                        printf("Enter the name of the text file: ");
                        scanf("%s", textFileName);
                        writeEventToFile(logArray,size,textFileName);
                        //bin save
                        break;
                    default:
                        break;
                    }

                break;
            case 3:
                print_sort();
                printf("Enter: ");
                scanf("%d",&option);
                switch (option){
                    case 1:
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&option);
                        gnomeSort(&logArray,size,option);
                        break;
                    case 2:
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&option);
                        //par
                        gnomeSort(&logArray,size,option);
                        break;
                    case 3:
                        print_h();
                        printf("Enter: ");
                        scanf("%d",&option);
                        //qsort
                        gnomeSort(&logArray,size,option);
                        break;
                                                            
                    default:
                        break;
                    }
                break;
            case 4:
                ss=1;
                break;
            default:
                break;
        }
    }while(ss==0);










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