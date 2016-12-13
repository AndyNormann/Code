#include <iostream>

int main(void)
{
    int sum = 0;
    int i;
    for (i = 0; i <= 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    std::printf("%d\n", sum);
    return 0;
}

