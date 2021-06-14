#include <stdio.h>
#define MAXN 200

//брой върхове в графа
const unsigned n=6;

//обхождане в дълбочина с начало връх= 0
const unsigned v=1;

//матрица на съседство
const char A[MAXN][MAXN] ={
 {0,1,0,0,1,1},
 {1,0,1,0,0,0},
 {0,1,0,1,1,0},
 {0,0,1,0,1,1},
 {1,0,1,1,0,1},
 {1,0,0,1,1,0}
};

//масив за посетени върхове
char used[MAXN];

void DFS ( unsigned i )
{
 unsigned k;
 used[i] =1;
 printf("%u ", i);
 for(k=0; k<n; k++)
    if(A[i][k] && !used[k])
       DFS(k);
}

void Cycle(char graph[MAXN][MAXN], int x, int n)
{
	int i;
	used[x] = 1;
	int counter = 0;
	for (i = 0; i < n; i++) 
	{
		if (graph[x][i])
		{
			if (!used[i])
			{
			counter = 0;
			Cycle(graph, i, n);
			}
		else
		{
			counter++;
			if (counter>1)
			{
			printf("\nCycle");
			break;
			}
		}
		}
	}
}
int main (void)
{
 unsigned k;
 for(k=1; k<n; k++)
   used[k]=0;
 printf("Obhozdane ot vryh %u:  \n", v);
 DFS(v);
 Cycle(A,0,5);
 printf("\n");
 return 0;
}


