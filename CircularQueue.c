#include <stido.h>
#include <stdlib.h>

typedef struct $
{
	int front,rear,len;
	int *pdata;	
}TQue, *PQue; 

PQue QueInit(int);


int main(int argc, char const *argv[])
{
	
	return 0;
}

PQue QueInit(int n)
{
	PQue pque;
	int *p;
	Pque = (PQue)malloc(sizeof(TQue));
	P = (int *)malloc(n*sizeof(int));
	if(p == NULL) {puts("malloc fail!"); return;}
	pque->pdata = p;
	pque->front = 0;
	pque->rear = 0;
	pque->len = n;

	return pque;
}