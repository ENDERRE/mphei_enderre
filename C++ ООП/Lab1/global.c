#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "global.h"

#define _USE_MATH_DEFINES_

int reint(char in, char* ch){
    for (int i=0;i<strlen(ch);i++){
        if(in==ch[i]){
            return i;
        }
    }
    return -1;
}

void relog(char **to, int len){
    *to=realloc(*to,sizeof(char)*(len+1));
    for (int i=len;i>0;i--){
        (*to)[i]=(*to)[i-1];
    }
}
void convert(){
    char *number;
    int base_from, base_to;
    char *res;
    number = readline("Введите число:");
    printf("Введите базы (откуда и куда): ");
    scanf("%d %d",&base_from, &base_to);

    convert_base(number, base_from, base_to, &res);
    printf("\nРезультат вычислений: %s\n",res);
}

// Функции для арифметических операций
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b != 0) return a / b;
    else {
        printf("Ошибка: деление на ноль.\n");
        return 0;
    }
}

// Функции для побитовых операций
int bitwise_and(int a, int b) { return a & b; }
int bitwise_or(int a, int b) { return a | b; }
int bitwise_xor(int a, int b) { return a ^ b; }
int left_shift(int a, int n) { return a << n; }
int right_shift(int a, int n) { return a >> n; }

// Функция для вычисления степени
double power(double base, int exp) {
    return pow(base, exp);
}

// Функция для вычисления факториала
unsigned factorial(int n) {
    if (n < 0) return 0; // Факториал не определен для отрицательных чисел
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}



// Логарифмы
double natural_log(double x) {
    if (x > 0) {
        printf("%.2f\n",log(x));
    }else {
        printf("Ошибка: логарифм не определен для не положительных чисел.\n");
        
    }
    return 0;

}

double log_base(double x, double base) {
    if (x > 0 && base > 1) {
        printf("%.2f\n",log(x) / log(base));
    }else {
        printf("Ошибка: логарифм не определен.\n");
        
    }
    return 0;
}

// НОД и НОК
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Конвертация систем счисления
void convert_base(char* number, int base_from, int base_to, char **res) {
    char *ss="0123456789abcdefghijklmnopqrstuvwxyz";

    int num_10=0, ff=0, temp;
    
    int len = strlen(number);

    for (int i=len; i--; i>0){
        temp=reint(number[i],ss);
        num_10+=temp*pow(base_from,ff);
        ff+=1;
    }
    *res=malloc(sizeof(char));
    len=0;
    while(num_10>0){
        len++;
        relog(res,len);
        (*res)[0]=ss[num_10%base_to];
        num_10/=base_to;
    }
    (*res)[len]='\0';
    free(number);

}
// Площадь правильного n-угольника
double area_polygon(int n, double side_length) {
    if(n<3 || side_length==0) return 0;
    double R=side_length/(2*sin(M_PI/n));
    double S=(n*R*R)/(2)*sin(2*M_PI/n);
    return S;
}
void poli_math(){
    int n;
    double side_length;
    printf("Введите количество сторон и длину стороны: ");
    scanf("%d %lf", &n, &side_length);
    double area = area_polygon(n, side_length);
    if (area > 0  )
        printf("Площадь правильного %d-угольника: %.5f\n", n, area);
    else
        printf("Ошибка при вычислении площади.\n");        
}

// Корни квадратного уравнения
void quadratic_roots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        printf("Нет действительных корней.\n");
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Корень: %.2f\n", root);
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Корни: %.2f и %.2f\n", root1, root2);
    }
}

void matem(){
    double a, b;
    char op;
    printf("Вместо \"op\" введите одну из операций \"+-*/\" \n");
    printf("Введите выражение (a op b): ");
    scanf("%lf %c %lf", &a, &op, &b);
    switch(op) {
        case '+': printf("Результат: %.2f\n", add(a, b)); break;
        case '-': printf("Результат: %.2f\n", subtract(a, b)); break;
        case '*': printf("Результат: %.2f\n", multiply(a, b)); break;
        case '/': printf("Результат: %.2f\n", divide(a, b)); break;
        default: printf("Неизвестная операция.\n");
    }
}
void bit_oper(){
    int a, b;
    printf("Введите два числа для побитовых операций: ");
    scanf("%d %d", &a, &b);
    printf("AND: %d\n", bitwise_and(a, b));
    printf("OR: %d\n", bitwise_or(a, b));
    printf("XOR: %d\n", bitwise_xor(a, b));
}
void step(){
    double base;
    int exp;
    printf("Введите основание и степень: ");
    scanf("%lf %d", &base, &exp);
    printf("Результат: %.0f\n", power(base, exp));
}
void fact(){
    int n;
    printf("Введите число для вычисления факториала: ");
    scanf("%d", &n);
    printf("Факториал: %u\n", factorial(n));
}
void trig(){
    double angle;
    printf("Введите угол в радианах для синуса и косинуса: ");
    scanf("%lf", &angle);

    printf("Синус: %.2f\n", sin(angle));
    printf("Косинус: %.2f\n", cos(angle));
}
void logarif(){
    double x, base;
    printf("Введите число для натурального логарифма: ");
    scanf("%lf", &x);
    natural_log(x);
    
    printf("Введите число и основание для логарифма по основанию: ");
    scanf("%lf %lf", &x, &base);
    log_base(x, base);
}
void delit(){
    int a, b;
    printf("Введите два числа для НОД и НОК: ");
    scanf("%d %d", &a, &b);
    printf("НОД: %d\n", gcd(a, b));
    printf("НОК: %d\n", lcm(a, b));
}
void quatro(){
    double a, b, c;
    printf("Введите коэффициенты a, b и c квадратного уравнения ax^2 + bx + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    quadratic_roots(a, b, c);
}
void print_menu(){
    printf(" ____________________________________________ \n");
    printf("| Выберите действие                          |\n");
    printf("| (a) Арифметические операции                |\n");
    printf("| (b) Побитовые операции                     |\n");
    printf("| (c) Степень числа                          |\n");
    printf("| (d) Факториал                              |\n");
    printf("| (e) Тригонометрические функции             |\n");
    printf("| (f) Логарифмы                              |\n");
    printf("| (g) НОД и НОК                              |\n");
    printf("| (h) Конвертация систем счисления           |\n");
    printf("| (q) Площадь правильного n-угольника        |\n");
    printf("| (j) Корни квадратного уравнения            |\n");
    printf("| Выход из программы Ctrl + D                |\n");
    printf("|____________________________________________|\n");
}
