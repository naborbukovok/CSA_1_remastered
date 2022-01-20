#include "../Headers/functional.h"

// Ввод параметров из файла.
void In(functional &f, FILE *in) {
    int key;
    int laziness;
    fscanf(in,
           "%d %d",
           &key, &laziness);
    // key должно быть = 0 (типизация - static) или = 1 (типизация - dynamic),
    // laziness должно быть = 0 (ленивые вычисления не поддерживаются) или = 1 (поддерживаются).
    if ((key != 0 && key != 1) || (laziness != 0 && laziness != 1)) {
        printf("Incorrect FUNCTIONAL. Generating random FUNCTIONAL...\n");
        InRandom(f);
    }
    else {
        f.t = static_cast<functional::type>(key);
        f.isLazy = (bool)laziness;
    }
}

// Случайный ввод параметров.
void InRandom(functional &f) {
    // Генерируем ключ для типизации - 0 или 1.
    int random_key = rand() % 2;
    f.t = static_cast<functional::type>(random_key);
    // Генерируем поддержку ленивых вычислений - 0 (false) или 1 (true).
    f.isLazy = rand() % 2;
}

// Вывод параметров в файл.
void Out(functional &f, FILE *out) {
    fprintf(out,
            "FUNCTIONAL.\n");
    switch (f.t) {
        case functional::STATIC:
            fprintf(out,
                    "Type: static,\n");
            break;
        case functional::DYNAMIC:
            fprintf(out,
                    "Type: dynamic,\n");
            break;
    }
    fprintf(out,
            "Supports lazy evaluation: %d,\n",
            f.isLazy);
}