#include <stdio.h>
#include <stdlib.h>

void Pyramid(int rows)
{
	int i=0,j=0,numOfWhiteSpaces=0;
	
	for ( i = rows; i >= 1; i--)
    {
        //���������� i*2 ��������� � �������� �� ����� ��� ���
        numOfWhiteSpaces=i*2;
        printf("%*s", numOfWhiteSpaces," ");
      
        //��� ���� � ��- ����� �� 10, ��� �������� i-10 ��������� 
		//��� ������ ��������� �� �������� �� ���� �� ����������� �� ���������� ������� �� ����������
		for(j=i-10;j>0;j--)
		{	
			printf(" ");	
		}
     
        //���������� j ������ j ���������� �� ���� �� i �� rows, �.� ������ ���� �� ����������
        for ( j = i; j <= rows; j++)          
        {
       		printf("%d ",j); 
        }
 
        //���������� j ������ j ���������� �� ���� �� rows-1 �� i,�.� ������� ���� �� ����������     
        for ( j = rows-1; j >= i; j--)
        {               
            printf("%d ",j);            
        }
             
        printf("\n");
    }
}
int main()
{
	int numOfRows;
	
	printf("Please enter how many rows your pyramid will be: ");
	scanf("%d",&numOfRows);
	
	Pyramid(numOfRows);
}
  
