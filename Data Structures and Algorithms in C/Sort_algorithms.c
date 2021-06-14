#include<stdio.h>
#include<time.h>
#include<windows.h>
void selection_sort(int A[], int n)
{
	int i, j, x, min;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j <= n-1; j++)
		{
			if (A[j] < A[min])
			min = j;
		}
		if (min != i)
		{
			x = A[min]; A[min] = A[i]; A[i] = x;
		}
	}
}


void insertion_sort(int A[], int n)
{
int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = A[i];
		j = i -1;
		while (j >= 0 && x < A[j])
		{
		A[j+1] = A[j];
		j--;
		}
		A[j+1] = x;
	}
}

void bubble_sort(int A[], int n)
{
int i, j, x;
	for (i = 0; i < n-1; i++)
	{

	for (j = n-1; j > i; j--)
	{
		if (A[j] < A[j-1])
		{
		x = A[j];
		A[j] = A[j-1];
		A[j-1] = x;
		}
	}
	}
}

void bubble_sort_flag( int A[], int n)
{
int i, x, flag;
	do
	{
	flag = 1;
	for(i=0; i<n-1; i++)
	{
		if (A[i]>A[i+1])
		{
			x =A[i];
			A[i] = A[i+1];
			A[i+1] = x;
			flag = 0;
		}
	}
	}
	while (!flag);
}
int main()
{
	int diffSizeOfArr,i,j,k;
    unsigned long long t1,t2;
	
	for(i=1;i<=6;i++)
	{
		printf("size: ");
	    scanf("%d",&diffSizeOfArr);
	    int *arr1=(int*)malloc(diffSizeOfArr*sizeof(int));
	    int *arr2=(int*)malloc(diffSizeOfArr*sizeof(int));
	    int *arr3=(int*)malloc(diffSizeOfArr*sizeof(int));
	    int *arr4=(int*)malloc(diffSizeOfArr*sizeof(int));
		for(j=0;j<diffSizeOfArr;j++)
		{
			arr1[j]=rand();
			arr2[j]=arr1[j];
			arr3[j]=arr1[j];
			arr4[j]=arr1[j];
		}

	    t1= GetTickCount();
		selection_sort(arr1,diffSizeOfArr);
		t2= GetTickCount();
		printf("{%d} selection_sort: %d\n",i,t2-t1);
		t1=0;
		t2=0;
		
		t1= GetTickCount();
		insertion_sort(arr2,diffSizeOfArr);
	 	t2= GetTickCount();
		printf("{%d} insertion_sort: %d\n",i,t2-t1);
		t1=0;
		t2=0;
		
		t1= GetTickCount();
		bubble_sort(arr3,diffSizeOfArr);
		t2= GetTickCount();
		printf("{%d} bubble_sort: %d\n",i,t2-t1);
		t1=0;
		t2=0;
		
		t1= GetTickCount();
		bubble_sort_flag(arr4,diffSizeOfArr);
		t2= GetTickCount();
		printf("{%d} bubble_sort_flag: %d\n",i,t2-t1);
		t1=0;
		t2=0;
	}
	
return 0;
}
