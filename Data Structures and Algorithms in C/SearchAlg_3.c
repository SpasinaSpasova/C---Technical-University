#include<stdio.h>
#include<stdlib.h>
struct list *L;
struct list
{
	int key;
	struct list *next;
}* head = NULL;

struct list * seqSearch (int x)
{

	struct list * tmp = head;
	while (tmp !=NULL)
	{
		if (tmp->key == x)
		{
			return tmp;	
		}
		else
		{
			tmp = tmp->next;
		}
	}
}
int main()
{
	
}
