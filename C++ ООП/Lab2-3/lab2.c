#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"


int main() {     
    char choice;
    srand(time(NULL));
    do {
        print_menu();
        printf("Ввод: ");
        if(scanf("%c", &choice)==EOF) {
            printf("Выход из программы\n"); 
            return 0; 
        }
        switch (choice) {
            case 'a': stat(); break;
            case 'b': non_stat(); break;
            default: printf("\n\nОшибка ввода, используйте только предложеные варианты\n"); break;
        }
        scanf("%*c");
    } while (1);
}


