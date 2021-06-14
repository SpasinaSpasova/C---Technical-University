#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
 char key;
 struct tree *left;
 struct tree *right;
};

//INSERT

void InsertNode (char x, struct tree ** v)
{
	if (*v != NULL)
	{
		if (x < (*v)->key)
		{
			InsertNode (x, &(*v)->left);
		}
		else
		{
				if (x > (*v)->key)
				{
					InsertNode (x, &(*v)->right);
				}
		}
	}
	else
	{
		(*v) = (struct tree *) malloc (sizeof (struct tree));
		(*v)->key = x;
		(*v)->left = NULL;
		(*v)->right = NULL;
	}
}



//DELETE
void DeleteNode (char x, struct tree ** v)
{
	if (*v == NULL)
	{
		printf( "\n Element miss");
	}
	else
	{
		if (x < (*v)->key)
		{
			DeleteNode (x, &(*v)->left);
		}
		else
		{
			if (x > (*v)->key)
			{
				DeleteNode (x, &(*v)->right);
			}
			else
			{
				if ( (*v)->left != NULL && (*v)->right != NULL)
				{
					struct tree * h = (*v)->right;
					while ( h->left != NULL)
					{
						h = h->left;
					}
					(*v)->key = h->key;
					DeleteNode ( (*v)->key, &(*v)->right);
				}
				else
				{
					struct tree * tmp = *v;
					if ((*v)->left)
					{
						(*v) = (*v)->left;
					}
					else
					{
						(*v) = (*v)->right;
					}
					free (tmp);
				}
			}
		}
	}
}



//SEARCH
struct tree* SearchTree (char x, struct tree *v)
{
	if (v != NULL)
	{
		if (x < v->key)
		{
			SearchTree (x, v->left);
		}
		else
		{
			if (x > v->key)
			{
				SearchTree (x, v->right);
			}
		    else
			{
				return v;
			} 
		
		}
	}
	else
	{
		return NULL;
	}
}
int main()
{
	struct tree** example;
	struct tree* searched;
	searched=(struct tree *) malloc (sizeof (struct tree));
	InsertNode('x',example);
	searched=SearchTree('x',example);
	printf("%c",searched);
}
