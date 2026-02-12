#include <stdio.h>
#include <math.h>
#include <locale.h>

void start_menu(){
    printf("(a) Инациализация массива\n (b) Вставка нового Элемента\n (c) Удаление элемента \n (d) Индивидуальное задание \n (e) Вывод содержимого массива\n");
    
}

int main() {
    int size = 0;
    char variant, check;
    float element;
    int individual_answer;
    int input_error = 1, mem_error=0, position, error = 0, flag = 1, len = 0;
    int *a = (int *) malloc(0);
    

}