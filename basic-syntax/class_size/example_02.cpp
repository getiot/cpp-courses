#include <iostream>

class CBase
{
    int  a;
    char *p;
};

int main(void)
{
    std::cout << "sizeof(CBase) = " << sizeof(CBase)<< std::endl;
    return 0;
}