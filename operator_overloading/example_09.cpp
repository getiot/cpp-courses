#include <iostream>
#include <vector>

using namespace std;

// 假设一个实际的类
class Obj
{
    static int i, j;

public:
    void f() const { cout << i++ << endl; }
    void g() const { cout << j++ << endl; }
};

// 静态成员定义
int Obj::i = 10;
int Obj::j = 12;

// 为上面的类实现一个容器
class ObjContainer
{
    std::vector<Obj*> a;

public:
    void add(Obj* obj) {
        a.push_back(obj);  // 调用向量的标准方法
    }

    friend class SmartPointer;
};

// 实现智能指针，用于访问类 Obj 的成员
class SmartPointer {
    ObjContainer oc;
    int index;

public:
    SmartPointer(ObjContainer& objc)
    {
        oc = objc;
        index = 0;
    }
    // 前缀版本
    // 返回值表示列表结束
    bool operator++() 
    {
        if(index >= oc.a.size())
            return false;
        
        if(oc.a[++index] == 0)
            return false;
        
        return true;
    }
    // 后缀版本
    bool operator++(int)
    {
        return operator++();
    }

    // 重载运算符 ->
    Obj* operator->() const 
    {
        if(!oc.a[index]) {
            std::cout << "Zero value";
            return (Obj*)0;
        }

        return oc.a[index];
    }
};

int main() 
{
    const int sz = 6;

    Obj o[sz];
    ObjContainer oc;

    for(int i=0; i<sz; i++) {
        oc.add(&o[i]);
    }

    SmartPointer sp(oc); 

    do {
        sp->f(); 
        sp->g();
    } while(sp++);

    return 0;
}