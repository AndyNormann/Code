#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ofstream output_file;
    output_file.open("output.c");
    std::stringstream hello_world_c;

    hello_world_c << "#include <stdio.h>\n\n";
    hello_world_c << "int main(int argc, char **argv){\n";
    hello_world_c << "    printf(\"hallaverden\\n\");\n";
    hello_world_c << "    return 0;\n";
    hello_world_c << "}\n";
    
    output_file << hello_world_c.str();

    output_file.close();

    system("gcc -o runnable output.c");
    system("./runnable");

    return 0;
}
