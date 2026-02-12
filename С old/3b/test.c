#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("test.bin", "rb"); // открыть бинарный файл для чтения

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numbers[100]; // массив для хранения чисел
    int count = 0; // индекс текущего числа

    while (fread(&numbers[count], sizeof(int), 1, file)) { // читать число из файла и сохранить его в массив
        count++;
    }

    fclose(file); // закрыть файл

    // вывести прочитанные числа
    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}