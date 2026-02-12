#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "uthash.h"

typedef struct {
    unsigned long long key; // число
    UT_hash_handle hh;      // хэш-дескриптор
} num_entry;

int main() {
    unsigned long long N;
    printf("Введите N: ");
    scanf("%llu", &N);

    num_entry *numbers = NULL; // хэш-таблица для уникальных чисел

    unsigned long long max_k = (unsigned long long)sqrtl(N) + 1;

    for (unsigned long long k = 1; k <= max_k; ++k) {
        unsigned long long k_sq = k * k;

        // m=0
        if (k_sq <= N) {
            // добавляем число, если еще нет
            num_entry *s;
            HASH_FIND_ULONGLONG(numbers, &k_sq, s);
            if (s == NULL) {
                s = malloc(sizeof(num_entry));
                s->key = k_sq;
                HASH_ADD_ULONGLONG(numbers, key, s);
            }
        }

        for (unsigned long long m = 1; ; ++m) {
            unsigned long long m_sq = m * m;

            // x = k^2 - m^2
            if (k_sq >= m_sq) {
                unsigned long long x1 = k_sq - m_sq;
                if (x1 > N) break; // дальше не нужно
                // добавляем
                num_entry *s;
                HASH_FIND_ULONGLONG(numbers, &x1, s);
                if (s == NULL) {
                    s = malloc(sizeof(num_entry));
                    s->key = x1;
                    HASH_ADD_ULONGLONG(numbers, key, s);
                }
            } else {
                break; // так как m^2 уже больше k^2
            }

            // x = k^2 + m^2
            unsigned long long x2 = k_sq + m_sq;
            if (x2 > N) break;
            // добавляем
            num_entry *s;
            HASH_FIND_ULONGLONG(numbers, &x2, s);
            if (s == NULL) {
                s = malloc(sizeof(num_entry));
                s->key = x2;
                HASH_ADD_ULONGLONG(numbers, key, s);
            }
        }
    }

    // подсчет
    unsigned long long count = HASH_COUNT(numbers);
    printf("Количество квадратичных чисел до %llu: %llu\n", N, count);

    // освобождение памяти
    num_entry *current, *tmp;
    HASH_ITER(hh, numbers, current, tmp) {
        HASH_DEL(numbers, current);
        free(current);
    }

    return 0;
}