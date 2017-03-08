#include <stdio.h>
#include <stdlib.h>

typedef struct Snode
{
	int data;
	struct Snode *next;
} Snode, *Plist;

void ListInit_hp(Plist L);
void ListInit_nhp(Plist L);

int ListLength_hp(Plist L);
int ListLength_nhp(Plist L);

Plist ListGet_hp(Plist L ,int n);
Plist ListGet_nhp(Plist L ,int n);

Plist ListLocate_hp(Plist L, int data);
Plist ListLocate_nhp(Plist L, int data);

Plist ListInsert_hp(Plist L, Plist p, int data);
Plist ListInsert_nhp(Plist L, Plist p, int data);

Plist ListDelete_hp(Plist L, int data);
Plist ListDelete_nhp(Plist L, int data);

Plist ListHCreate_hp(Plist L, int* d);
Plist ListHCreate_nhp(Plist L, int* d);

void ListMerge(Plist la, Plist lb, Plist lc);

void ListPrint_h(Plist L);
void ListPrint_nh(Plist L);


int main()
{
	Plist phead_h;
	Plist phead_nh;

	Plist phead2_h;
	Plist result_h;

	Plist pget;

	int judge = 1;
	char oper;

	int input;


	int data[5] = { 1, 3, 5, 7, 9};
	int data2[5] = { 0, 2, 4, 6, 8};

	printf("please enter 1:with headnode; 0:without headnode :");
	scanf("%d", &judge);
	fflush(stdin);
	if(judge){
		while ((oper=getchar()) != '\n'){
			switch(oper){
				case 'i': ListInit_hp(phead_h);break;
				case 'l': ListLength_hp(phead_h);break;
				case 'g': printf("please input the number you want to get:");
						scanf("%d", &input);pget = ListGet_hp(phead_h, input);break;
				case 'L': printf("please input the data you want to find:");
						scanf("%d", &input);ListLocate_hp(phead_h, input);break;
				case 'I': printf("please input the data you want to insert:");scanf("%d", &input);
						ListInsert_hp(phead_h, pget, input);break;
				case 'd': printf("please input the data you want to delete:");
						scanf("%d", &input);ListDelete_hp(phead_h, input);break;
				case 'c': ListHCreate_hp(phead_h, data);break;
				case 'm': ListMerge(phead_h, phead2_h, result_h);break;
				case 'p': ListPrint_h(phead_h);break;
				case 'P': ListPrint_h(result_h);break;
				default : break;
			}//switch
			fflush(stdin);
		}//while
	}else{
		while ((oper=getchar()) != '\n'){
			switch(oper){
				case 'i': ListInit_hp(phead_nh);break;
				case 'l': ListLength_hp(phead_nh);break;
				case 'g': printf("please input the number you want to get:");
						scanf("%d", &input);pget = ListGet_nhp(phead_nh, input);break;
				case 'L': printf("please input the data you want to find:");
						scanf("%d", &input);ListLocate_nhp(phead_nh, input);break;
				case 'I': printf("please input the data you want to find:");scanf("%d", &input);
						ListInsert_nhp(phead_nh, pget, input);break;
				case 'd': printf("please input the data you want to delete:");
						scanf("%d", &input);ListDelete_nhp(phead_nh, input);break;
				case 'c': ListHCreate_nhp(phead_nh, data);break;
				case 'p': ListPrint_nh(phead_nh);break;
				default : break;					
			}//switch
			fflush(stdin);
		}//while
	}//else
}//main


void ListInit_hp(Plist L)
{
	L = (Snode *)malloc(sizeof(Snode));
	if(L == NULL){
		printf("malloc fail");
		exit(0);
	}
	L->next = NULL;	
}

void ListInit_nhp(Plist L)
{
	L->next = NULL;
}

int ListLength_hp(Plist L)
{
	int length = 0;
	L = L->next;
	while(L->next != NULL){
		L = L->next;
		length++;
	}
	return length;
}


int ListLength_nhp(Plist L)
{
	int length = 0;
	while(L->next != NULL){
		L = L-> next;
		length++;
	}
	return length;
}

