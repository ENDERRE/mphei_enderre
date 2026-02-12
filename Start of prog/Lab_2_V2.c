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
	} while (fabs(g)>E);
	return k;
}

int main() {
	setlocale(LC_ALL, "RU");

	long double x, k, E, y;

	printf("Введите число sinh: ");
	scanf("%Lf", &x);
	printf("Введите точность: ");
	scanf("%Lf", &E);


	k = sinhh(x, E);
	//y = sinh(x);
	printf("%.20Lf\n", k);
	//printf("sinh: %.20Lf", y);
	return 0;
}

