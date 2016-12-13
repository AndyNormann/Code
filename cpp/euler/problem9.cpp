#include <iostream>
#include <math.h>

int main()
{
    double a, b, c;

    for (a = 1; a < 1000; ++a) {
        for (b = a+1; b < 1000; ++b) {
            c = sqrt((b*b)+(a*a));
            if (c <= b) {
                continue;
            }
            if (a+b+c == 1000) {
                std::printf("%.2f\n", a*b*c);
                return 0;
            }
        }
    }
    return 0;
}

