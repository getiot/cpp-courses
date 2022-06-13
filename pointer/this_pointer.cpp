#include <iostream>
using namespace std;

class Human
{
public:
    string name;
    string gender;

    Human(string name, int gender)
    {
        this->name = name;
        this->gender = gender == 0 ? "female" : "male";
    }
};

class Employee: public Human
{
public:
    int id;      // data member (also instance variable)
    float salary;
    Employee(int id, string name, float salary): Human(name, 0)
    {
        this->id = id;
        this->salary = salary;
    }
    void display()
    {
        cout << id << "  " << name << "  " << gender << "  " << salary << endl;
    }
};

int main(void)
{
    Employee e1 = Employee(101, "Olalla", 89000);  // creating an object of Employee
    Employee e2 = Employee(102, "Maggie", 59000);  // creating an object of Employee
    e1.display();
    e2.display();
    return 0;
}