#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
    char data[1024];
    
    // 以写模式打开文件
    ofstream outfile;
    outfile.open("demo.txt");
    
    cout << "Writing to the file >>" << endl;
    cout << "Enter your name: "; 
    cin.getline(data, 1024);
    
    // 向文件写入用户输入的数据
    outfile << "Name:" << data << endl;
    
    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();
    
    // 再次向文件写入用户输入的数据
    outfile << "Age:" << data << endl;
    
    // 关闭打开的文件
    outfile.close();
    
    // 以读模式打开文件
    ifstream infile;
    infile.open("demo.txt");
    
    cout << "Reading from the file >>" << endl;
    infile >> data;
    
    // 在屏幕上写入数据
    cout << data << endl;
    
    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;
    
    // 关闭打开的文件
    infile.close();
    return 0;
}