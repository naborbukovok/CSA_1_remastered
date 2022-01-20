#include "../Headers/objectoriented.h"

// Ввод параметров из файла.
void In(objectoriented &o, FILE *in) {
    int key;
    fscanf(in,
           "%d",
           &key);
    /*
     * key должно быть = 0 (наследование - single),
     *             или = 1 (наследование - multiple),
     *             или = 2 (наследование - interface).
    */
    if ((key != 0 && key != 1 && key != 2)) {
        printf("Incorrect OBJECTORIENTED. Generating random OBJECTORIENTED...\n");
        InRandom(o);
    }
    else {
        o.inh = static_cast<objectoriented::inheritance>(key);
    }
}

// Случайный ввод параметров.
void InRandom(objectoriented &o) {
    // Генерируем ключ для наследования - 0, 1 или 2.
    int random_key = rand() % 3;
    o.inh = static_cast<objectoriented::inheritance>(random_key);
}

// Вывод параметров в файл.
void Out(objectoriented &o, FILE *out) {
    fprintf(out,
            "OBJECTORIENTED.\n");
    switch (o.inh) {
        case objectoriented::SINGLE:
            fprintf(out,
                    "Inheritance: single,\n");
            break;
        case objectoriented::MULTIPLE:
            fprintf(out,
                    "Inheritance: multiple,\n");
            break;
        case objectoriented::INTERFACE:
            fprintf(out,
                    "Inheritance: interface,\n");
            break;
    }
}