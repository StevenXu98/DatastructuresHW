#include <stdio.h>
#include <stdlib.h>

#define NOFOUND do{puts("no found \n");return ;}while(0)


typedef struct node{
	int data;
	struct node *next;
}Snode, *PList;

PList ListInit();
void ListCreate(PList, int*);
void ListInsert(PList);
void ListDelete(PList);
PList Listlocate(PList , int);
int ListLength(PList);
void ListPrint(PList);
void ListClear(PList);


int main(int argc, char const *argv[])
{
	PList phead;
	char input;
	int array[5] = { 1, 3, 5, 7, 9, };
	int n;

	while((input = getchar())!= '\n'){
		switch(input){
			case 'i': phead = ListInit();break;
			case 'c': ListCreate(phead, array);break;
			case 'I': ListInsert(phead);break;
			case 'd': ListDelete(phead);break;
			case 'l': printf("please enter the number you want to find: ");
					  scanf("%d", &n); Listlocate(phead, n);break;
			case 'L': printf("length = %d \n", ListLength(phead));break;
			case 'p': ListPrint(phead);break;
			case 'C': ListClear(phead);break;
			default : break;
		}
		fflush(stdin);
	}

	return 0;
}

PList ListInit()
{
	PList p;
	p = (Snode *)malloc(sizeof(Snode));
	if(p == NULL) {printf("malloc fail \n"); exit(0);}
	p->next = p;
	return p;
}

void ListCreate(PList L, int* array)
{
	PList p;

	for(int i = 0; i < 5; i++){	
		p = (Snode *)malloc(sizeof(Snode));
		if(p == NULL) {	printf("malloc fail \n");return ;}
		
		p->data = array[i];
		p->next = L->next;
		L->next = p;
		L = L->next;
	}
}

void ListInsert(PList L)
{
	PList p,pre;
	int c;
	p = (Snode *)malloc(sizeof(Snode));
	if(p == NULL) {	printf("malloc fail \n");return ;};

	printf("please input the data: ");
	scanf("%d", &(p->data));

	printf("please choose the data: ");
	scanf("%d", &c);

	pre = Listlocate( L, c);
	if(pre == NULL) NOFOUND;

	p->next = pre->next;
	pre->next = p;	
}

void ListDelete(PList L)
{
	int d;
	PList pre,temp;
	printf("input the data you want to delete: ");
	scanf("%d" , &d);
	pre = Listlocate( L, d);
	if(pre == NULL) NOFOUND;

	temp = pre->next;
	pre->next = pre->next->next;
	free(temp);
	
}

PList Listlocate(PList L, int c)
{
	PList h = L;
	while((L->next != h)&&(L->next->data != c)){
		L = L->next;
	}
	if(L->next->data == c) return L;
	else return NULL;
		
}

int ListLength(PList L)
{
	int length = 0;
	PList h = L;
	
	L = L->next;
	
	while(L != h){
		L = L->next;
		length++;
	}
	return length;
	
}

void ListPrint(PList L)
{
	PList h = L;
	
	L = L->next;
	
	while(L != h){
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

void ListClear(PList L)
{
	PList p, q;
	p = L->next;
	if(L==NULL) NOFOUND;

	while(p != L){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
