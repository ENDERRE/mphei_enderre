#include <stdio.h>

int main() {
	double x = 2.00001;
	long double y = 3.00000000000001;
	printf("%g %lf", x, y);
}