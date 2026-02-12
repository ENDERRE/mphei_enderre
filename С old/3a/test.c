#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <readline/readline.h>

void readFromFile(char* filename) {
    FILE *file = stdin;
    stdin=fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char *c=NULL;
    //while(c!=)
    c=readline(NULL);
    //printf("%s\n",c);
    fclose(file);
}

int main() {
    char* filename = "test.txt";
    readFromFile(filename);

    return 0;
}