#include <iostream>
using namespace std;

#define PI           3.1415926
#define MKSTR( x )   (#x)
#define CONCAT(a, b) (a ## b)

int main(void)
{
    cout << "Value of PI is :" << PI << endl;
    cout << MKSTR(HELLO 人人都懂物联网) << endl;

    double xy = 99.999;
    
    cout << CONCAT(x, y) << endl;
    //cout << CONCAT(HELLO, 人人都懂物联网) << endl;
    
    return 0;
}
