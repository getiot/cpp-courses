#include <iostream>

using namespace std;

//变量声明
extern int a, b, c;
extern float f;

int main ()
{
    // 变量定义
    int a, b, c;
    float f;

    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl ;

    f = 20.0/3.0;
    cout << f << endl ;

    return 0;
}