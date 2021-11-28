#include <iostream>
using namespace std;

class Cube
{
public:
    double getVolume(void)
    {
        return length * width * height;
    }

    void setLength( double len )
    {
        length = len;
    }

    void setWidth( double bre )
    {
        width = bre;
    }

    void setHeight( double hei )
    {
        height = hei;
    }

    // 重载 + 运算符，用于把两个 Cube 对象相加
    Cube operator+(const Cube& b)
    {
        Cube c;

        c.length = this->length + b.length;
        c.width  = this->width  + b.width;
        c.height = this->height + b.height;

        return c;
    }

private:
    double length;    // 长度
    double width;     // 宽度
    double height;    // 高度
};

int main( )
{
    Cube c1;                // 声明 c1，类型为 Cube
    Cube c2;                // 声明 c2，类型为 Cube
    Cube c3;                // 声明 c3，类型为 Cube
    double volume = 0.0;    // 把体积存储在该变量中

    // 设置 c1 属性
    c1.setLength(10.0); 
    c1.setWidth(10.0); 
    c1.setHeight(10.0);

    // 设置 c2 属性
    c2.setLength(20.0); 
    c2.setWidth(20.0); 
    c2.setHeight(20.0);

    // 获取 c1 的体积
    volume = c1.getVolume();
    cout << "Volume of c1 : " << volume << endl;

    // 获取 c2 的体积
    volume = c2.getVolume();
    cout << "Volume of c2 : " << volume << endl;

    // 把两个对象相加，得到 c3
    c3 = c1 + c2;

    // 获取 c3 的体积
    volume = c3.getVolume();
    cout << "Volume of c3 : " << volume << endl;

    return 0;
}
