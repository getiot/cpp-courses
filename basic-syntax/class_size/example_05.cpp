#include <iostream>

class CBase
{
    int a;
    static int b;
};

int main(void)
{
    std::cout << "sizeof(CBase) = " << sizeof(CBase)<< std::endl;
    return 0;
}