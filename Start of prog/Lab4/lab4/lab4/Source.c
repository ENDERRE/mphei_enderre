#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define a2 2

int main() {
    char buf[81] = { 0 };
    char* res = NULL;
    int len = 0;
    int n;
    do {
        n = scanf("%80[^\n]", buf);

        if (n < 0) {
            return NULL;
        }
        else if (n > 0) {
            int chunk_len = strln(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            mcp(res + len, buf, chunk_len);

            len = str_len;
        }
        else {
            fflush(stdin);
        }
    } while (n > 0);
    res[len] = '\0';

    printf("%s", res);
}