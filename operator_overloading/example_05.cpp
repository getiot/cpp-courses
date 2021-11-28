#include <iostream>
using namespace std;

class Time
{
private:
    int minute;             
    int second;

public:
    Time () {
        minute = 0;
        second = 0;
    }

    Time (int m, int s) {
        minute = m;
        second = s;
    }

    void display() {
        cout << minute << " : " << second << endl;
    }

    // 重载前缀递增运算符 ( ++ )
    Time operator++() {
        second++;

        if (second >= 60) {
            minute++;
            second = 0;
        }

        return Time(minute, second);
      }
    
    // 重载后缀递增运算符（ ++ ）
    Time operator++(int)
    {
        Time t(minute, second);  // 保存原始值
        second++;                // 对象加 1

        if (second >= 60) {
            minute++;
            second = 0;
        }

        return t;  // 返回旧的原始值
    }
};

int main()
{
    Time t1(12, 58), t2(0,45);
    
    t1.display();
    (++t1).display();
    (++t1).display();
    
    t2.display();
    (t2++).display();
    (t2++).display();
    
    return 0;
}