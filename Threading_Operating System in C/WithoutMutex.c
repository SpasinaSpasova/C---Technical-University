#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//global variables
 HANDLE globalh;
 int count=0; 
 
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
	
	for(i=0;i<10000;i++)
	{
		
		globalh=p1->h;
		for(j=0;j<10000;j++);
		if(globalh!=p1->h)
		{
			count++;
		}
	}
	
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
