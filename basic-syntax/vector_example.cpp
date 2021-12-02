#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // 创建一个向量存储 int 类型数据
    vector<int> vec;
    
    // 显示 vec 的原始大小
    cout << "vector size = " << vec.size() << endl;
    
    // 推入 8 个值到向量中
    for (int i=0; i<8; i++) {
        vec.push_back(i);
    }
    
    // 显示 vec 扩展后的大小
    cout << "extended vector size = " << vec.size() << endl;
    
    // 访问向量中的 8 个值
    for (int i=0; i<8; i++) {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }
    
    // 使用迭代器 iterator 访问值
    vector<int>::iterator v = vec.begin();
    while (v != vec.end()) {
        cout << "value of v = " << *v << endl;
        v++;
    }
    
    return 0;
}