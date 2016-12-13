#include <iostream>

#define MAX 4000000

int main()
{
    int p1, p2;
    p1 = 0;
    p2 = 1;
    int cur;

    int sum = 0;

    for(cur = p1+p2; cur<MAX; cur = p1+p2){
        if (cur %2 == 0) {
            sum += cur;
        }
        p1 = p2;
        p2 = cur;
    }

    std::printf("%d\n", sum);


    return 0;
}

