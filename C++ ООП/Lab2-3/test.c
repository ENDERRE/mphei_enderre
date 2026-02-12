#include <stdio.h>
#include <stdlib.h>

int main() {
    int var = 13;
    printf("Значение переменной var: %d\n", var);
    printf("Адрес переменной var: %p\n", &var);
    int *ptr = &var;
    printf("Значение указателя ptr: %p\n", ptr);
    printf("Значение, на которое ссылается указатель ptr: %d\n", *ptr);
    int **ptr_to_ptr = &ptr;
    printf("Значение указателя на указатель ptr_to_ptr: %p\n", ptr_to_ptr);


    int size = 5; 
    int *dynamic_array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dynamic_array[i] = i + 1; 
    }

    printf("\nДинамический массив:\n");
    

    for (int i = 0; i < size; i++) {
        printf("Значение dynamic_array[%d]: %d\n", i, dynamic_array[i]);
        printf("Адрес dynamic_array[%d]: %p\n", i, &dynamic_array[i]);
        
        int *array_ptr = &dynamic_array[i];
        printf("Значение указателя array_ptr: %p\n", array_ptr);
        printf("Значение, на которое ссылается array_ptr: %d\n", *array_ptr);
        
        int **array_ptr_to_ptr = &array_ptr;
        printf("Значение указателя на указатель array_ptr_to_ptr: %p\n", array_ptr_to_ptr);
        printf("\n");
    }

    free(dynamic_array);

    return 0;
}
