#include<stdio.h>
int main()
{
	int i,current,k,n;
	
	
	int helpArr[101];
	
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
	//���������� ���������� �� �������� �����
	for(i=0;i<101;i++)
	{
		helpArr[i]=0;
	}
    //����������� ��������� �� ������� ������ � �������� ����� � + 1
	for(i=0;i<n;i++)
	{
		k=arr[i];
		
		helpArr[k]++;
		
	}
	//����������
	for(i=0;i<101;i++)
	{
		if(helpArr[i]!=0)
		{
			printf("Element %d => count %d\n",i,helpArr[i]);
		}	
	}

}
