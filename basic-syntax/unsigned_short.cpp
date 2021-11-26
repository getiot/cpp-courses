#include <iostream>
using namespace std;

#define NUMBER 49000

int main()
{
    short int i;           // 有符号短整数
    short unsigned int j;  // 无符号短整数

    j = NUMBER;
    i = NUMBER;
    cout << i << " " << j << endl;

    return 0;
}