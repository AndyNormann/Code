#include <iostream>

int main()
{
    int n, s, p, q;

    std::cin >> n >> s >> p >> q;
    
    int a[n];

    int mod = 2^31;

    a[0] = s % mod;

    for (int i = 0; i < n; ++i) {
        a[i] = a[i-1]*p+q % (mod);
    }

    int un = 0;

    for (int i = 0; i < n; ++i) {
        int freq = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i] == a[j]) {
                freq++;
            }
        }
        if (freq == 1) {
            un++;
        }
    }

    std::cout << un << std::endl;

    return 0;
}

