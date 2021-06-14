#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
 unsigned * array;
 unsigned length;
}Set;

unsigned * Random_Generator(unsigned number_of_blocks)
{
	unsigned *array = (unsigned*)malloc(sizeof(unsigned)* number_of_blocks);
	unsigned r;
	int i,j;
	for(i=0;i<number_of_blocks;)
	{
		r=90+rand() % (100-90)+ 1;
		for(j=0;j<i;j++)
		{
			if(array[j]==r)
			{
				break;
			}
			
		}
		if(i==j)
		{
			array[i]=r;
			i++;
		}
		
	}
	
	return array;
}

Set* CreateSet(unsigned number_of_elements)
{
	Set *s=(Set*)malloc(sizeof(Set));
	
	s->length=number_of_elements;
	
	s->array=Random_Generator(number_of_elements);
	return s;
}

void PrintSet(Set *set)
{
	int i;

	for(i=0;i<set->length;i++)
	{
		
		printf("%u ",set->array[i]);
	}	
	printf("\n");
}

unsigned Find_Element(Set * set, unsigned element)
{
	int i;
	for ( i = 0; i < set->length; i++)
	{
        if(set->array[i]==element)
        {

            return 1;
	    }
    }
    return 0;
}

Set * Intersection(Set * A, Set * B)
{

	Set * s = (Set*)malloc(sizeof(Set));
    s->array = NULL;
    s->length = 0;
	
   	int i;
	for ( i = 0; i < A->length; i++)
	{
		if (Find_Element(B,A->array[i]))
		{
		    s->length++;
		    
		 	s->array=(unsigned*)realloc(s->array,sizeof(unsigned)*s->length);
		 	s->array[s->length-1]=A->array[i];
		}
	}
	return s;
}

Set * Union(Set * A, Set * B)
{
	unsigned size=A->length+B->length-Intersection(A,B)->length;
	Set *s = (Set*)malloc(sizeof(Set));
	s->array=(unsigned*)malloc(sizeof (unsigned)*size);
    s->length=size;
	int i,j;
	for ( i = 0; i < A->length; i++)
	{
		s->array[i]=A->array[i];
	}

	for ( j= 0; j < B->length; j++)
	{
		if (!Find_Element(A,B->array[j]))
		{
			s->array[i]=B->array[j];
			i++;
		}
		
	}
	return s;
}

Set * Difference(Set * A, Set * B)
{
	int i,j=0;
	
	unsigned size=A->length-Intersection(A,B)->length;
	
	Set *s = (Set*)malloc(sizeof(Set));
	s->array=(unsigned*)malloc(sizeof (unsigned)*size);
    s->length=size;
   
	for ( i = 0; i < A->length; i++)
	{
		if (!Find_Element(B,A->array[i]))
		{
		
			s->array[j]=A->array[i];
			j++;
		}
	}
	return s;
}

Set * SymmetricDifference(Set * A, Set * B)
{
	int i,j;
	Set *firstDifference=Difference(A,B);
	Set *secondDifference=Difference(B,A);
	
	unsigned size=firstDifference->length+secondDifference->length;
	Set *s = (Set*)malloc(sizeof(Set));
	s->array=(unsigned*)malloc(sizeof (unsigned)*size);
    s->length=size;
    
	s=Union(firstDifference,secondDifference);
    
    return s;
}
int main(void)
{
	
	srand((unsigned) time(NULL));

    Set *X=CreateSet(7);
    Set *Y = CreateSet(5);
    printf("FIRST SET: ");
    PrintSet(X);
    printf("SECOND SET: ");
    PrintSet(Y);
    
    
    Set *Z=Intersection(X,Y);
    printf("INTERSECTION SET: ");
    PrintSet(Z);
    
    Set *C=Union(X,Y);
    printf("UNION SET: ");
    PrintSet(C);
    
    Set *D=Difference(X,Y);
    printf("DIFFERENCE SET: ");
    PrintSet(D);
    
    Set *J=SymmetricDifference(X,Y);
    printf("SYMMETRIC DIFFERENCE SET: ");
    PrintSet(J);
    
    return 0;
}



