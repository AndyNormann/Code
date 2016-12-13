#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void insert_line(std::string str, int indent = 0);
void insert_include(std::string inc);
void insert_function(std::string name, std::string return_type, std::vector<std::string> args, std::string body);

std::stringstream hello_world_c;

void insert_line(std::string str, int indent)
{
    for (int i = 0; i < indent; ++i) {
        hello_world_c << "\t";
    }
    hello_world_c << str;
    hello_world_c << "\n";
}

void insert_include(std::string inc)
{
    insert_line("#include <" + inc + ">");
}

void insert_function(std::string name, std::string return_type, std::vector<std::string> args, std::string body)
{
    std::stringstream arguments;

    arguments << args[0];
    for (size_t i = 1; i < args.size(); ++i) {
        arguments << ", " << args[i];
    }
    
    insert_line(return_type + " " + name + "(" + arguments.str() + ")");
    insert_line("{", 0);
    insert_line(body, 1);
    insert_line("}", 0);
}

int main()
{
    std::ofstream output_file;

    output_file.open("output.c");

    insert_include("stdio.h");

    std::vector<std::string> args;
    args.push_back("int argc");
    args.push_back("char **argv");

    std::stringstream body;
    body << "printf(\"skjera\\n\");\n" << "\treturn 0;\n";
    insert_function("main", "int", args, body.str());

    output_file << hello_world_c.str();

    output_file.close();

    system("gcc -o runnable output.c");
    system("./runnable");
    system("rm runnable output.c");

    return 0;
}
