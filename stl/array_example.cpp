#include <iostream>
#include <array>

using namespace std;

int main(void)
{
    array<int, 4> arr;

    // 填充数组
    for (int i=0; i<arr.size(); i++) {
        arr.at(i) = i + 1;
    }

    // 使用 at 方法获取数组内容
    for (int i=0; i<arr.size(); i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    // 使用 get 方法获取数组内容
    cout << get<1>(arr) << endl;
    cout << get<2>(arr) << endl;

    // 使用 data 方法获取数组内容
    for (int i=arr.size()-1; i>=0; i--) {
        cout << *(arr.data()+i) << " ";
    }
    cout << endl;
    
    return 0;
}
