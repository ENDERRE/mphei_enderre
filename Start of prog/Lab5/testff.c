#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {debug, info, warn, error, fatal} LogLevel;

typedef struct {
    int id;
    LogLevel level;
    char text[100];
} LogEntry;

void inputLogArray(LogEntry* (*array), int *size) {
    printf("Enter the size of the log array: ");
    scanf("%d", &*size);
    *array = (LogEntry*) realloc((*array),(*size)*sizeof(LogEntry));
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

void outputLogArray(LogEntry* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("id: %d, level: %d, text: %s\n", array[i].id, array[i].level, array[i].text);
    }
}

void saveLogArrayToFile(LogEntry* array, int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    
    fwrite(array, sizeof(LogEntry), size, file);
    
    fclose(file);
}

void loadLogArrayFromFile(LogEntry* array, int size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }
    
    fread(array, sizeof(LogEntry), size, file);
    
    fclose(file);
}

int main() {
    int size;

    
    LogEntry* logArray = (LogEntry*) malloc(sizeof(LogEntry));
    
    printf("1. Input log array from keyboard\n");
    printf("2. Input log array from text file\n");
    printf("3. Input log array from binary file\n");
    int option;
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            inputLogArray(&logArray, &size);
            break;
        case 2:
            printf("Enter the name of the text file: ");
            char textFileName[100];
            scanf("%s", textFileName);
            loadLogArrayFromFile(logArray, size, textFileName);
            break;
        case 3:
            printf("Enter the name of the binary file: ");
            char binaryFileName[100];
            scanf("%s", binaryFileName);
            loadLogArrayFromFile(logArray, size, binaryFileName);
            break;
        default:
            printf("Invalid option.\n");
    }
    
    printf("1. Output log array to screen\n");
    printf("2. Output log array to text file\n");
    printf("3. Output log array to binary file\n");
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
        default:
            printf("Invalid option.\n");
    }
    
    free(logArray);
    
    return 0;
}