#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int fNum;
	char name[20];
	float grade;
	
}Student;

int FindMaxGrade(Student *student,int n)
{
	int i,maxIndex=0;
	
	for(i=0;i<n;i++)
	{
		
		if(student[i].grade>student[maxIndex].grade)
		{
			maxIndex=i;
		}
	
	}
	
	return maxIndex;
}

void PrintMax(Student *student,int n)
{
	int res=0;
	//извикваме функцията за намиране на максималната оценка
	res=FindMaxGrade(student,n);
	
	printf("Faculty number: %d\n",student[res].fNum);
	
	printf("Student name: %s\n",student[res].name);
	
	printf("Average grade: %.2f\n", student[res].grade);
	
}

int main()
{
	Student *st;
	int n,i;

	
	printf("Please, enter the size of the Array: ");
	scanf("%d",&n);
	//динамично заделяне на памет
	st=(Student*)malloc(n*sizeof(Student));
	
	//пълним масива от структури
	for(i=0;i<n;i++)
	{
		printf("Enter detail of student #%d\n", (i + 1));
		 
		printf("Enter faculty number: ");
		scanf("%d",&st[i].fNum);
		
		printf("Enter student name: ");
		scanf("%s",st[i].name);
		
		printf("Enter average grade: ");
		scanf("%f",&st[i].grade);
	}
	//извикваме функцията за принтиране
   PrintMax(st,n);
   
   system("pause");
   free(st);

}
