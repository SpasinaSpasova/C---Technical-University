#include<stdio.h>
int main()
{
	int n=6,total=0,i,p,k;
	//������ �������� ��� ����������� ��
    int* gifts=(int*)malloc(sizeof(int)*n);
    gifts[0]=3;
    gifts[1]=7;
    gifts[2]=5;
    gifts[3]=0;
    gifts[4]=7;
    gifts[5]=6;
    //�������� ������ ���� �� ������ ��������
    for(i=0;i<n;i++)
    {
    	total+=gifts[i];
	}
	printf("All gifts price: %d\n",total);
	
	//�������� �����
	int* can=(int*)malloc(sizeof(int)*total+1);
	can[0]=1;//������� 1��
   
   //���������� ���������� �������� � �������� �����
   	for (i=1;i<total+1;i++)
   	{
      can[i]=0;
  	}
  	
  	// �������� �� ������ �������� ���� �� ��������� �� ��������
  	for ( p=0;p<n;p++)//��������� ������ � ����������
   {
	  for( i=total;i>=0;i--)//��������� �������� ����� ������� ������
       {
	    	if (can[i]==1)
        	{
			 can[i+gifts[p]]=1;
        	}
       }
    }
    //���������� �� ������ ���� �� ��������, ����� �� ������ ����� �� �������

   i=total/2;// ��� ���� �������� ������ � ����������
   while (i>1&&can[i]!=1)//��� �� ���������� �� �������� � �������� ����� �� � 1��, 
                        //��������� �� �� ��������� ������ ������ �������� ���������� � ������ 
                        //"i" �� � ������� ��- ����� �� 1
   {
   		i--;
   }
 
   printf("\n%d - %d", i, total-i);
   return 0;
}
