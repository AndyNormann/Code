#include <stdio.h>
#include <stdlib.h>

int* insWeave(int ins, int len, int *list);

int main(int argc, char *argv[])
{
    int N = 100;
    int *halla = calloc(N, sizeof(int));
    int i;
    int *ballasnu;


    for (i = 0; i < N; i++) {
        halla[i] = i;
    }

    ballasnu = insWeave(11, N, halla);

    for (i = 0; i < N; i++) {
        printf("%d\n", ballasnu[i]);
    }

    return 0;
}


int* insWeave(int ins, int len, int *list)
{
    int *retVal = calloc(len, sizeof(int));

    int i;
    for (i = 0; i < len; i++) {
        retVal[i*2] = list[i];
    }

    for (i = 1; i < len*2; i += 2) {
        retVal[i] = ins;
    }

    return retVal;
}
