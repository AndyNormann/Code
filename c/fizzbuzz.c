#include <stdio.h>

/*
 * Print the values from 1 to 100, if a number is a multiple of 3, print fizz
 * instead.
 * If a number is a multiple of 5, print buzz instead. If a number is a multiple
 * of both
 * 3 and 5, print fizzbuzz.
*/

int main() {
    int i;
    for (i = 1; i < 101; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("fizzbuzz\n");
        } else if (i % 3 == 0) {
            printf("fizz\n");
        } else if (i % 5 == 0) {
            printf("buzz\n");
        } else {
            printf("%d\n", i);
        }
    }
    return 0;
}
