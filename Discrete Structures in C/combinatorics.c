#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
 unsigned * array;
 unsigned length;
} Set;
typedef struct
 {
 unsigned *v;
 unsigned k;
 unsigned n;
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
void PrintSet(Set *set)
{
	int i;

	for(i=0;i<set->length;i++)
	{
		
		printf("%c ",(char)set->array[i]);
	}	
	printf("\n");
}
Relation * pow3Set(Set * A)
{
	Relation *r=(Relation*)malloc(sizeof(Relation));
	r->k=3;
	r->n=A->length*A->length*A->length;
	r->v=(unsigned*)malloc(sizeof(unsigned)*r->n*r->k);
	int i,j,k,vCount=0;
	for(i=0;i<A->length;i++)
	{
		for(j=0;j<A->length;j++)
		{
			for(k=0;k<A->length;k++)
			{
				r->v[vCount]=A->array[i];
				vCount++;
				r->v[vCount]=A->array[j];
				vCount++;
				r->v[vCount]=A->array[k];
				vCount++;
			}
		}
	}
	
	return r;
}
Relation * Var3Set(Set * A)
{

	Relation *r=(Relation*)malloc(sizeof(Relation));

	r->k=3;
	r->n=fact(A->length)/fact(A->length-r->k);
	
	r->v=(unsigned*)malloc(sizeof(unsigned)*r->k*r->n);
	int i,j,k,vCount=0;
	for(i=0;i<A->length;i++)
	{
		for(j=0;j<A->length;j++)
		{
			for(k=0;k<A->length;k++)
			{
				if(A->array[i]!=A->array[j]&&
				A->array[i]!=A->array[k]
				&&A->array[j]!=A->array[k])
				{
					r->v[vCount]=A->array[i];
					vCount++;
					r->v[vCount]=A->array[j];
					vCount++;
					r->v[vCount]=A->array[k];
					vCount++;
				}
				
			}
		}
	}
	
	return r;
}

int fact(int n)
{
	int  fact = 1;
    int i;
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else 
	{
        for (i = 1; i <= n; ++i) 
		{
            fact *= i;
        }
       return fact;
    }

    return 0;
}
void Print(Relation *r)
{
	int i,j;
	for(i=0;i<r->n;i++) 
	{
        printf("(");
        for(j=0;j<r->k;j++) 
		{
            printf("%c",(char)r->v[i*r->k+j]);
            if(j+1!=r->k)
			{
                printf(",");
            }
        }
        printf(")");
    }
     
}
int main()
{
     Set* A=CreateSet(4,20,60);
     PrintSet(A);
     Relation* r= Var3Set(A);
     Print(r);
    
}
