#include <iostream>
using namespace std;

// 第一个命名空间
namespace first_namespace
{
    void func() {
        cout << "Inside first space" << endl;
    }
    
    // 第二个命名空间
    namespace second_namespace
    {
        void func() {
            cout << "Inside second space" << endl;
        }
    }
}

using namespace first_namespace::second_namespace;

int main(void)
{
    // 调用第二个命名空间中的函数
    func();
    return 0;
}