#include "../Headers/procedural.h"

// Ввод параметров из файла.
void In(procedural &p, FILE *in) {
    int abstractness;
    fscanf(in,
           "%d",
           &abstractness);
    // laziness должно быть = 0 (абстрактных типов данных нет) или = 1 (есть).
    if (abstractness != 0 && abstractness != 1) {
        printf("Incorrect PROCEDURAL. Generating random PROCEDURAL...\n");
        InRandom(p);
    }
    else {
        p.isAbstract = (bool)abstractness;
    }
}

// Случайный ввод параметров.
void InRandom(procedural &p) {
    // Генерируем наличие абстрактных типов данных - 0 (false) или 1 (true).
    p.isAbstract = rand() % 2;
}

// Вывод параметров в файл.
void Out(procedural &p, FILE *out) {
    fprintf(out,
            "PROCEDURAL.\n"
            "Has abstract data types: %d,\n",
            p.isAbstract);
}