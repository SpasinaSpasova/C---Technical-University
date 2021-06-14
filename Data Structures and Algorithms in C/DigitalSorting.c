#include<stdio.h>
#include<stdlib.h>
void digitalSort(int A[],int min,int max,int arrSize)
{
	int i,j,k;
	int *P=(int*)malloc(sizeof(int)*arrSize+1);
	for (i = min; i <= max; i++)
	{
		P[i] = 0;
	}
    for (j = 0; j < arrSize; j++)
    {
		P[A[j]]++;    	
	}
	j = 0;
	for (i = min; i<= max; i++)
	{
		for (k = 0; k < P[i]; k++)
		{
			A[j++] = i;
		}
		
	}


}



int main()
{
	int n,i,current;
	printf("Please, enter n: ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter cuccrent element: ");
		scanf("%d",&current);
		if(current>=0 && current<=100)
		{
			arr[i]=current;
		}	
		else
		{
			i--;
			
		}
	
	}
	digitalSort(arr,0,100,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
