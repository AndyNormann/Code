#include <crow_all.h>
#include <iostream>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]() {
        return "Halla hva skjera boy";
    });


    return 0;
}
