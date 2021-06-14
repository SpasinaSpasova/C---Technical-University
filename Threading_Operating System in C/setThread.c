#include<stdio.h>
#include<windows.h>

int *arr;

typedef struct  
{ 
HANDLE h; 
DWORD tid; 
int start_index,end_index,sum; 
}threadinfo;



DWORD WINAPI SumThread(void *p) 
{ 
	int i;
	threadinfo *p1=(threadinfo *)p; 
	printf("thread %d started\n",p1->h); 
	

	for(i=p1->start_index;i<=p1->end_index;i++)
	{
		p1->sum+=arr[i];
	
	}

		
printf("thread %d terminated\n",p1->h); 
return 0; 
}

int main()
{
	int n,m,r,i,total=0;
	
	threadinfo *th;
	
	//динамично заделяне на памет за th
	printf("Please, enter the size of the Thread Array: \n");
	scanf("%d",&n);
	th=(threadinfo*)malloc(n*sizeof(threadinfo));
	
	//динамично заделяне на памет за Arr
	printf("Please, enter the size of the Array: \n");
	scanf("%d",&m);
	arr=(int*)malloc(m*sizeof(int));
	
	r=m/n;
	
	for(i=0;i<m;i++)
	{
		arr[i]=i;
		
	}
	for(i=0;i<n;i++)
	{
	
		th[i].start_index=r*i;
	    th[i].end_index=(i+1)*r-1;
	    th[i].sum=0;
	  	th[i].h=CreateThread(NULL,0,SumThread,th+i,CREATE_SUSPENDED,&th[i].tid);
	  	ResumeThread(th[i].h);
	}
	
	th[n-1].end_index=m-1;

 	
	scanf_s("%d", &i);
	
	for(i=0;i<n;i++)
	{
		printf("Thread %d sum: %d \n",th[i].h,th[i].sum);
		total=total+th[i].sum;
	}

	printf("Total sum: %d \n",total);
	
	ExitThread(0);
  
}
