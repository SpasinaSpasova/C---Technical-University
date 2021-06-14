#include<stdio.h>
#include<stdlib.h>

struct bracket
{
char symbol;
struct bracket * prev;
} * sp = NULL;

//�������� ����������
struct bracket *ptr;
//�������� �� ��.
int Push (char c)
{

	//�������� �� �����
    ptr = (struct bracket *)malloc(sizeof(struct bracket));
    //��������� �������� �� �����
	if (!ptr)
	{
	return 0;
	}
	//������� �������� �� ����� � �������� �� ������� � �����
	ptr->symbol = c;
	ptr->prev = sp;
	sp = ptr;
	return 1;
}
//���������� �� �������
int Pop (char c)
{

	char mirror;
	switch (c)
	{
	case ')' :
		mirror = '(';
		break;
	case '}' :
		mirror = '{';
		break;
	case ']' :
		mirror = '[';
		break;
	}
	//������� ���������
	if (sp && sp->symbol == mirror)
	{
	ptr = sp;
	sp = sp->prev;
	free (ptr);
	return 1;
	}
	//��������� ���������
	else
	{
		return 0;
	}

}



int main()
{
	int i,resForMemory,resForPop;

	char str[20];
	printf("Enter a string ");
	scanf("%s", &str); 
	
	for(i=0;i<20;i++)
	{
		char current=str[i];
		
		if(current=='('||current=='{'||current=='[')
		{
			resForMemory=Push(current);
			if(resForMemory==0)
			{
				printf("Memory failed\n");
				break;
			}
		}
		else if(current==')'||current=='}'||current==']')
		{
		
			resForPop=Pop(current);
			if(resForPop==0)
			{
				printf("Delete failed\n");
				break;
			}
		
		}
	}
	//����������� ���� ��������� ��� � ������ � ���������� ��������� � ���� �������
	if(sp==NULL&&resForPop==1)
	{
		printf("Balanced!");
	
	}
	else
	{
		printf("Not balanced!");
	}
}
