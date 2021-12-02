#include <iostream>
#include<queue>

using namespace std;

int main(void)
{
    priority_queue<int> p; // priority queue declaration
    priority_queue<int> q; // priority queue declaration
    
    p.push(1); // inserting element '1' in p.
    p.push(2); // inserting element '2' in p.
    p.push(3); // inserting element '3' in p.
    p.push(4); // inserting element '4' in p.
    
    q.push(5); // inserting element '5' in q.
    q.push(6); // inserting element '6' in q.
    q.push(7); // inserting element '7' in q.
    q.push(8); // inserting element '8' in q.
    
    p.swap(q);
    
    cout << "Elements of p are : " << endl;
    while (!p.empty()) {
        cout << p.top() << endl;
        p.pop();
    }
    
    cout << "Elements of q are :" << endl;
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
    
    return 0;
}