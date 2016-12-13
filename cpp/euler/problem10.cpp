#include <iostream>
#include <cmath>

#define MAX 2000000

int main()
{
    bool marks[MAX];
    int upper_bound = sqrt(MAX);
    long sum = 0;

    for (int i = 2; i < MAX; ++i) {
        marks[i] = true;
    }

    for (int i = 2; i < upper_bound; ++i) {
       if (!marks[i]) continue; 

       for (int j = i*i; j < MAX; j += i) {
           marks[j] = false;
       }
    }

    for (int i = 0; i < MAX; ++i) {
        if (marks[i]) {
            sum += i;
        }
    }

    std::printf("%ld\n", sum);

    return 0;
}

