#include <iostream> 
using namespace std;

class Shape
{
protected:
    int width, height;
public:
    Shape(int w=0, int h=0)
    {
        width = w;
        height = h;
    }
    virtual int area()
    {
        cout << "Parent class area : ";
        return 0;
    }
};

class Rectangle: public Shape
{
public:
    Rectangle(int w=0, int h=0):Shape(w, h) { }
    int area()
    {
        cout << "Rectangle class area : ";
        return (width * height);
    }
};

class Triangle: public Shape
{
public:
    Triangle(int w=0, int h=0):Shape(w, h) { }
    int area()
    {
        cout << "Triangle class area : ";
        return (width * height / 2);
    }
};

int main(void)
{
    Shape *shape;
    Rectangle rec(10, 5);  // 创建矩形实例
    Triangle  tri(10, 5);  // 创建三角形实例
    
    shape = &rec;                   // 存储矩形的地址
    cout << shape->area() << endl;  // 调用矩形的求面积函数 area
    
    shape = &tri;                   // 存储三角形的地址
    cout << shape->area() << endl;  // 调用三角形的求面积函数 area
    
    return 0;
}
