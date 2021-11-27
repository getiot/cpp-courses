#include <iostream>
using namespace std;

float s;
float &Circle(float r)
{
    s = 3.14 * r * r;
    return s;
}

int main()
{
    float r = 10.0;
    Circle(r);
    cout << "S = " << s << endl;
    return 0;
}