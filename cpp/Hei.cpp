#include <iostream>
using namespace std;

class Person
{
public:
    virtual void getdata();
    virtual void putdata();
    string name;
    int age;
    int cur_id;
    static int count;
};


class Student: public Person
{
private:
    int marks[6];

public:
    Student () : Person() {cur_id = count++;}

    void getdata(){
        std::cin >> name >> age;
        for (int i = 0; i < 6; ++i) {
            cin >> marks[i];
        }
    }
    void putdata(){
        std::cout << name << " " << age << std::endl;
        for (int i = 0; i < 6; ++i) {
            std::cout << marks[i] << " ";
        }
    }
};

class Professor : public Person
{
private:
    int publications;
public:
    Professor () : Person() {cur_id = count++;}

    void getdata(){
        std::cin >> name >> age >> publications;
    }

    void putdata(){
        std::printf("%s %d %d %d\n", name.c_str(), age, publications, cur_id);
    }
};

int main()
{
    Person *p[5];

    p[0] = new Professor();
    p[1] = new Student();
    return 0;
}
