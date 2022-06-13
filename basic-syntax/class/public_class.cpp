#include <iostream>
using namespace std;

class A
{
public:
    A() { a = 12; }
    int a;
};

class B: public A  /* must use public */
{
public:
    B(): A() {}

};

int main(void)
{
    B b;
    cout << b.a << endl;  /* because public */

    return 0;
}