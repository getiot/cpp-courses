#include <iostream>  
#include <map>  
#include <string>  
  
using namespace std;  
  
int main(void)  
{
    multimap<string, string> m = {
        {"China","Shanghai"},
        {"China", "Guangzhou"},
        {"Thailand", "Chiang Mai"},
        {"Netherlands", "Amsterdam"},
        {"United Kingdom", "London"},
        {"United States", "Los Angeles"}
    };

    cout << "Size of map m: " << m.size() << endl;
    cout << "Elements in m: " << endl;

    for (multimap<string, string>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << "  [" << (*it).first << ", " << (*it).second << "]" << endl;
    }

    return 0;
}