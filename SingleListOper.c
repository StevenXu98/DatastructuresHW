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

