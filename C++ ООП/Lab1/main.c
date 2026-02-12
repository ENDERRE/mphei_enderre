#include <stdio.h>
#include <stdlib.h>
#include "global.h"
//gcc global.c global.h main.c -lm -o main -lreadline

int main() {     
    char choice;
    do {
        print_menu();
        printf("Ввод: ");
        if(scanf("%c", &choice)==EOF) {
            printf("Выход из программы\n"); 
            return 0; 
        }
        switch (choice) {
            case 'a': matem(); break;
            case 'b': bit_oper(); break;
            case 'c': step(); break;
            case 'd': fact(); break;
            case 'e': trig(); break;
            case 'f': logarif(); break;
            case 'g': delit(); break;
            case 'h': convert(); break;
            case 'q': poli_math(); break;
            case 'j': quatro(); break;
            default: printf("\n\nОшибка ввода, используйте только предложеные варианты\n"); break;
        }
        scanf("%*c");
    } while (1);
}


