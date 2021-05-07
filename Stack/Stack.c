#include <stdio.h>
#include <stdlib.h>
using namespace std;
//--------------------------------------------------------
struct ITEM {
	int data;
	struct ITEM* next;
};
typedef struct ITEM ELEMENT;
//------------- -------------------------------------------
int push(ELEMENT **ppSt, int *pD){
	ELEMENT *p_new;
	p_new = (ELEMENT *)malloc(sizeof(ELEMENT));
	if (p_new == NULL)
		return 0;
	p_new->data = *pD;
	p_new->next = *ppSt;
	*ppSt = p_new;
	return 1;
}
//--------------------------------------------------------
int pop(ELEMENT **ppSt, int *pD){
	if (*ppSt==NULL)
		return 0;
	ELEMENT *old_element;
	old_element = *ppSt;
	*pD = (*ppSt)->data;
	*ppSt = (*ppSt)->next;
	free(old_element);
	return 1;
}
//--------------------------------------------------------
int main(int argc, char* argv[])
{
	ELEMENT *pSt;				
 	pSt = NULL;					
	int i, data;
	for (i = 0; i<10; i++)
	{
		data = i*i;
		if(	push(&pSt, &data)==0)	
			break;
	}

	
	while (pop(&pSt, &data)){			
		printf("%d\t",data);
	}
	system("pause");
	return 0;
}
