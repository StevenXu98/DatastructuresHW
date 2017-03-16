#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
} SNode ,*Pstack;

Pstack CreateStack(Pstack *S)
{
	*S = (Pstack)malloc(sizeof(SNode));
	(*S)->next = NULL;
}

void Push(int in,Pstack S)
{
	SNode *Tmp;
	Tmp = (SNode *)malloc(sizeof(SNode));
	Tmp->data = in;
	Tmp->next = S->next;
	S->next = Tmp;
}

int Pop(Pstack S)
{
	SNode *First;
	int out;
	First = S->next;
	if(!First){//堆栈为空
		return -1;
	}
	S->next = First->next;
	out = First->data;
	free(First);
	return out;
}


Pstack Odd,Even;



int main()
{
	int n;

	int num;
	char judge;

	CreateStack(&Odd);
	CreateStack(&Even);

	printf("input how many numbers do u want? ");
	scanf("%d", &n);
	fflush(stdin);
	srand((unsigned) time(NULL)); 

	for(; n > 0; n--){
		num = rand() % 10;
		if(num % 2 == 0) Push(num, Even);
		else Push(num, Odd);	
	}

	num = 0;

	printf("which stack do u want to print? O/E : ");	
	while((judge = getchar())!='\n'){	
		fflush(stdin);
		if(judge == 'O'){
			while(1){
				num = Pop(Odd);
				if(num == -1) break;
				printf("%d ", num);			
			}//while Odd
			printf("\n");
		}else if(judge == 'E'){
			while(1){
				num = Pop(Even);
				if(num == -1) break;
				printf("%d ", num);
			}//while Even
			printf("\n");
		}else printf("unknow stack\n");
	}


	return 0;
}