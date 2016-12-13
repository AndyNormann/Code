#include <iostream>

bool even(int num)
{
    for (int i = 1; i < 21; ++i) 
        if (num%i != 0) 
            return false;
    return true;
}

int main()
{
    int cur = 20;
    while(!even(cur))
        cur += 20;
    std::printf("%d\n", cur);
    return 0;
}

