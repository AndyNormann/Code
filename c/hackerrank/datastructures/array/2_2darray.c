#include <stdio.h>

int main()
{
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }

    int i = 0, j = 0;
    int sum = 0;
    sum += arr[i][j];
    sum += arr[i][j+1];
    sum += arr[i][j+2];
    sum += arr[i+1][j+1];
    sum += arr[i+2][j];
    sum += arr[i+2][j+1];
    sum += arr[i+2][j+2];

    int largestSum = sum;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            sum += arr[i][j];
            sum += arr[i][j+1];
            sum += arr[i][j+2];
            sum += arr[i+1][j+1];
            sum += arr[i+2][j];
            sum += arr[i+2][j+1];
            sum += arr[i+2][j+2];

            if (sum > largestSum) largestSum = sum;
            sum = 0;
        }
    }
    printf("%d\n", largestSum);

    return 0;
}

