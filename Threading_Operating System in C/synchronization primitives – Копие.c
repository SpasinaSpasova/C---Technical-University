#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

HANDLE sem, mutex;
int counter = 0;
int size = 1000000;
HANDLE th;

typedef struct
{
    HANDLE h; // handle 
    DWORD tid; // tid 

}threadinfo;

DWORD WINAPI thread_func(void* p)
{
    int i;
    threadinfo* p1 = (threadinfo*)p;
    printf("\nthread %d started", p1->h);
    
    while (1) {
        srand(time(0));
        int num = rand();
        WaitForSingleObject(mutex, INFINITE);
        if (num % 5 == 0) {
            counter++;
            if (counter == size) {
                th = p1->h;
                ReleaseSemaphore(sem, 1, NULL);
            }
        }
        ReleaseMutex(mutex);
    }

    printf("\nthread %d terminated\n", p1->h);
    
    return 0;
}

int main()
{
    threadinfo* thread_arr;
    int i, n;

    printf("Enter n: ");
    scanf_s("%d", &n);
    thread_arr = (threadinfo*)malloc(n * sizeof(threadinfo));

    mutex = CreateMutex(NULL, FALSE, NULL);
    sem = CreateSemaphore(NULL, 0, 1, NULL);

    for (i = 0; i < n; i++)
    {
        thread_arr[i].h = CreateThread(NULL, 0, thread_func, thread_arr + i, CREATE_SUSPENDED, &thread_arr[i].tid);
    }

    for (i = 0; i < n; i++)
    {
        ResumeThread(thread_arr[i].h);
    }

     WaitForSingleObject(sem, INFINITE);
    

    printf("\nthread handle = %d", th);
    
    printf("\nmain thread terminated");

    return 0;
}


