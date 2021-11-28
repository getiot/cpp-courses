#include <iostream>
using namespace std;

class Box
{
    double length;  // 长度
    double width;   // 宽度
    double height;  // 高度

public:
    Box () {
        length = 0.0;
        width  = 0.0;
        height = 0.0;
    }

    Box (double a, double b ,double c)
    {
        length = a;
        width  = b;
        height = c;        
    }

    double getVolume(void)
    {
        return length * width * height;
    }

    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.width  = this->width + b.width;
        box.height = this->height + b.height;
        return box;
    }
};

int main(void)
{
    Box b1(5.0, 4.0, 3.0);
    Box b2(6.0, 5.0, 4.0);
    Box b3;

    cout << "Volume of b1 : " << b1.getVolume() << endl;
    cout << "Volume of b2 : " << b2.getVolume() << endl;

    // 把两个对象相加，得到 Box3
    b3 = b1 + b2;

    // Box3 的体积
    cout << "Volume of b3 : " << b3.getVolume() << endl;

    return 0;
}