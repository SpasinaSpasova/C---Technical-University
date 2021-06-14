#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
 unsigned * array;
 unsigned length;
} Set;
typedef struct
{
 unsigned x;
 unsigned y;
} Pair;
typedef struct 
{
 Pair * pairs;
 unsigned length;
} Relation;

unsigned * Random_Generator(unsigned number_of_blocks,int max,int min)
{
	unsigned *array = (unsigned*)malloc(sizeof(unsigned)* number_of_blocks);
	unsigned r;
	int i,j;
	for(i=0;i<number_of_blocks;)
	{
		r=min+rand() % (max-min)+ 1;
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

Set* CreateSet(unsigned number_of_elements,int max,int min)
{
	Set *s=(Set*)malloc(sizeof(Set));
	
	s->length=number_of_elements;
	
	s->array=Random_Generator(number_of_elements,max,min);
	return s;
}

Relation* cartesian_product(Set * A, Set * B)
{
	int i,j,countRelation=0;
	int size=A->length*B->length;
    Relation *r=(Relation*)malloc(sizeof(Relation));
    r->pairs = (Pair*)malloc(sizeof(Pair)*size);
	r->length=size;
	
	for(i=0;i<A->length;i++)
	{
			for(j=0;j<B->length;j++)
			{
				r->pairs[countRelation].x=A->array[i];
				r->pairs[countRelation].y=B->array[j];
				countRelation++;
			}
	}
	
	return r;
}
void print_cartesian_product(Relation * r)
{
	int i;
	
	for(i=0;i<r->length;i++)
	{
		printf("(%c,%c) ",(char)r->pairs[i].x,(char)r->pairs[i].y);
	}
		
}


void PrintSet(Set *set)
{
	int i;

	for(i=0;i<set->length;i++)
	{
		
		printf("%c ",(char)set->array[i]);
	}	
	printf("\n");
}


int main()
{
	srand((unsigned) time(NULL));

	Relation *result;

    Set *X=CreateSet(3,90,65);
    Set *Y = CreateSet(3,122,97);
    printf("FIRST SET: ");
    PrintSet(X);
    printf("SECOND SET: ");
    PrintSet(Y);
    
   result= cartesian_product(X,Y);
   print_cartesian_product(result);
}

