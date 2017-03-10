#include <stdio.h>
#include <stdlib.h>

#define NOFOUND do{puts("no found \n");return 0;}while(0)

typedef struct node{
	int data;
	struct node *next;
}Snode, *PList;

PList ListInit();

int main()
{
	PList phead;
	char input;

	while((input = getchar())!= '\n'){
		switch(input){
			case 'i': phead = ListInit();break;

		}
	}
}

PList ListInit()
{
	PList p;
	p = (Snode *)malloc(sizeof(Snode));
	p->next = p;
}

void ListInsert(PList L)
{
	PList p,pre;
	int c;
	p = (Snod *)malloc(sizeof(Snode));

	printf("please input the data: ");
	scanf("%d", &(p->data));

	printf("please choose the data: ");
	scanf("%d", &c);

	pre = Listlocate(PList L, c);
	if(pre == NULL) NOFOUND;

	p->next = pre->next;
	pre->next = p;
	
}
