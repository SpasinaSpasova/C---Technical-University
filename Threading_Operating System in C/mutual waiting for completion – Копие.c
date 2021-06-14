#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int n;

typedef struct
{
    HANDLE h; // handle 
    DWORD tid; // tid 

}threadinfo;

threadinfo* thread_arr;


DWORD WINAPI thread_func(void* p)
{
    int i;
    threadinfo* p1 = (threadinfo*)p;
    printf("\nthread %d started", p1->h);
    for (i = 0; i < 100000000; i++)
    {

    }
    
    for (i = 0; i < n; i++) {
        if (thread_arr[i].tid < p1->tid) {
            WaitForSingleObject(thread_arr[i].h, INFINITE);
        }
    }

    printf("\nthread h = %d, tid = %d terminated\n", p1->h, p1->tid);
    return 0;
}

int main()
{
    int i;

    printf("Enter n: ");
    scanf_s("%d", &n);
    thread_arr = (threadinfo*)malloc(n * sizeof(threadinfo));

    for (i = 0; i < n; i++)
    {
        thread_arr[i].h = CreateThread(NULL, 0, thread_func, thread_arr + i, CREATE_SUSPENDED, &thread_arr[i].tid);
    }

    for (i = 0; i < n; i++)
    {
        ResumeThread(thread_arr[i].h);
    }

    printf("\nmain thread terminated");
    ExitThread(0);
}


