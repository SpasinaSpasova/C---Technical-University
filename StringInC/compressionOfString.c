#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int IsDelimiter(char c)
{
	if(c==' '||c=='.'||c=='?'||c=='!'||c=='\t'||c==',')
	{
		return 1;
	}
	return 0;
}
int main()
{
	int i=0;
	int currPosition=0;
	int dCount=0;
	char *str="The quick red fox jumps,    over the dog!";

	while(str[i]!='\0')
	{
		if(IsDelimiter(str[i]))
		{
			i++;
			dCount++;
			for(;IsDelimiter(str[i]);i++){dCount++;}
		}
		else
		{
			str[currPosition]=str[i];
			i++;
			currPosition++;
		}
	}
	str[currPosition]='\0';
	printf("%s",str);
	return 0;
}
