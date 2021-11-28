#include <iostream>
using namespace std;

const int SIZE = 10;

class Fibo
{
private:
    // 偷懒，防止把 SIZE 设置的过小
    int arr[SIZE+3];

public:
    Fibo() {
        arr[0] = 0;
        arr[1] = 1;

        for(int i=2; i<SIZE; i++) {
            arr[i] = arr[i-2] + arr[i-1];
        }
    }

    int& operator[](unsigned int i) {
        if (i >= SIZE) {
            std::cout << "(索引超过最大值) ";
            return arr[0]; // 返回第一个元素
        }
        return arr[i];
    }
};

int main()
{
    Fibo fb;
    
    for (int i=0; i<SIZE+1; i++) {
        cout << fb[i] << " ";
    }
    cout << endl;
    
    return 0;
}