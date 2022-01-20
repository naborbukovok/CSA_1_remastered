#ifndef CSA_1_PROCEDURAL_H
#define CSA_1_PROCEDURAL_H

#include <stdio.h>
#include <stdlib.h>

struct procedural {
    // Наличие абстрактных типов данных.
    bool isAbstract;
};

// Ввод параметров из файла.
void In(procedural &p, FILE *in);

// Случайный ввод параметров.
void InRandom(procedural &p);

// Вывод параметров в файл.
void Out(procedural &p, FILE *out);

#endif //CSA_1_PROCEDURAL_H
