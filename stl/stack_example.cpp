#include <iostream>
#include <stack>

using namespace std;

void show_stack(stack <int> s)
{
    stack <int> sg = s;

    while (!sg.empty()) {
        cout << ' ' << sg.top();  // 打印数据
        sg.pop();                 // 出栈
    }
    cout << '\n';
}

int main(void)
{
    stack <int> s;
    
    // 入栈
    s.push(55);
    s.push(44);
    s.push(33);
    s.push(22);
    s.push(11);
    
    cout << "The stack s is : ";
    show_stack(s);

    cout << "\n s.size() : " << s.size();
    cout << "\n s.top()  : " << s.top();
    cout << "\n s.pop()  : ";

    // 出栈
    s.pop();
    s.pop();

    show_stack(s);

    return 0;
}