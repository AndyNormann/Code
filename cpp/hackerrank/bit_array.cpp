#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>
using namespace std;

int main()
{
    int n, s, p, q;

    std::cin >> n >> s >> p >> q;
    
    auto a = make_unique<int[]>(n);

    int mod = q % (2^31);

    a[0] = s % (2^31);

    for (int i = 1; i < n; ++i) {
        a[i] = a[i-1] * p + mod;
    }

    //std::cout << nums.size() << std::endl;
    

    //int un = 0;
    //for (int i = 0; i < n; ++i) {
        //int freq = 0;
        //for (int j = 0; j < n; ++j) {
            //if (a[i] == a[j]) {
                //freq++;
            //}
        //}
        //if (freq == 1) {
            //un++;
        //}
    //}

    //std::cout << un << std::endl;

    return 0;
}
