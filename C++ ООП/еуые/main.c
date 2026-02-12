
#include <stdio.h>
#include <stdlib.h>
#include "h.h"
#include <string.h>
#include <readline/readline.h>
int main(int argc, char* argv[]) {
    Queue q;
    char* out_filename = NULL;
    int size, value, action;
    PRINT_DEBUG(Debug ON);
    // Обработка аргументов командной строки
    printf("\t\t===================\n");
    printf("\t\t|Work`s with queue|\n");
    printf("\t\t===================\n");
    printf("\n");
    printf("Enter the queue size: ");
    scanf("%d", &size);
    initQueue(&q, size);
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--out") == 0 && i + 1 < argc) {
            out_filename = argv[i + 1];
            i++;
        }
    }
    if (out_filename) {
        if (serializeQueue(&q, out_filename) == 0) {
            printf("Queue saved to %s\n", out_filename);
        }
        else {
            printf("Failed to save queue\n");
        }
    }
    do{
        printf("---------------------\n1. Add \n2. Extract \n3. Show \n4. Clearing the memory\n5. Binary input\n6. Binary output\n7. Exit\n---------------------\nSelect: ");
        scanf("%d", &action);
        char* file_name=NULL;

        switch (action) {
        case 1:
            printf("\n");
            printf("Write number: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            showQueue(&q);
            break;
        case 4:
            freeQueue(&q);
            break;
        case 5:
            printf("\nWrite file_name (x.bin): ");
            file_name = readline("");
            serializeQueue(&q, file_name);
            printf("===============\n");
            printf("Queue recorded!\n");
            printf("===============\n");
            break;
        case 6:
            printf("Write file_name (x.bin): ");
            file_name = readline("");
            deserializeQueue(&q, file_name);
            printf("===============\n");
            printf("Queue restored!\n");
            printf("===============\n");
            break;
        case 7:
            freeQueue(&q);
            PRINT_DEBUG(Debug OFF);
            return 0;
        default:
            printf("-----------------------\n");
            printf("Error-incorrert number!\n");
            printf("-----------------------\n");
        }
    } while (1);
    
    return 0;
}