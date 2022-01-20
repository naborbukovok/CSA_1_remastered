#include <string.h>
#include <time.h>
#include "../Headers/container.h"

void errMessage1() {
    printf("Incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile_1 outfile_2\n"
           "  Or:\n"
           "     command -n number outfile_1 outfile_2\n");
}

void errMessage2() {
    printf("Incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile_1 outfile_2\n"
           "  Or:\n"
           "     command -n number outfile_1 outfile_2\n");
}

int main(int argc, char *argv[]) {
    clock_t start = clock();

    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    Init(c);

    srand(static_cast<unsigned int>(time(nullptr)));

    if (!strcmp(argv[1], "-f")) {
        FILE *in = fopen(argv[2], "r");
        if (in == nullptr) {
            printf("No such file: %s\n", argv[2]);
            return 3;
        }
        In(c, in);
        fclose(in);
        if (c.len < 1 || c.len > container::max_len) {
            printf("Incorrect languages number.\n");
            return 3;
        }
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > container::max_len)) {
            printf("Incorrect languages number.\n");
            return 3;
        }
        InRandom(c, size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод необработанного контейнера.
    FILE *out1 = fopen(argv[3], "w");
    fprintf(out1,
            "Container:\n");
    Out(c, out1);
    fclose(out1);

    // Вывод контейнера с переставленными языками.
    FILE *out2 = fopen(argv[4], "w");
    SwapElements(c);
    fprintf(out2,
            "Container with swapped elements:\n");
    Out(c, out2);
    fclose(out2);

    Clear(c);

    printf("Stop\n");

    printf("%.2f ms\n", (double) (clock() - start) / CLOCKS_PER_SEC * 1000);
    return 0;
}