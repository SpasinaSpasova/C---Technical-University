#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//global variables
 HANDLE globalh;
 int count=0; 
 HANDLE thMutex;
 
 //struct
typedef struct 
{
	HANDLE h;
	DWORD tid;
}threadinfo;

//thread function
DWORD WINAPI Thread_Function(void *p)
{
	int i,j;
	
	threadinfo *p1=(threadinfo *)p;
	printf("\nThread %d started",p1->h);
	
	//P(mutex)
	WaitForSingleObject(thMutex,INFINITE);
	
	for(i=0;i<10000;i++)
	{
	
		globalh=p1[i].h;
		for(j=0;j<10000;j++);
		if(globalh!=p1[i].h)
		{
			count++;
		}
	}
	//V(mutex)
	ReleaseMutex(thMutex);
	printf("\nThread %d terminated",p1->h);
	return 0;
} 

int main()
{
	int n,i;
	threadinfo *th;
	
	printf("Enter n: ");
	scanf("%d",&n);
	
	th=(threadinfo*)malloc(n*sizeof(threadinfo));
	
	 	// create mutex
	thMutex = CreateMutex( 
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);  

	for(i=0;i<n;i++)
	{
	  	th[i].h=CreateThread(NULL,0,Thread_Function,th+i,CREATE_SUSPENDED,&th[i].tid);
	}
	for(i=0;i<n;i++)
	{
		ResumeThread(th[i].h);
	}
	
	scanf("%d",&i);
	
	printf("Count is %d ",count);
	
	ExitThread(0);
}
