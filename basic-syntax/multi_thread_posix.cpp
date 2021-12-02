#include <iostream>
#include <pthread.h>

using namespace std;

// 定义线程数量
#define NUM_THREADS 10

// 线程函数实体
void *thread_entry(void* args)
{
    // 对传入的参数进行强制类型转换
    // 由无类型指针变为整形数指针，然后再读取
    int tid = *(int *)args;

    cout << tid << ": Hello thread!" << endl;

    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tids[NUM_THREADS];
    int index[NUM_THREADS];

    // 创建线程
    for (int i=0; i<NUM_THREADS; i++)
    {
        index[i] = i;
        pthread_create(&tids[i], NULL, thread_entry, (void *)&index[i]);
    }

    // 等待线程完成
    for (int i=0; i<NUM_THREADS; i++)
    {
        pthread_join(tids[i], NULL);
    }

    pthread_exit(NULL);

    return 0;
}