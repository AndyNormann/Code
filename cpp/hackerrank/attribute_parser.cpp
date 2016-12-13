#include <cstdio>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> u;


    FILE* input = fopen("attribute_parser.dat", "rw");

    int number_of_lines;
    int number_of_queries;

    fscanf(input, "%d %d", &number_of_lines, &number_of_queries);

    printf("%d %d\n", number_of_lines, number_of_queries);

    for (int i = 0; i < number_of_lines; ++i) {
        std::string tag_start;
        while(fgets(input, ))
        
        
    }


    fclose(input);
    return 0;
}

