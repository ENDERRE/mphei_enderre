#include <stdio.h>
#include <math.h>
#include <locale.h>
long double sinhh(long double x, long double E) {
	long double k = x, g = x;
	int r = 2;
	do {
		g = (g * x * x) / (r * (r + 1));
		k += g;
		r += 2;
	} while (g > E || g < -E);
	return k;
}

int main() {
	setlocale(LC_ALL, "RU");

	long double x, k, E;

	printf("Введите число sinh: ");
	scanf_s("%Lf", &x);
	printf("Введите точность: ");
	scanf_s("%Lf", &E);


	k = sinhh(x, E);
	printf("%.20Lf", k);
	return 0;
}
