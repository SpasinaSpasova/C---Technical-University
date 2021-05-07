#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char FName[25];
	char SName[25];
	char LName[25];
}PName;

typedef struct
{
	PName name;
	char EGN[15];
	char AccountNr[80];
	float AccountSum;
}Person;

int main()
{
	Person *p;
	FILE *fp;
	int i,r;
	fp=fopen("account.txt","r");
	fscanf(fp,"%d",&r);
	p=(Person*)malloc(r*sizeof(Person));
	
	for(i=0;i<r;i++)
	{
		fscanf(fp,"%s",p[i].name.FName);
		fscanf(fp,"%s",p[i].name.SName);
		fscanf(fp,"%s",p[i].name.LName);
		fscanf(fp,"%s",p[i].EGN);
		fscanf(fp,"%s",p[i].AccountNr);
		fscanf(fp,"%f",&p[i].AccountSum);
	}
	for(i=0;i<r;i++)
	{
		printf("%s\t", p[i].name.FName);
		printf("%s\t", p[i].name.SName);
		printf("%s\t", p[i].name.LName);
		printf("%s\t", p[i].EGN);
		printf("%s\t", p[i].AccountNr);
		printf("%f\n", p[i].AccountSum);
	}
	fclose(fp);
	free(fp);
	return 0;
}
