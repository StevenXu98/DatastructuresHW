#include <stdio.h>

typedef struct Snode
{
	int data;
	struct Snode next;
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


int main()
{
	Plist phead_h;
	Plist phead_nh;

	int judge = 1;
	char oper;

	scanf("%d", &judge);
	if(judge){
		while ((oper=getchar()) != '\n'){
			switch(oper){
				case i: ListInit_hp(phead_h);break;
				case l: ListLength_hp(phead_h);break;
				case g: ListGet_hp(phead_h);break;
			}//switch
		}//while
	}else{
		while ((oper=getchar()) != '\n'){
			switch(oper){
				case i: ListInit_hp(phead_h);break;
				case l: ListLength_hp(phead_h);break;
				case g: ListGet_hp(phead_h);break;
			}//switch
		}//while
	}else
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
		L = L->list;
	}
	return L;

}

Plist ListLocate_nhp(Plist L, int data)
{
	while (L && (L->data != data)){
		L = L->list;
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
	Plist pre;
	while(pre && (pre->next->data != data))
		pre = pre->next;

	temp = pre->next;
	if(temp == NULL){
		printf("no found\n");
		return L;
	}else{
		pre-next = pre->next->next;
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