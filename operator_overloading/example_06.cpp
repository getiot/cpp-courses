#include <iostream>
using namespace std;

class Rect
{
private:
    double width;
    double height;

public:
    Rect() {
        width = 0;
        height = 0;
    }

    Rect(double a, double b) {
        width = a;
        height = b;
    }

    void display() {
        cout << " width: " << width;
        cout << " height: " << height;
    }

    void operator= (const Rect &r)
    {
        width = r.width + 1;
        height = r.height + 1;
    }
};

int main()
{
    Rect r1(3.0, 4.0), r2;
    
    r2 = r1;

    cout << "r1: ";
    r1.display();
    cout << endl;

    cout << "r2: ";
    r2.display();
    cout << endl;

    return 0;
}