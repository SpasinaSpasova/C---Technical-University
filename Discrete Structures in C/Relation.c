#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
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
	printf("\n");	
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

//...............................
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

unsigned FindElementRel(Relation * relation, Pair pair)
{
	int i;
	for ( i = 0; i < relation->length; i++)
	{
        if(relation->pairs[i].x==pair.x
		&& relation->pairs[i].y==pair.y)
        {

            return 1;
	    }
    }
    return 0;
}


Relation * intersectionRel(Relation * A, Relation * B)
{

	Relation * s = (Relation*)malloc(sizeof(Relation));
    s->pairs = NULL;
    s->length = 0;
	
   	int i;
	for ( i = 0; i < A->length; i++)
	{
		if (FindElementRel(B,A->pairs[i]))
		{
		    s->length++;
		    
		 	s->pairs=(Pair*)realloc(s->pairs,sizeof(Pair)*s->length);
		 	s->pairs[s->length-1]=A->pairs[i];
		}
	}
	return s;
}
Relation * Union(Relation * A, Relation * B)
{
	unsigned size=A->length+B->length-intersectionRel(A,B)->length;
	Relation *s = (Relation*)malloc(sizeof(Relation));
	s->pairs=(Pair*)malloc(sizeof (Pair)*size);
    s->length=size;
	int i,j;
	for ( i = 0; i < A->length; i++)
	{
		s->pairs[i]=A->pairs[i];
	}

	for ( j= 0; j < B->length; j++)
	{
		if (!FindElementRel(A,B->pairs[j]))
		{
			s->pairs[i]=B->pairs[j];
			i++;
		}
		
	}
	return s;
}
Relation * differenceRel(Relation * A, Relation * B)
{
	int i,j=0;
	
	unsigned size=A->length-intersectionRel(A,B)->length;
	
	Relation *s = (Relation*)malloc(sizeof(Relation));
	s->pairs=(Pair*)malloc(sizeof (Pair)*size);
    s->length=size;
   
	for ( i = 0; i < A->length; i++)
	{
		if (!FindElementRel(B,A->pairs[i]))
		{
		
			s->pairs[j]=A->pairs[i];
			j++;
		}
	}
	return s;
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
void isEqual(Relation *rel1,Relation *rel2)
{

	int i;
	bool check;
 	for(i=0;i<rel1->length;i++)
	{
	   if(rel1->pairs[i].x==rel2->pairs[i].x
	   &&rel1->pairs[i].y==rel2->pairs[i].y)
	   {
	   	check=true;
	   }
	   else
	   {
	   	check=false;
	   }

	}
	printf("%s", check ? "true" : "false");
}
int main()
{
	srand((unsigned) time(NULL));

	Relation *rel1,*rel2,*leftSide,*rightSide1,*rightSide2,*rightSide;
	

    Set *A=CreateSet(3,100,90);
    Set *B = CreateSet(3,100,90);
     Set *C=CreateSet(3,100,90);
    Set *D = CreateSet(3,100,90);
    printf("A SET: ");
    PrintSet(A);
    printf("B SET: ");
    PrintSet(B);
    printf("C SET: ");
    PrintSet(C);
    printf("D SET: ");
    PrintSet(D);
    
   
   leftSide=differenceRel(cartesian_product(A,B),cartesian_product(C,D));
   rightSide1=cartesian_product(Difference(A,C),B);
   rightSide2=cartesian_product(A,Difference(B,D));
   rightSide=Union(rightSide1,rightSide2);
   
   print_cartesian_product(leftSide);
  print_cartesian_product(rightSide);
 
   isEqual(leftSide,rightSide);
}

