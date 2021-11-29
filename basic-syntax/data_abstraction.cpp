#include <iostream>
using namespace std;

class Muler
{
public:
    // 构造函数
    Muler(int i = 1) {
        total = i;
    }
    
    // 对外的接口
    void mulNum(int number) {
        total *= number;
    }
    
    // 对外的接口
    int getTotal() {
        return total;
    };
    
private:
    // 对外隐藏的数据
    int total;
};

int main(void)
{
    Muler a;
    
    a.mulNum(3);
    a.mulNum(7);
    a.mulNum(11);
    
    cout << "Total " << a.getTotal() << endl; 
    return 0;
}