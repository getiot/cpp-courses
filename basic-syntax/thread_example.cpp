#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

static const int nt=10;

void Hello(int num)
{
    cout << num << ": Hello thread!" << endl;
}

int main(void)
{
    thread t[nt];
    
    for (int i=0; i<nt; i++) {
        t[i] = thread(Hello, i);
        t[i].detach();
    }
    
#if 0
    for (int i=0; i<nt; i++) {
        t[i].join();
    }
#endif

    cout << "Main thread exit." << endl;
    sleep(1);
    
    return 0;
}