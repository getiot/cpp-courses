#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max (T const& a, T const& b) 
{
    return a < b ? b : a;
}

int main(void)
{
    int i = 39;
    int j = 67;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 3.15;
    double f2 = 20.87;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello"; 
    string s2 = "GetIoT";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

   return 0;
}