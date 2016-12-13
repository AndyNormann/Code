#include <stdio.h>

int main(int argc, const char *argv[])
{
    int N;

    scanf("%d", &N);

    int nums[N];

    int i;
    for (i = 0; i < N; ++i) {
        scanf("%d", nums[i]);
    }

    for(i = N-1; i--; ){
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

