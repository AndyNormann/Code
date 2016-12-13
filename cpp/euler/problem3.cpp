#include <iostream>

#define NUM 600851475143

int main()
{
    long res;
    long d = 2;
    long n = NUM;

    while(n > 1){
        while(n % d == 0){
            res = d;
            n /= d;
        }
        d = d+1;
        if (d*d > n) {
            if (n > 1) 
                res = n;
            break;
        }
    }
    std::printf("%ld\n", res);

    return 0;
}

