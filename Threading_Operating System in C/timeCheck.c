#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

LARGE_INTEGER v1, v2,v3,v4;

typedef struct 
{
int id;
char fname[20];
char lname[20];
}person;

int main()
{
	int i;
	person *arr=(person*)malloc(10000000*sizeof(person));
	int *arr_id=(int*)malloc(10000000*sizeof(int));
	
	QueryPerformanceCounter(&v1);
	for(i=0;i<10000000;i++)
	{
		if (arr[i].id==10)
		{
			arr[i].id=0;
		} 
	}
	QueryPerformanceCounter(&v2);
	printf("Person array %d\n",(int)(v2.QuadPart - v1.QuadPart) / 1000);
	
	QueryPerformanceCounter(&v3);
	for(i=0;i<10000000;i++)
	{
		if (arr_id[i]==10)
		{
			arr_id[i]=0;
		} 
	}
	QueryPerformanceCounter(&v4);
	printf("Id array %d\n",(int)(v4.QuadPart - v3.QuadPart) / 1000);
	free(arr);
	free(arr_id);
	return 0;
}
