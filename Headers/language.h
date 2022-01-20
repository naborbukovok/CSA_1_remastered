#ifndef CSA_1_LANGUAGE_H
#define CSA_1_LANGUAGE_H

#include "procedural.h"
#include "objectoriented.h"
#include "functional.h"

struct language {
    // Название.
    char name[40];
    // Популярность.
    double popularity;
    // Год.
    int year;
    // Значения ключей для каждой альтернативы.
    enum key {
        PROCEDURAL, OBJECTORIENTED, FUNCTIONAL
    };
    // Ключ.
    key k;

    union {
        procedural p;
        objectoriented o;
        functional f;
    };
};

// Ввод параметров из файла.
language *In(FILE *in, int key);

// Случайный ввод параметров.
language *InRandom();

// Вывод параметров в файл.
void Out(language &l, FILE *out);

// Получение частного от деления года создания на количество символов в названии.
double GetParameter(language &l);

#endif //CSA_1_LANGUAGE_H
