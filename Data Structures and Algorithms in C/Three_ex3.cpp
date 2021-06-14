#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char key;
	struct node * left;
	struct node * right;
};

void readtree(struct node **p, char &x)
{
	char y, z;
    struct node * q1, *q2;
    
    if( *p == NULL )
    {
        printf( "Vyvedi korena" );
        scanf( "%c", &x );
        (*p)=(struct node *)malloc(sizeof(struct node));
        (*p)->key=x;
    }
    fflush(stdin);
    
   
    printf("\nVyvedi liav naslednik na %c: ", x);
    z = getchar();
    fflush(stdin);
    
    
    printf("\nVyvedi desen naslednik na %c: ", x);
    y = getchar();
    
   
    if (z!='0')
    {
        q1=(struct node *)malloc(sizeof(struct node));
        q1->key=z;
        (*p)->left=q1;
        readtree(&q1,z); 
    }
    else
    (*p)->left=NULL;
    
    if (y!='0')
    {
        q2=(struct node *)malloc(sizeof(struct node));
        q2->key=y;
        (*p)->right=q2;
        readtree(&q2,y); 
    }
    else
    (*p)->right=NULL;

}
void printtree(struct node *p, int delta)
{
    int i;
    if (p!=NULL)
    {
        printtree(p->left,delta+1);
        for (i=1;i<=delta; i++)
            printf("\t");
        printf("%c",p->key);
        printf("\n");
            printtree(p->right, delta+1);
		
    }
}
void inorder (struct node * v)
{
	if (v != NULL)
	{
	inorder (v->left);
	printf ("%c \t", v->key);
	inorder (v->right);
	}
}
int result(struct node * p)
{
	if (p->key > '0' && p->key <= '9')
	{
		return (p->key - '0');
	}
	else if (p->key == '*')
	{
		return result(p->left) * result(p->right);
	}
	else if (p->key == '+')
	{
		return result(p->left) + result(p->right);
	}
	else if (p->key == '-')
	{
		return result(p->left) - result(p->right);	
	}
	
}

int main()
{
	struct node *n = NULL;
	char c;
	readtree(&n, c);
	printtree(n, 0);
	inorder(n);
	printf("=%d",result(n));

}
