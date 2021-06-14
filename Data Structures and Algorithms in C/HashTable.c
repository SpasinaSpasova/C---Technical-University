#include<stdio.h>
int main()
{
	int i,current,k=0;
 
	int arr[1001];


	for(i=0;i<1001;i++)
	{
		arr[i]=0;
	}
	

		
	while(1)
	{
		printf("Enter cuccrent element: ");
		scanf("%d",&current);
		
		k=current%997;
	
		if(arr[k]==0)
		{
			arr[k]=current;
		}
		else	
		{
			break;
		}
		
	
		
	}
	
	//принтираме
	for(i=0;i<1001;i++)
	{
		if(arr[i]!=0)
		{
			printf("Arr [%d]=> %d\n",i,arr[i]);
		}	
	}
	
	return 0;

}
