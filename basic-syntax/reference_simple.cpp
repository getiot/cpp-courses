#include <iostream>
using namespace std;

void printNum(const int &num)
{
    cout << "Num = " << num << endl;
}

int main()
{
    int a = 1992;  // 普通变量
    int &ra = a;   // 引用变量

    //printNum(a);
    
    cout << "before a = " << a << endl;
    
    ra = 2021;     // 通过引用修改变量
    
    cout << "after  a = " << a << endl;
    
    return 0;
}