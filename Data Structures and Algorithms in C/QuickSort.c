#include<stdio.h>
#include<stdlib.h>
void quicksort(float A[], int start, int stop)
{
    int i=start, j=stop;
    float m;
	m=A[(start+stop)/2];
	do
	{
	while (A[i]<m) i++;
	while (A[j]>m) j--;

	if(i<=j)
	{
		float temp=A[i];
		A[i]=A[j];
		A[j]=temp;
		i++; j--;
	}
	}while (i<=j);

	if (start < j)
	{
		quicksort(A, start, j);

	}
	if (i < stop)
	{
		quicksort(A, i, stop);
	
	}
 
}
int main()
{
	int n,i;
	float current;
	printf("Please, enter n: ");
	scanf("%d",&n);
	float* arr;
	arr=(float*)malloc(sizeof(float)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter cuccrent element: ");
		scanf("%f",&current);
		arr[i]=current;
	}
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%.2f ", arr[i]);
	}
}
