#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    map<int, string> mapStudent;
#if 1
    // 使用 insert 函数插入 pair 数据
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));

    // 用 insert 函数插入 value_type 数据
    mapStudent.insert(map<int, string>::value_type (1, "student_one"));
    mapStudent.insert(map<int, string>::value_type (2, "student_two"));
    mapStudent.insert(map<int, string>::value_type (3, "student_three"));
#endif
    // 用数组方式插入数据
    mapStudent[1] = "student_one";
    mapStudent[2] = "student_two";
    mapStudent[3] = "student_three";

    cout << "The size of map is: " << mapStudent.size() << endl;

    map<int, string>::iterator iter;
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    {
        cout << iter->first<< ": " << iter->second << endl;
    }

    return 0;
}