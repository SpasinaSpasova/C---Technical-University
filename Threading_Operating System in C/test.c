#include<stdio.h>
#include<windows.h>
int a[100];
int n;
HANDLE s;
typedef struct
{
    HANDLE h; // handle 
    DWORD tid; // tid 

}threadinfo;
DWORD WINAPI thread_func(void* p)
{
    
    WaitForSingleObject(s, INFINITE);
	n++;
	a[n]++;
	n--;
    ReleaseSemaphore(s, 1, NULL);

}
int main()
{
	printf("jjkj\n");
	int i;
	 threadinfo* thread_arr;
	 
	  thread_arr = (threadinfo*)malloc(10 * sizeof(threadinfo));


	s = CreateSemaphore(NULL,4, 4, NULL);
	
	for (i = 0; i <= 10; i++)
    {
        thread_arr[i].h = CreateThread(NULL, 0, thread_func, thread_arr + i, CREATE_SUSPENDED, &thread_arr[i].tid);
    }

    for (i = 0; i <= 10; i++)
    {
        ResumeThread(thread_arr[i].h);
    }
    printf("\nmain thread terminated");
    for (i = 0; i <= 100; i++)
    {
       printf("%d\n" , a[i]);
    }
    return 0;
}
