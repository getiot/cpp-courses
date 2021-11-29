#include <iostream>
using namespace std;

class Box
{
public:
    Box() {
        cout << "调用构造函数 :)" << endl;
    }
    ~Box() {
        cout << "调用析构函数 _(:з」∠)_" <<endl;
    }
};

int main(void)
{
    Box* myBoxArray = new Box[4];
    
    delete [] myBoxArray; // 删除数组
    return 0;
}