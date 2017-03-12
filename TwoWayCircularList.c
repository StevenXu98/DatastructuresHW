#include <stdio.h>
#include <stdlib.h>

#define NOFOUND do{puts("no found \n");return ;}while(0)

typedef struct node
{
	struct node *pre;
	int data;
	struct node *next;
}Snode, *Plist;

Plist ListInit();
void ListCreate(Plist, int *);
Plist ListLocate(Plist, int);
void ListInsert(Plist);
void ListDelete(Plist);
void ListClear(Plist);
void ListPrint(Plist);

int main(int argc, char const *argv[])
{
	Plist phead;
	char input;
	int array[5]= { 1, 3, 5, 7, 9,};

	while((input = getchar())!='\n'){
		switch(input){
			case 'i': phead = ListInit();break; 
			case 'c': ListCreate(phead, array);break;
			case 'I': ListInsert(phead);break;
			case 'd': ListDelete(phead);break;
			case 'C': ListClear(phead);break;
			case 'p': ListPrint(phead);break;
			default : break;
		}
		fflush(stdin);
	}
	
	return 0;
}

Plist ListInit()
{
	Plist p;
	p = (Snode *)malloc(sizeof(Snode));
	if(p == NULL) {printf("malloc fail\n");return 0;}
	p->pre = p;
	p->next = p;

	return p;
}

void ListCreate(Plist L, int *array)
{	
	Plist p;
	Plist h = L;

	for(int i = 0; i < 5; i++){
		p = (Snode *)malloc(sizeof(Snode));
		if(p == NULL) {printf("malloc fail\n");return ;}
		p->data = array[i];
		L->next = p;
		p->pre = L;
		p->next = h;
		h->pre = p;
		L = L->next;
	}

}

Plist ListLocate(Plist L,int c)
{
	Plist h = L;
	while((L->next != h)&&(L->next->data != c)){
		L = L->next;
	}
	if(L->next->data == c) return L;
	else return NULL;
		
}

void ListInsert(Plist L)
{
	Plist p,q;
	int c;
	p = (Snode *)malloc(sizeof(Snode));
	if(p == NULL) {	printf("malloc fail \n");return ;};

	printf("please input the data: ");
	scanf("%d", &(p->data));

	printf("please choose the data: ");
	scanf("%d", &c);

	q = ListLocate( L, c);
	if(q == NULL) NOFOUND;

	p->next = q->next;
	q->next = p;
	p->pre = p->next->pre;
	p->next->pre = p;

}

void ListDelete(Plist L)
{
	int d;
	Plist pre,temp;
	printf("input the data you want to delete: ");
	scanf("%d" , &d);
	pre = ListLocate( L, d);
	if(pre == NULL) NOFOUND;

	temp = pre->next;
	temp->pre->next = temp->next;
	temp->next->pre = temp->pre;
	free(temp);
	
}

void ListClear(Plist L)
{
	Plist p, q;
	p = L->next;

	while(p != L){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;	
}

void ListPrint(Plist L)
{
	Plist h = L;
	L = L->next;
	if(L==NULL) NOFOUND;
	
	while(L != h){
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
