#include <stdio.h>

int p(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
int f(int x) {
	int u = 1;

	for (int i = 1; i <= x / 2; i++) {
		if (x % i == 0) {
			if (p(i) == 1) {
				printf("M%d: %d\n", u, i);
				u++;
			}
		}
	}
	if (p(x) == 1) {
		printf("M%d: %d\n", u, x);
	}
	return 0;
}
int main() {
	int x;
	printf("Vvedite chislo: ");
	scanf_s("%d", &x);
	return f(x);
}