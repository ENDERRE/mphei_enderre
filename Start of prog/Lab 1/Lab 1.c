#include <stdio.h>
int pr(int k, int x_fin, int x_fin_len) {
    int Est = 1;

    for (int i = 0; i < x_fin_len; i++) {
        if (x_fin % 10 == k) {
            Est = 0;
        }
        x_fin /= 10;
    }
    return Est;
}

int f(int x_fin_len) {
    int t = 1;
    for (int i = 0; i < x_fin_len; i++) {
        t *= 10;
    }
    return t;
}


int main() {
    int x, k = 0, x_fin = 0, x_fin_len = 0;
    printf("Vvedite tseloe thislo:");
    scanf_s("%d", &x);
    while (x != 0) {
        k = x % 10;
        x /= 10;

        if (pr(k, x_fin, x_fin_len) == 1) {
            if (k == 0) {
                x_fin *= 10;
                x_fin_len++;
            }
            else {
                x_fin += k * f(x_fin_len);
                x_fin_len++;
            }
        }
    }
    printf("%d", x_fin);

    return 0;
}
