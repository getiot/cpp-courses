#include <iostream>

// 基类 Shape
class Shape 
{
    public:
        Shape() {
            width = 0;
            height = 0;
        }

        Shape(int a, int b) {
            width = a;
            height = b;
        }

    protected:
        int width;
        int height;
};

// 基类 PaintCost
class PaintCost 
{
    public:
        int cost(int area) { return area * 70; }
};

// 派生类
class Rectangle: public Shape, public PaintCost
{
    public:
        Rectangle(int a,int b):Shape(a,b){}

        int area() { return width * height; }
};

int main(void)
{
    Rectangle rect(5,7);

    int area = rect.area();

    // 输出对象的面积
    std::cout << "Total area: " << area << "\n";

    // 输出总花费
    std::cout << "Total paint cost: $" << rect.cost(area) << "\n";
    
    return 0;
}