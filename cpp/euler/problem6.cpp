#include <iostream>
#include <cmath>

int main()
{
    int sum_of_squares = 0, square_of_sum = 0;

    for (int i = 1; i < 101; ++i) {
        sum_of_squares += pow(i, 2);
        square_of_sum += i;
    }

    square_of_sum = pow(square_of_sum, 2);

    std::printf("%d\n", square_of_sum-sum_of_squares);
    return 0;
}

