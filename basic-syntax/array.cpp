#include <iostream>
#include <iomanip>

using std::setw;

const int LEN = 10;

char hello1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char hello2[6] = "Hello";
char hello3[] = "Hello";

int main ()
{
    int arr[ LEN ]; // arr 是一个包含 10 个整数的数组

    // 初始化数组元素          
    for ( int i=0; i<LEN; i++ )
    {
        arr[i] = i + 128; // 设置元素 i 为 i + 128
    }

    std::cout << "Element" << std::setw(13) << "Value" << std::endl;

    // 输出数组中每个元素的值                     
    for ( int j=0; j<10; j++ )
    {
        std::cout << setw(7)<< j << std::setw( 13 ) << arr[j] << std::endl;
    }

    std::cout << hello1 << sizeof(hello1) << std::endl;
    std::cout << hello2 << sizeof(hello2) << std::endl;
    std::cout << hello3 << sizeof(hello3) << std::endl;

    return 0;
}