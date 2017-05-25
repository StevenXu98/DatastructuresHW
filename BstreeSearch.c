#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}Tnode, *Pnode;

Pnode bst_search(Pnode p, int e)
{
	while(p){
		if(e == p->data) return p;
		else if(e < p->data) p = p->lchild;
		else p = p->rchild;
	}
	printf("no found");
	return p;
}

Pnode bst_search2(Pnode p, int e)
{
	Pnode hp;
	while(p){
		if(e < p->data){
			hp = p;
			p = p->lchild;
		}else{
			hp = p;
			p = p->rchild;
		}
	}
	return hp;
}



void bst_insert(Pnode *pp, int e)
{
	Pnode temp, q;
	temp = (Pnode)malloc(sizeof(Tnode));
	temp->data = e;
	temp->lchild = NULL;
	temp->rchild = NULL;
	if(!(*pp)){
		*pp = temp;
		return ;
	}
	q =  bst_search2(*pp, e);
	if(e < q->data)
		q->lchild = temp;
	else
		q->rchild = temp;
	return ;
}


Pnode bst_create(int *a, int n)
{
	int i;
	Pnode p = NULL;
	for(i = 0; i < n; ++i){
		bst_insert(&p, a[i]);
	}
}




int main()
{
	int a[5] = {1, 2, 3, 4, 5};

	bst_create(a, 5);



	return 0;
}