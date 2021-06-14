#include<stdio.h>
#include<stdlib.h>
int *A;
int seq_search_unorder (int x,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i] == x)
		{
			return i;
		}
	}

	return -1;
}
int newElement_search(int x,int n)
{
	A[n] = x;
	int i = 0;
	while ( A[i] != x)
	{
		i++;	
	}
	if ( i < n )
	{
		return i;	
	}
return -1;
}

int seq_Search_order (int x,int n)
{
	int i=0;
	while (i < n && A[i]<=x)
	{
		if (A[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}


int BinSearch(int x,int n)
{
	int l = 0, r = n-1, m;
	while (l <= r)
	 {
		m = (l + r) / 2;
		
		if (x < A[m]) 
		{
			r = m - 1;	
		}
		else
		{
			if (x > A[m])
			{
				l = m + 1;		
			}
			else 
			{
				return m;
			}
		}
	 }
	return -1;
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
	
	
	 printf ("Result from seq_search_unorder %d\n ",seq_search_unorder(4,n));
	 printf ("Result from newElement_search %d\n ",newElement_search(4,n));
	 printf ("Result from seq_Search_order %d\n ",seq_Search_order(4,n));
	 printf ("Result from BinSearch %d\n ",BinSearch(4,n));
}

