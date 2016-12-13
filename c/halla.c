#include <stdio.h>
int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
        for(int arr_j = 0; arr_j < 6; arr_j++){

            scanf("%d",&arr[arr_i][arr_j]);
        }
    }


    int i, j;
    int sum = 0;
    int largestSum = 0;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            //if (arr[i][j] == 0) continue;

            sum += arr[i][j];
            sum += arr[i][j+1];
            sum += arr[i][j+2];
            sum += arr[i+1][j+1];
            sum += arr[i+2][j+0];
            sum += arr[i+2][j+1];
            sum += arr[i+2][j+2];

            if (sum > largestSum) largestSum = sum;
            sum = 0;
        }
    }

    for(i = 4; i > 0; --i){
        for (j = 4; j > 0; --j) {
            //if (arr[i][j] == 0) continue;

            sum += arr[i][j];
            sum += arr[i][j-1];
            sum += arr[i][j-2];
            sum += arr[i-1][j-1];
            sum += arr[i-2][j-0];
            sum += arr[i-2][j-1];
            sum += arr[i-2][j-2];

            if (sum > largestSum) largestSum = sum;
            sum = 0;
        }
    }

    printf("%d\n", largestSum);

    return 0;
}
