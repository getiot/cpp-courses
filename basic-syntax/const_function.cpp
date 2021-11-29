#include <iostream>
using namespace std;

class GetIoT
{
public:
    GetIoT(int value=0) {
        this->value = value;
    }
    
    int getValue() {
        return value;
    }
    
    const int getValue1() {
        value = 1;
        return value;
    }
    
    int getValue2() const {
        value = 2;           // 出错, 因为函数后面加 const，不能修改成员变量
        return value;
    }
    
private:
    int value;
};

int main(void)
{
    GetIoT getiot(3);
    
    cout << "getValue: " << getiot.getValue() << endl;
    cout << "getValue1: " << getiot.getValue1() << endl;
    cout << "getValue2: " << getiot.getValue2() << endl;

    return 0;
}