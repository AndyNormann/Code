#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person
{
protected:
    string name;
    int age;
    static int count;
public:
    Person() {
        count = 1;
    }
    virtual void getdata() 
    {
        std::cin >> name;
        std::cin >> age;
    }
    virtual void putdata() 
    {
        std::cout << name << " " << age << " " << count << std::endl;
    }
 
};


class Student: public Person
{
private:
    int marks[6];
    int cur_id;
public:
    Student (){
        cur_id = count++;
    }
    void getdata(){
        std::cin >> name >> age;
        for (int i = 0; i < 6; ++i) {
            cin >> marks[i];
        }
    }
    void putdata(){
        std::cout << name << " " << age << " ";
        int sum = 0;
        for (int i = 0; i < 6; ++i) {
            sum += marks[i];
        }
        std::cout << sum << " " << count << std::endl;
    }

};

class Professor : public Person
{
private:
    int publications;
    int cur_id;
public:
    Professor (){
        cur_id = count++;
    }
    void getdata(){
        std::cin >> name >> age >> publications;
    }

    void putdata(){
        std::printf("%s %d %d %d\n", name.c_str(), age, publications, cur_id);
    }

};


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
