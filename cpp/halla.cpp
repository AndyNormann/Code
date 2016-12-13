#include <iostream>

int main(int argc, const char *argv[])
{
    int *arrays[10];

    int yo[5];

    for (int i = 0; i < 5; ++i) {
        yo[0] = i;
    }

    arrays[0] = yo;

    for (int i = 0; i < 5; ++i) {
        std::cout << arrays[0][i] << std::endl;
    }

    return 0;
}