Plist ListGet_hp(Plist L ,int n)
{
	L = L->next;
	int i = 1;
	while((L != NULL)&&(i < n)){
		L = L->next;
		i++;
	}
	return L;
}

Plist ListGet_nhp(Plist L ,int n)
{
	int i = 1;
	while((L != NULL)&&(i < n)){
		L = L->next;
		i++;
	}
	return L;
}

Plist ListLocate_hp(Plist L, int data)
{
	L = L->next;
	while (L && (L->data != data)){
		L = L->next;
	}
	return L;

}

Plist ListLocate_nhp(Plist L, int data)
{
	while (L && (L->data != data)){
		L = L->next;
	}
	return L;
}

Plist ListInsert_hp(Plist L, Plist p, int data)
{
	Plist q ,pre;
	q = (Snode*)malloc(sizeof(Snode));
	if(q = NULL){
		printf("malloc fail");
		exit(0);
	}
	q->data = data;

	pre = L;

	while(pre && (pre->next != p)){
		pre = pre->next;
	}

	q->next = pre->next;
	pre->next = q;

	return L;
}

Plist ListInsert_nhp(Plist L, Plist p, int data)
{
	Plist q, pre, *pL;
	pL = &L; 
	q = (Snode*)malloc(sizeof(Snode));
	if(q = NULL){
		printf("malloc fail");
		exit(0);
	}
	q->data = data;

	if(p == L){
		q->next = L;
		*pL = q;
		return L;
	}

	pre = L;
	while(pre && (pre->next != p)){
		pre = pre->next;
	}

	q->next = pre->next;
	pre->next = q;

	return L;
}

Plist ListDelete_hp(Plist L, int data)
{
	Plist pre, temp;
	while(pre && (pre->next->data != data))
		pre = pre->next;

	temp = pre->next;
	if(temp == NULL){
		printf("no found\n");
		return L;
	}else{
		pre->next = pre->next->next;
	}

	free(temp);

	return L;

}

Plist ListDelete_nhp(Plist L, int data)
{
	Plist pre, temp;
	Plist *pL;
	pL = &L;

	while(pre && (pre->next->data != data))
		pre = pre->next;

	temp = pre->next;

	if(temp == NULL){
		printf("no found\n");
		return L;
	}else{
		if(temp == L){
			*pL = temp->next;
			return L;
		}else{
			pre->next = pre->next->next;
		}
	}
	free(temp);

	return L;
}

Plist ListHCreate_hp(Plist L, int d[5])
{
	L = (Snode *)malloc(sizeof(Snode));
	if(L == NULL){
		printf("malloc fail");
		exit(0);		
	}
	L->next = NULL;

	for(int i = 0; i < 5; i++){
		Plist p;
		p = (Snode *)malloc(sizeof(Snode));
		if(p == NULL){
			printf("malloc fail");
			exit(0);
		}//if
		p->data = d[i];
		p->next = L->next;
		L->next = p;
	}//if
}

Plist ListHCreate_nhp(Plist L, int d[5])
{
	L = (Snode *)malloc(sizeof(Snode));
	L->data = d[0];
	L->next = NULL;

	for(int i = 0; i < 5; i++){
		Plist p;
		p = (Snode *)malloc(sizeof(Snode));
		if(p == NULL){
			printf("malloc fail");
			exit(0);
		}//if
		p->data = d[i];
		p->next = L->next;
		L->next = p;
	}//if
}

void ListMerge(Plist la, Plist lb, Plist lc)
{
	Plist pa, pb, pc;
	pa = la->next;
	pb = lb->next;
	lc = la;
	pc = lc;

	while((pa!= NULL)&&(pb!= NULL)){
		if((pa->data <= pb->data)){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}//else
	}//if
	if(pa != NULL) pc = pa->next;
	else pc = pb->next;

	free(pb);
}

void ListPrint_h(Plist L)
{
	if(L = NULL){
		printf("no found\n");
		return ;
	}
	while(L->next != NULL){
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

void ListPrint_nh(Plist L)
{
	L = L->next;
	if(L = NULL){
		printf("no found\n");
		return ;
	}
	while(L->next != NULL){
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
