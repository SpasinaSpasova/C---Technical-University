#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

LARGE_INTEGER v1, v2;
HANDLE m1, m2;
int sum = 0;
int* arr;
int n;
int isFirst = 0;
int allFinished = 0;
struct threadinfo
{
    HANDLE handle;
    DWORD tid;
    int start_index, end_index, sum;
};

DWORD WINAPI thread_func(void* p)
{
	int i;
    WaitForSingleObject(m1, INFINITE);
    if (isFirst == 0)
    {
        QueryPerformanceCounter(&v1);
    }
    isFirst++;
    ReleaseMutex(m1);

    struct threadinfo* p1 = (struct threadinfo*)p;
    for ( i = p1->start_index; i <= p1->end_index; i++)
    {
        p1->sum += *(arr + i);
    }
    sum += p1->sum;

    WaitForSingleObject(m2, INFINITE);
    allFinished++;
    if (allFinished == n)
    {
        QueryPerformanceCounter(&v2);
        printf("the execution time is : % d\n", (int)(v2.QuadPart - v1.QuadPart) / 1000);
    }
    ReleaseMutex(m2);

    return 0;
}


int main()
{
	int i;
    m1 = CreateMutex(NULL, FALSE, NULL);
    m2 = CreateMutex(NULL, FALSE, NULL);
    printf("\nEnter the number of threads: ");
    scanf("%d", &n);

    // printf("\nEnter the number of integers in the array: ");
    int m = 200000000;
    //scanf("%d", &m);
    arr = (int*)malloc(m * sizeof(int));
    int r = m / n;

    struct threadinfo* threads = (struct threadinfo*)malloc(sizeof(struct threadinfo) * n);

    for ( i = 0; i < n; i++)
    {
        threads[i].handle = CreateThread
        (
            NULL,
            0,       // Stack size 
            thread_func, // Thread func
            threads + i,    // thread
            CREATE_SUSPENDED,       // Creation flag                     
            &threads[i].tid   // Thread func parameter
        );
        threads[i].start_index = i * r;
        threads[i].end_index = i * r + r - 1;
        threads[i].sum = 0;
    }
    threads[n - 1].end_index = m - 1;

    for ( i = 0; i < n; i++)
    {
        ResumeThread((threads + i)->handle);

    }
    ExitThread(0);
}
