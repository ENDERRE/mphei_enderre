#ifndef LIB_G
#define LIB_G
#include <stdio.h>
int reint(char in, char* ch);
void relog(char **to, int len);
void convert();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int bitwise_and(int a, int b);
int bitwise_or(int a, int b);
int bitwise_xor(int a, int b);
int left_shift(int a, int n);
int right_shift(int a, int n);
double power(double base, int exp);
unsigned factorial(int n);
double calculate_sin(double angle);
double calculate_cos(double angle);
double natural_log(double x);
double log_base(double x, double base);
int gcd(int a, int b);
int lcm(int a, int b);
void convert_base(char* number, int base_from, int base_to, char **res);
double area_polygon(int n, double side_length);
void poli_math();
void quadratic_roots(double a, double b, double c);
void matem();
void bit_oper();
void step();
void fact();
void trig();
void logarif();
void delit();
void quatro();
void print_menu();

#endif