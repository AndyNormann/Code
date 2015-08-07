#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "fileread.h"

int main(int argc, const char *argv[])
{
    if(argc != 2){
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    }

    std::vector<tree_leaf> leafs;
    read_file(&leafs, argv[1]);

    std::sort(leafs.begin(), leafs.end(), leaf_sort);

    print_list(&leafs);

    return 0;
}
