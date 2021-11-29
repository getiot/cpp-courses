#include <iostream>
#include <exception>

struct MyException : public std::exception
{
    const char * what () const throw ()
    {
        return "My C++ Exception";
    }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch (MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::exception& e)
    {
        // 其他的错误
    }
    
    return 0;
}