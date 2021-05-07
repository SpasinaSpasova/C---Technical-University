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
	Person p[3];
	int i;
	FILE *fp;
	for(i=0;i<3;i++)
	{
		printf("First name: ");scanf("%s",p[i].name.FName);
		printf("Second name: ");scanf("%s",p[i].name.SName);
		printf("Last name: ");scanf("%s",p[i].name.LName);
		printf("EGN: ");scanf("%s",p[i].EGN);
		printf("Account N: ");scanf("%s",p[i].AccountNr);
		printf("Account sum: ");scanf("%f",&p[i].AccountSum);
		
	}
	for(i=0;i<3;i++)
	{
		printf("%s\t", p[i].name.FName);
		printf("%s\t", p[i].name.SName);
		printf("%s\t", p[i].name.LName);
		printf("%s\t", p[i].EGN);
		printf("%s\t", p[i].AccountNr);
		printf("%f\n", p[i].AccountSum);
	}
	
	fp=fopen("account.txt","w");
	fprintf(fp,"%d\n",3);
	for(i=0;i<3;i++)
	{
		fprintf(fp,"%s\n",p[i].name.FName);
		fprintf(fp,"%s\n",p[i].name.SName);
		fprintf(fp,"%s\n",p[i].name.LName);
		fprintf(fp,"%s\n",p[i].EGN);
		fprintf(fp,"%s\n",p[i].AccountNr);
		fprintf(fp,"%f\n",p[i].AccountSum);
	}
		
	fclose(fp);
	free(fp);
	return 0;
}
