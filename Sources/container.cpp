#include "../Headers/container.h"

// Инициализация.
void Init(container &c) {
    c.len = 0;
}

// Очистка от элементов (освобождение памяти).
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

// Ввод содержимого контейнера из файла.
void In(container &c, FILE *in) {
    int key = -1;
    while (fscanf(in, "%d", &key) != EOF) {
        if (c.len >= c.max_len) {
            In(in, key);
            c.len++;
        } else if ((c.cont[c.len] = In(in, key)) != nullptr) {
            c.len++;
        }
    }
}

// Случайный ввод содержимого контейнера.
void InRandom(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRandom()) != nullptr) {
            c.len++;
        }
    }
}

// Вывод содержимого контейнера в файл.
void Out(container &c, FILE *out) {
    fprintf(out,
            "There are %d elements in container:\n",
            c.len);
    for (int i = 0; i < c.len; i++) {
        fprintf(out, "%d: ", i);
        Out(*(c.cont[i]), out);
    }
}

// Функция для перемещения в конец элементов, больших чем среднее значение функции
// GetParameter (по условию, порядок сохраняется прежний).
void SwapElements(container &c) {
    double averageParameter = 0;
    int countOfBigger = 0;
    container newc;
    Init(newc);
    for(int i = 0; i < c.len; i++) {
        averageParameter += GetParameter(*c.cont[i]);
    }
    averageParameter /= c.len;
    for(int j = 0; j < c.len; j++) {
        if (GetParameter(*c.cont[j]) > averageParameter) {
            countOfBigger++;
        }
    }
    int countOfOthers = 0;
    for(int k = 0; k < c.len; k++) {
        if (GetParameter(*c.cont[k]) > averageParameter) {
            newc.cont[c.len - countOfBigger] = c.cont[k];
            countOfBigger--;
        }
        else {
            newc.cont[countOfOthers] = c.cont[k];
            countOfOthers++;
        }
    }
    for(int q = 0; q < c.len; q++) {
        c.cont[q] = newc.cont[q];
    }
}
