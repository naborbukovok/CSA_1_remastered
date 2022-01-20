#ifndef CSA_1_FUNCTIONAL_H
#define CSA_1_FUNCTIONAL_H

#include <stdio.h>
#include <stdlib.h>

struct functional {
    // Значения типизаций функциональных языков.
    enum type {
        STATIC, DYNAMIC
    };
    // Типизация.
    type t;
    // Поддержка ленивых вычислений.
    bool isLazy;
};

// Ввод параметров из файла.
void In(functional &f, FILE *in);

// Случайный ввод параметров.
void InRandom(functional &f);

// Вывод параметров в файл.
void Out(functional &f, FILE *out);

#endif //CSA_1_FUNCTIONAL_H
