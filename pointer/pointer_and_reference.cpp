#include <iostream>

using namespace std;

void change(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 10;
    int *i = &x;
    int &j = x;

    cout << i << endl;
    cout << *i << endl;

    cout << j << endl;
    cout << &j << endl;

    cout << sizeof(i) << endl;
    cout << sizeof(*i) << endl;
    cout << sizeof(j) << endl;

    int a = 10;
    int b = 20;

    change(a, b);

    cout << a << endl;
    cout << b << endl;
    //cout << c << endl;

    return 0;
}
