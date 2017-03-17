#include <stdio.h>
#include <stdlib.h>
#define m 5

typedef struct
{
	int data[m];
	int front,count;	
}qnode;



int IsEmpty(qnode q)
{
	if(q.count == 0) return 1;
	else return 0;
}

void DoEmpty(qnode q)
{
	q.front = 0;
}

void InQueue(qnode *q)
{
	int input;
	if(q->count == m){
		printf("queue is full\n");
		return ;
	}
	printf("input the number: \n");
	scanf("%d", &input);
	fflush(stdin);
	q->data[(q->front+q->count) % m] = input;
	q->count++;
//	q->front++;
}

int OutQueue(qnode *q)
{
	int output;
	if(q->count == 0){
		printf("queue is empty\n");
		exit(0);
	}
	output = q->data[q->front];
	q->front = (q->front + 1) % m;

	return output;
}

int OutHead(qnode q)
{
	int output;
	if(q.count == 0){
		printf("queue is empty\n");
		exit(0);
	}
	output = q.data[q.front];
	return output;
}



int main()
{
	qnode q;
	q.front = 0;
	q.count = 0;
	char c;
	while((c = getchar()) != '\n'){
		switch(c){
			case 'I': InQueue(&q);break;
			case 'i': IsEmpty(q);break;
			case 'h': printf("%d",OutHead(q));break;
			case 'o': printf("%d",OutQueue(&q));break;
			case 'e': DoEmpty(q);break;
			default : break;
		}
		fflush(stdin);
	}
	return 0;
}
