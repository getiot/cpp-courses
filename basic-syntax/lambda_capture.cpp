#include <iostream>
using namespace std;

int main(void)
{
    int a = 100, b = 200;
    auto f = [a, b] { int c = a + b; cout << c << endl; };
    f(); // 输出 300

    // 或通过“函数体”后面的‘()’传入参数，输出 123
    auto x = [](int a) -> int { cout << a << endl; return a; }(123);
    
    return 0;
}