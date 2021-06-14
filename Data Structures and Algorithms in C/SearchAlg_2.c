#include<stdio.h>
#include<stdlib.h>
int *A;
void seq_search_unorder (int x,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i] == x)
		{
			printf("seq_search_unorder %d",i);
		}
	}
}

void seq_Search_order (int x,int n)
{
	int i=0;

	while (i < n && A[i]<=x)
	{
		if (A[i] == x)
		{
			printf("seq_Search_order %d",i);
		}
		i++;
	}
	
}

int main()
{
	int n,i;
	
	printf("Insert n: ");
	scanf("%d",&n);
	A=(int*)malloc(n+1*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	seq_search_unorder(1,n);
	printf("\n\n");

	seq_Search_order(1,n);
	printf("\n\n");

	
}
