#include <iostream>
using namespace std;

class Box
{
public:
    Box()
    {
        cout << "Create a Box" << endl;
    }

    Box(double length, double width, double height)
    {
        this->length = length;
        this->width  = width;
        this->height = height;
    }

    ~Box()
    {
        cout << "Delete a Box" << endl;
    }

    double length;   // 盒子的长度
    double width;    // 盒子的宽度
    double height;   // 盒子的高度
};

int main(void)
{
    Box box(30, 20, 10);

    cout << "Length = " << box.length << ", ";
    cout << "Width = " << box.width << ", ";
    cout << "Height = " << box.height << endl;

    return 0;
}