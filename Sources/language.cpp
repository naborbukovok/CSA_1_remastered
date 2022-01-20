#include <cstring>
#include "../Headers/language.h"

// Ввод параметров из файла.
language *In(FILE *in, int key) {
    language *l;
    l = new language;
    double popularity;
    int year;
    fscanf(in,
           "%s %lf %d",
           l->name, &popularity, &year);
    if (popularity < 0 || popularity > 100) {
        printf("Incorrect language popularity. Generating new one...\n");
        popularity = 100 * (double)rand() / RAND_MAX;
    }
    else if (year < 1945 || year > 2022) {
        printf("Incorrect language year. Generating new one...\n");
        year = 1945 + rand() % (2022 - 1945 + 1);
    }
    switch(key) {
        case 0:
            l->k = language::PROCEDURAL;
            l->popularity = popularity;
            l->year = year;
            In(l->p, in);
            return l;
        case 1:
            l->k = language::OBJECTORIENTED;
            l->popularity = popularity;
            l->year = year;
            In(l->o, in);
            return l;
        case 2:
            l->k = language::FUNCTIONAL;
            l->popularity = popularity;
            l->year = year;
            In(l->f, in);
            return l;
        default:
            return nullptr;
    }
}

// Случайный ввод параметров.
language *InRandom() {
    language *l;
    l = new language;
    // Генерируем длину названия.
    int name_len = 1 + rand() % 39;
    // Генерируем название.
    for (int i = 0; i < name_len; ++i) {
        l->name[i] = 'a' + rand() % 26;
    }
    l->name[name_len] = '\0';
    // Генерируем популярность.
    l->popularity = 100 * (double)rand() / RAND_MAX;
    // Генерируем год создания.
    l->year = 1945 + rand() % (2022 - 1945 + 1);
    // Генерируем ключ для альтернативы: 0, 1 или 2.
    int random_key = rand() % 3;
    switch (random_key) {
        case 0:
            l->k = language::PROCEDURAL;
            InRandom(l->p);
            return l;
        case 1:
            l->k = language::OBJECTORIENTED;
            InRandom(l->o);
            return l;
        case 2:
            l->k = language::FUNCTIONAL;
            InRandom(l->f);
            return l;
        default:
            return nullptr;
    }
}

// Вывод параметров в файл.
void Out(language &l, FILE *out) {
    switch (l.k) {
        case language::PROCEDURAL:
            Out(l.p, out);
            fprintf(out,
                    "Name: %s,\n"
                    "Popularity: %f,\n"
                    "Year: %d,\n"
                    "Special parameter (year / name length): %f.\n",
                    l.name, l.popularity, l.year, GetParameter(l));
            break;
        case language::OBJECTORIENTED:
            Out(l.o, out);
            fprintf(out,
                    "Name: %s,\n"
                    "Popularity: %f,\n"
                    "Year: %d,\n"
                    "Special parameter (year / name length): %f.\n",
                    l.name, l.popularity, l.year, GetParameter(l));
            break;
        case language::FUNCTIONAL:
            Out(l.f, out);
            fprintf(out,
                    "Name: %s,\n"
                    "Popularity: %f,\n"
                    "Year: %d,\n"
                    "Special parameter (year / name length): %f.\n",
                    l.name, l.popularity, l.year, GetParameter(l));
            break;
        default:
            printf("Incorrect.\n");
            return;
    }
}

// Общая для всех альтернатив функция - частное от года и длины названия.
double GetParameter(language &l) {
    return (double)(l.year) / strlen(l.name);
}
