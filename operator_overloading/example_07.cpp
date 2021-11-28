#include <iostream>
using namespace std;

class Rect
{
private:
    int width;
    int height;

public:
    Rect() {
        width  = 0;
        height = 0;
    }

    Rect(int a ,int b) {
        width  = a;
        height = b;
    }

    void operator()() {
        cout << "Area of myself is:" << width * height << endl;
    }
};

int main()
{
    Rect r1(3, 4), r2(6, 8);

    cout << "r1: "; 
    r1();

    cout << "r2: ";
    r2();
    
    return 0;
}