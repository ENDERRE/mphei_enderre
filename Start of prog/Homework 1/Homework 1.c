#include <stdio.h>

int r(int x) {
    int k=0;

    while (x != 0) {
        k = k * 10 + x % 10;
        x /= 10;
    }

    return k;
}
int p(int x) {
    if (x % 10 == 0) {
        return x / 10;
    }
    return x;
}
int main() {
    int x,k;
    printf("Vedite chislo: ");
    scanf_s("%d", &x);
    k = r(x);
    while (p(x) != k) {
        printf("%d %d\n", p(x), k);
        x += k;
        k = r(x);
    }

    printf("%d", x);
}