#include <iostream>
#include <string>
#include <vector>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
};

std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k)
{
    size_t largest_index = 0;
    int largest_size = 0;

    for(size_t i = 0; i < strarr.size()-k; i++){
        int sum = 0;
        for (size_t j = 0; j < k; j++) {
            sum += strarr[i+j].length();
        }
        if (sum > largest_size) {
            largest_size = sum;
        }
    }

    std::string retval;
    for (size_t i = largest_index; i < largest_index+k; i++) {
        retval += strarr[i];
    }

    return retval;
}




int main()
{
    std::vector<std::string> vec {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};


    std::cout << LongestConsec::longestConsec(vec, 2) << "\n";
    return 0;
}
