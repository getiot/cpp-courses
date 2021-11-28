#include <iostream>
using namespace std;

// 定义一个结构体 Book，顺带定义一个 book1 实例和一个 book2 指针
struct Book {
    const char*  title;
    const char*  author;
    const char*  category;
    int          isbn;
} book1, *book2;

// 定义一个函数用于打印结构体 Book 的信息
void show_book(struct Book &book)
{
    cout << "《" << book.title << "》" << "的编号是: " << book.isbn;
    cout << " , 放在书架 " << book.category;
    cout << " , 作者是："  << book.author << endl;
}

int main(void)
{
    book2 = &book1;
    
    book1.title    = "C++ 基础教程";
    book1.author   = "人人都懂物联网";
    book1.category = "IT 技术";
    book1.isbn     = 12345678;
    
    show_book(book1);
    
    book2->title    = "C++ 高级教程";
    book2->author   = "GetIoT";
    book2->category = "物联网";
    book2->isbn     = 87654321;

    show_book(book1);

    return 0;
}