#include <iostream>
#include <queue>

using namespace std;

void show_queue(queue <int> q)
{
    queue <int> qu = q;
    
    while (!qu.empty()) {
        cout << ' ' << qu.front();
        qu.pop();
    }
    cout << '\n';
}

int main(void)
{
    queue <int> q;
    
    q.push(55);
    q.push(44);
    q.push(33);
    q.push(22);
    q.push(11);
    
    cout << "The queue q is : ";
    show_queue(q);
    
    cout << "\n q.size()  : " << q.size();
    cout << "\n q.front() : " << q.front();
    cout << "\n q.back()  : " << q.back();

    cout << "\n q.pop() : ";
    q.pop();
    q.pop();
    show_queue(q);
    
    return 0;
}