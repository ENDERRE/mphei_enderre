#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    int S[] = { 2,2,2,7,7,7,8,8,8 };
    int k = sizeof(S) / sizeof(int);

    for (int i = 0; i < k; i++) {
        for (int i = 0; i < k; i++) { printf("%d ", S[i]); }
        printf("\n");
        if (S[i] % 2 != 0) {
            int r = S[i];

            for (int f=i; f > 0; f--) {

                S[f] = S[f - 1];
            }
            S[0] = r;
        }
    }
    for (int i=0;i<k;i++){ printf("%d ", S[i]); }
}