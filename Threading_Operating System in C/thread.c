#include <windows.h>
#include <stdio.h>
typedef struct
{
HANDLE h; // handle 
DWORD tid; // tid 
}threadinfo;

DWORD WINAPI thread_func(void *p)
{
	int i;
	threadinfo *p1=(threadinfo *)p; 

	printf("\nThread %d started",p1->h);
	for(i=0;i<100000000;i++)
	{
		
	}

	printf("\nThread %d terminated",p1->h);
	return 0;
}

int main()
{
	threadinfo *thread_arr; 
	int n,i;

	
	printf("Please, enter the size of the Thread Array: ");
	scanf("%d",&n);
	//dynamic memory allocation
	thread_arr=(threadinfo*)malloc(n*sizeof(threadinfo));
	
	
	for(i=0;i<n;i++)
	{   
	     //without create suspended
		//	thread_arr[i].h=CreateThread(NULL,0,thread_func,thread_arr+i,0,&thread_arr[i].tid);
	
		//with create suspended
		thread_arr[i].h=CreateThread(NULL,0,thread_func,thread_arr+i,CREATE_SUSPENDED,&thread_arr[i].tid);
	
	}
	for(i=0;i<n;i++)
	{
		//for create suspended unblock
		ResumeThread(thread_arr[i].h);
	}
	
	printf("\nMain terminated!");
	//return 0;-> return all threads, after main thread
	ExitThread(0);//main terminated, but still we have started threads
}
