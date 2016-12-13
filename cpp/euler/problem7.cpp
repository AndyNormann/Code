#include <iostream>
#include <math.h>

bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

int main()
{
    int num_primes = 0;
    int num = 2;
    
    while(num_primes < 10001){
        if(isPrime(num)){
            num_primes++;
        }
        num++;
    }

    std::printf("num_primes: %d, num: %d\n", num_primes, num-1);

    return 0;
}

