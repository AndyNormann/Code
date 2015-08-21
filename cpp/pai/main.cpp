#include <iostream>
#include <fstream>
#include <sstream>

std::stringstream hello_world_c;

void insert_line(std::stringstream &output, std::string str, int indent)
{
    for (int i = 0; i < indent; ++i) {
        output << "\t";
    }
    output << str;
    output << "\n";
}

void add(std::string str, int indent){
    insert_line(hello_world_c, str, indent);
}

int main()
{
    std::ofstream output_file;
    output_file.open("output.c");

    add("#include <stdio.h>", 0);
    add("int main()", 0);
    add("{", 0);
    add("printf(\"skjera\");", 1);
    add("return 0;", 1);
    add("}", 0);
    
    output_file << hello_world_c.str();

    output_file.close();

    system("gcc -o runnable output.c");
    system("./runnable");

    return 0;
}
