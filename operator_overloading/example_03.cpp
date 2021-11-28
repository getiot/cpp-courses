#include <iostream>
using namespace std;

class Rect
{
private:
    double width;
    double height;

public:
    Rect(double a, double b)
    {
        width  = a;
        height = b;
    }

    double area() {
        return width * height;
    }

    // 重载小于运算符 ( < ), 按照面积比大小
    bool operator<(Rect& that)
    {
        return this->area() < that.area();
    }
};

int main()
{
    Rect r1(3.0, 5.0), r2(3.5, 4.5);

    cout << "Area of r1 = " << r1.area() << endl;
    cout << "Area of r2 = " << r2.area() << endl;

    if ( r1 < r2 )
        cout << "r1 is less than r2" << endl;
    else
        cout << "r1 is large than r2" << endl;

   return 0;
}