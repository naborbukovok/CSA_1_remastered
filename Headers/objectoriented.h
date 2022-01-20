#ifndef CSA_1_OBJECTORIENTED_H
#define CSA_1_OBJECTORIENTED_H

#include <stdio.h>
#include <stdlib.h>

struct objectoriented {
    // Значения наследования объектно-ориентированных языков.
    enum inheritance {
        SINGLE, MULTIPLE, INTERFACE
    };
    // Наследование.
    inheritance inh;
};

// Ввод параметров из файла.
void In(objectoriented &o, FILE *in);

// Случайный ввод параметров.
void InRandom(objectoriented &o);

// Вывод параметров в файл.
void Out(objectoriented &o, FILE *out);

#endif //CSA_1_OBJECTORIENTED_H
