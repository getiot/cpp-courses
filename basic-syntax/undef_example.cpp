#include <iostream>
using namespace std;

#define PI 3.1415926
int main(void)
{
    cout << "PI = " << PI << endl;
    #undef PI
    cout << "PI = " << PI << endl;
    return 0;
}