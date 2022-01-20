#ifndef CSA_1_CONTAINER_H
#define CSA_1_CONTAINER_H

#include "language.h"

// Простейший контейнер на основе одномерного массива.
struct container {
    enum {
        // Максимальная длина.
        max_len = 10000
    };
    // Текущая длина.
    int len;
    language *cont[max_len];
};

// Инициализация.
void Init(container &c);

// Очистка от элементов (освобождение памяти).
void Clear(container &c);

// Ввод содержимого контейнера из файла.
void In(container &c, FILE *in);

void InRandom(container &c, int size);

// Вывод содержимого контейнера в файл.
void Out(container &c, FILE *out);

// Функция для перемещения в конец элементов, больших чем среднее значение функции
// GetParameter (по условию, порядок сохраняется прежний).
void SwapElements(container &c);

#endif //CSA_1_CONTAINER_H
