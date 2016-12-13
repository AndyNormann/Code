#include <stdio.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

int main(int argc, const char *argv[]) {
    printf(KNRM "hei\n");
    printf(KRED "hei\n");
    printf(KGRN "hei\n");
    printf(KYEL "hei\n");
    printf(KBLU "hei\n");
    printf(KMAG "hei\n");
    printf(KCYN "hei\n");
    printf(KWHT "hei\n");

    return 0;
}
