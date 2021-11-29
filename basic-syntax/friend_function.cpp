#include <iostream>
using namespace std;

class Student
{
public:
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    
    void sayHello() const
    {
        cout << "I am " << this->name << " and i am " << this->age << " years old!" << endl;
    }

    friend void show(Student stu);
    
private:
    string name;
    int age;
};

// 非成员函数
void show(Student stu)
{
    cout << "Call Show, Name = " << stu.name << ", Age = " << stu.age << endl;
}

int main(void)
{
    Student stu("GetIoT.tech", 3);
    show(stu);
    return 0;
}