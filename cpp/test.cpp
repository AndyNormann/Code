#include <iostream>

class Balle
{
public:
    Balle (){
        x = 1;
        y = 1;
        z = 1;
    }

private:
    int x, y, z;
};

int main()
{
    Balle *b = new Balle();

    if(b){
        std::cout << "Initialized right" << std::endl;
    }

    std::memset(b, 0, sizeof(Balle));

    if(b == NULL){
        std::cout << "Yo" << std::endl;
    }



    return 0;
}

