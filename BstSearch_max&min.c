#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *rchild;
	struct node *lchild;
}Tnode, *Pnode;


void search_max(Pnode p, int x)
{
	while(p){
		if(p->data == x){
			while(p->rchild){
				p = p->rchild;
			}
			printf("%d ", p->data);
			return ;
		}else if(p->data > x) p = p->lchild;
		else p = p->rchild;
	}
	printf("no found");
}

void search_min(Pnode p; int x)
{
	while(p){
		if(p->data == x){
			while(p->lchild){
				p = p->lchild;
			}
			printf("%d ", p->data);
			return ;
		}else if(p->data > x) p = p->lchild;
		else p = p->rchild;
	}
	printf("no found");
}