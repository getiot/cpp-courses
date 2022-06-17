#include <iostream>

class CBase
{
    int  a;
    char *p;

    virtual void FuncA();
};

int main(void)
{
    std::cout << "sizeof(CBase) = " << sizeof(CBase)<< std::endl;
    return 0;
}