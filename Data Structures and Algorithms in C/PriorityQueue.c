#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//struct
struct queue
{
int rank;
char task[20];
struct queue * next;
} * head = NULL;

//print
void PrintQueue()
{
struct queue * ptr = head;
	while (ptr)
	{
	printf("Task %s, with priority %d\n", ptr->task, ptr->rank);
	ptr = ptr->next;
	}
}

//find
struct queue* FindPlace(int rank)
{
	struct queue *s,*f;
	f=head;
    s=NULL;
    
    while(f!=NULL&&f->rank<=rank)
	{
		s=f;
		f=f->next;
	}
	return s;
}

//delete
void Delete(int countToDel)
{
	int i,x=0;
	struct queue *temp; 
	
	for(i=0;i<countToDel;i++)
	{
		x = head->rank;
		temp = head;
		head = head->next;
		free (temp);
		x=0;
	}
}

//insert
int Insert(int rank,char *task)
{
	struct queue *ptr,*ptr1;
	ptr = (struct queue *)malloc(sizeof(struct queue));
	if (!ptr)
	{
		return 0;
	}
	ptr->rank = rank;
	strcpy(ptr->task,task);
 
	ptr1 = FindPlace (rank);
	if (!ptr1)
	{
		ptr->next = head;
		head = ptr;
	}
	else
	{
		ptr->next = ptr1->next;
		ptr1->next = ptr;
	}
	return 1;
}
int main()
{
	int i,numOfElements=0,countToDelete=0,currentPriority=0;
	char currentTask[20];
	struct queue * priorityQueue;
	priorityQueue = (struct queue *)malloc(sizeof(struct queue));
	
	printf("Enter count of elements: ");
	scanf("%d",&numOfElements);
	
	for(i=0;i<numOfElements;i++)
	{
		printf("Enter current task: ");
		scanf("%s",&currentTask);
		printf("Enter current priority: ");
		scanf("%d",&currentPriority);
		Insert(currentPriority,currentTask);
	}
	
	PrintQueue();
	Delete(2);
	PrintQueue();
}
