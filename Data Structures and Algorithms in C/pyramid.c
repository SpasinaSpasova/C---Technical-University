#include <stdio.h>
#include <stdlib.h>

void Pyramid(int rows)
{
	int i=0,j=0,numOfWhiteSpaces=0;
	
	for ( i = rows; i >= 1; i--)
    {
        //Принтираме i*2 интервала в началото на всеки нов ред
        numOfWhiteSpaces=i*2;
        printf("%*s", numOfWhiteSpaces," ");
      
        //ако реда е по- голям от 10, ние добавяме i-10 интервала 
		//към всички интервали от началото на реда до отпечатване на конкретния елемент на пирамидата
		for(j=i-10;j>0;j--)
		{	
			printf(" ");	
		}
     
        //Принтираме j където j стойността ще бъде от i до rows, т.е лявата част на пирамидата
        for ( j = i; j <= rows; j++)          
        {
       		printf("%d ",j); 
        }
 
        //Принтираме j където j стойността ще бъде от rows-1 до i,т.е дясната част на пирамидата     
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
  
