#include <iostream>
using namespace std;

// 基类
class Shape 
{
public:
    // 构造函数
    Shape(int w=0, int h=0) {
        width = w;
        height = h;
    }
    // 提供接口框架的纯虚函数
    virtual int getArea() = 0;
    
    void setWidth(int w) {
        width = w;
    }
    
    void setHeight(int h) {
        height = h;
    }
protected:
    int width;
    int height;
};

// 派生类
class Rectangle: public Shape
{
public:
    Rectangle(int w, int h): Shape(w, h) {}

    int getArea() {
        return (width * height);
    }
};

class Triangle: public Shape
{
public:
    Triangle(int w, int h): Shape(w, h) {}

    int getArea() {
        return (width * height)/2;
    }
};

int main(void)
{
    Rectangle rect(6, 8);
    Triangle  tri(6, 8);
    
    // 输出对象的面积
    cout << "Total Rectangle area is : " << rect.getArea() << endl;
    cout << "Total Triangle area is  : " << tri.getArea() << endl;
    
    return 0;
}