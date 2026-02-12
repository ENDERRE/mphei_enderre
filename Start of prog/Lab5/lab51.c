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
void pairInsertionSort(int *arr, int n) {
    int key;
    int keym;
    int p;
    for (int i = 1; i < n; i += 2) {
        if(arr[i]>arr[i-1]){
            keym=arr[i];
            key=arr[i-1];

        }else{
            key=arr[i];
            keym=arr[i-1];
        }
    p=i;
    while(p-2>=0 && arr[p-2]>keym){
            arr[p]=arr[p-2];
            p--;

        
    }


    arr[p]=keym;
    
    while(p-1>0 && arr[p-1]>key){
            arr[p-1]=arr[p-2];
            p--;
    }
    arr[p-1]=key;
    } 
    p=n-1;
    key=arr[p];
    while(p>0 && arr[p-1]>key){
            arr[p]=arr[p-1];
            p--;
    }
    arr[p]=key;
}
void gnomeSort(int *arr, int n) {
    int index = 0;
    while (index < n) {
        if (index == 0 || arr[index] <= arr[index - 1]) {
            index++;
        } else {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    int *arr = malloc(size * sizeof(int));
    
    readArrayStdin(arr, size);
    pairInsertionSort(arr,size);
    writeArrayStdout(arr,size);
    
    readArrayStdin(arr, size);
    gnomeSort(arr,size);
    writeArrayStdout(arr,size);
    free(arr);
    
    return 0;
}