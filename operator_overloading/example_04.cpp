#include <iostream>
using namespace std;

class Rect
{
public:
    double width;
    double height;

    Rect() {
        width = 0;
        height = 0;
    }

    Rect(double a, double b )
    {
        width  = a;
        height = b;
    }

    double area() {
        return width * height;
    }

    friend std::ostream &operator<<(std::ostream &output, Rect &r)
    { 
        output << "width: " << r.width << ", ";
        output << "height: " << r.height << ", ";
        output << "area: " << r.area();

        return output;
    }

    friend std::istream &operator>>(std::istream &input, Rect &r)
    {
        input >> r.width >> r.height;
        return input;            
    }
};

int main()
{
    Rect r1(3.0, 4.0), r2(6.0, 8.0), r3;
    
    cout << "Enter the value of object: \n";
    cin >> r3;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r3: " << r3 << endl;
    
    return 0;
}