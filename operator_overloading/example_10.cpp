#include <iostream>
using namespace std;

class Rect
{
private:
    int width;
    int height;

public:
    Rect() {
        width = 0;
        height = 0;
    }

    Rect( int a, int b ) {
        width = a;
        height = b;
    }

    int area () {
        return width * height;
    }

    // 当 width 或者 height 有一个小于 0 则返回 true
    bool operator!() {
        if ( width <= 0 || height <= 0 ) {
            return true;
        }
        return false;
    }
};

int main()
{
    Rect r1(3, 4), r2(-3, 4);

    if (!r1) cout << "r1 is not a rectangle" << endl;
    else cout << "r1 is a rectangle" << endl;

    if (!r2) cout << "r2 is not a rectangle" << endl;
    else cout << "r2 is a rectangle" << endl;
    
    return 0;
}