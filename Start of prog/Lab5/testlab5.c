#include <stdio.h>
#include <stdlib.h>

void readArrayStdin(int *arr, int size) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    } 
}

void readArrayTextFile(int *arr, int size, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    printf("Чтение массива из файла...\n");
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d ", &arr[i]);
    }

    fclose(file);
}

void readArrayBinaryFile(int *arr, int size, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    printf("Чтение массива из бинарного файла...\n");
    fread(arr, sizeof(int), size, file);

    fclose(file);
}

void writeArrayStdout(int *arr, int size) {
    printf("Массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void writeArrayTextFile(int *arr, int size, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    printf("Запись массива в файл...\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void writeArrayBinaryFile(int *arr, int size, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    printf("Запись массива в бинарный файл...\n");
    fwrite(arr, sizeof(int), size, file);

    fclose(file);
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    int *arr = malloc(size * sizeof(int));
    
    readArrayStdin(arr, size);
    
    writeArrayStdout(arr, size);
    
    writeArrayTextFile(arr, size, "array.txt");
    
    writeArrayBinaryFile(arr, size, "array.bin");
    
    free(arr);
    
    return 0;
}