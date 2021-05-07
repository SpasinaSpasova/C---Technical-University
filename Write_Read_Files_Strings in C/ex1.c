#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int fakNo;
	char name[20];
	char fam[20];
	float avrgGrade;
}TStudents;
void WriteStudents(TStudents *Students, int num,char *fileName)
{
	int i;
	FILE *fp;
	fp=fopen(fileName,"w");
	fprintf(fp,"%d",num);
	for(i=0;i<num;i++)
	{
		fprintf(fp,"%d, %s, %s, %f",
		Students[i].fakNo,
		Students[i].name,
		Students[i].fam,
		Students[i].avrgGrade);
	}
	fclose(fp);
}
int main()
{
	int i;
	TStudents Bel[2];
	for(i=0;i<2;i++)
	{
		printf("\nFakNo: ");
		scanf("%d",&Bel[i].fakNo);
		
		printf("\Name: ");
		scanf("%s",&Bel[i].name);
		
		printf("\nFam: ");
		scanf("%s",&Bel[i].fam);
		
		printf("\nGrade: ");
		scanf("%f",&Bel[i].avrgGrade);
	}
	WriteStudents(Bel,2,"text.txt");
}
