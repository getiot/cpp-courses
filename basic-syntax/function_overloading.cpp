#include <iostream>
using namespace std;

class GetIoT
{
public:
    void show(int i) 
    {
        cout << "Int: " << i << endl;
    }

    void show(double f) 
    {
        cout << "Float: " << f << endl;
    }

    void show(const char* s) 
    {
        cout << "String: " << s << endl;
    }
};

int main(void)
{
   GetIoT getiot;

   // 调用 show 函数输出 int 数据类型
   getiot.show(64);

   // 调用 show 函数输出 float 数据类型
   getiot.show(3.1415926);

   // 调用 show 函数输出 string 数据类型
   getiot.show("Welcome to getiot.tech");

   return 0;
}