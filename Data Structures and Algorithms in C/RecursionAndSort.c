#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*void merge_sort (int l, int r, float A[])
{
	int m;
	if (l < r)
	{
	m = (l + r)/2;
	merge_sort (l, m, A);
	merge_sort (m+1, r, A);
	mergeArr (l, m, r, A);
	}
}
void mergeArr (int l, int m, int r,float *A)
{
	float *T;
	T=(float*)malloc(r*sizeof(float));
	int k,i1,i2,j1,j2,n;
	i1=l;
	i2=m;
	j1=m+1;
	j2=r;
	n=r-l+1;
	k = i1;
	while ((i1<=i2)&&(j1<=j2))
	{
		if (A[i1]<A[j1])
		{
		T[k]=A[i1]; i1++;
		}
		else
		{
		T[k]=A[j1]; j1++;
		}
		k++;
	}
	while (i1<=i2)
	{ 
		T[k]=A[i1]; i1++; k++;
	}
	while (j1<=j2)
	{
		T[k]=A[j1]; j1++; k++;
	}
	for (k=0; k<n; k++)
	{
		j1--;
		A[j1]=T[j1];
	} 	
}

int main()
{
	float arr[]={1,-5,12,16,21,0,3.5,6};
	merge_sort(0,7,arr);
	int i;
	for(i=0;i<8;i++)
	{
		printf("%.2f, ",arr[i]);
	}
	
}*/


//recursion
int fibonaccii (int n)	
{ 
	if (n <= 1) 
	{
		return 1;
	}
	return fibonaccii (n - 1) + fibonaccii (n - 2);
} 

//itterative
int fibonaccii_l (int n)
{
	int i, f1 = 1, f2 = 1, f;
	for (i = 2; i <= n; i++)
		{
		f = f1 + f2; f2 = f1; f1 = f;
		}
	return f;
} 

int main()
{
	int i,n=8,k=5,rec,iter;
	int t1, t2,tRec,tIter;

	for(i=0;i<n;i++)
	{
		t1 = GetTickCount();
		rec=fibonaccii(k);
		t2 = GetTickCount();
		tRec=t2-t1;
		printf("{%d} Time recursion %dms\n", k,tRec);
		k+=5;
	}
	printf("\n");
	t1=0;
	t2=0;
	k=5;
	for(i=0;i<n;i++)
	{
		t1 = GetTickCount();
		iter=fibonaccii_l(k);
		t2 = GetTickCount();
		tIter=t2-t1;
		printf("{%d} Time iterarion %d ms\n", k,tIter);
		k+=5;
	}
}
