#include <stdio.h>
#include <math.h>
#include <locale.h>
long double sinhh(long double x, int i) {
	long double k = x, g = x;
	int r = 2, l = 1;
	while (l < i) {
		g = (g * x * x) / (r * (r + 1));
		k += g;
		r += 2;
		l++;
	}
	return k;
}

int main() {
	setlocale(LC_ALL, "RU");

	long double x, k, y;
	int i;

	printf("Введите число sinh: ");
	scanf("%Lf", &x);
	printf("Кол_во циклов: ");
	scanf("%d", &i);

	k = sinhh(x, i);
	y = sinh(x);
	printf("%.20Lf\n", k);
	printf("sinh: %.20Lf", y);
	return 0;
}