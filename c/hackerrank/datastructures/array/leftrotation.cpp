#include <stdio.h>

int main()
{
    int N, d, N_minus_one = 0;
    scanf("%d %d", &N, &d);

    N_minus_one = N-1;

    int *old_array = new int[N];
    int *new_array = new int[N];


    for (int i = 0; i < N; i++) {
	scanf("%d", &old_array[i]);
    }

    for (int i = d; i < N; i++) {
	new_array[i-d] = old_array[i];
    }
    for (int i = N-d, j = 0; i < N; i++, j++) {
	new_array[i] = old_array[j];
    }

    for (int i = 0; i < N; i++) {
	printf("%d ", new_array[i]);
    }

    delete[] old_array;
    delete[] new_array;

    return 0;
}

