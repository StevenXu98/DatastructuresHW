#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 6

typedef struct{
 	char vexs[MAXNUM];
 	int edges[MAXNUM][MAXNUM];
 	int n ,e;		//定点数与边数
}AdjGragh;

void CreatMGraph(AdjGragh *G)
{
	int i, j;
	scanf("%d%d", &G->n, &G->e);
	for(i = 0; i < G->n; ++i){
		fflush(stdin);
		G->vexs[i] = getchar();		
	}
	for(i = 0; i < G->n; ++i){
		for(j = 0; j < G->n; ++j){
			scanf("%d",&G->edges[i][j]);
		}
	}
}

void PrintMGraph(AdjGragh *G)
{
	int i, j;
	for(i = 0; i < G->n; ++i){
		for(j = 0; j < G->n; ++j){
			printf("%d", G->edges[i][j]);
		}
		printf("\n");	
	}
}

int GetDegeee(AdjGragh *G)
{
	int i, j, flag = 0;
	int degree = 0;
	fflush(stdin);
	char temp = getchar();
	for(i = 0; i < G->n; ++i){
		if(temp == G->vexs[i]){
			flag = 1;
			break;
		}
	}
	if(flag){
		for(j = 0; j < G->n; ++j){
			degree += G->edges[i][j];
		}
	}else{
		printf("no found");
		return -1;
	}

	return degree;
}

typedef struct node{
	int adjvex;
	struct node *nextarc;
	int info;
}ENode;

typedef struct vnode{
	int data;
	ENode *fistarc;
}VNode;

typedef struct {
	VNode adjlist[MAXNUM];
	int n, e;
}TGraph;

void CreatTGraph(TGraph *G)
{
	int i, j, k;
	ENode *S;
	scanf("%d%d",&G->n, &G->e);
	for(i = 0; i < G->n; ++i){
		fflush(stdin);
		G->adjlist[i].data = getchar();
		G->adjlist[i].fistarc = NULL;
	}
	for(k = 0; k < G->e; ++k){
		scanf("%d%d", &i, &j);
		S = (ENode*)malloc(sizeof(ENode));
		S->adjvex = j;
		S->nextarc = G->adjlist[i].fistarc;
		G->adjlist[i].fistarc = S;

		S = (ENode*)malloc(sizeof(ENode));
		S->adjvex = i;
		S->nextarc = G->adjlist[j].fistarc;
		G->adjlist[j].fistarc = S;
	}	
}

int visited[MAXNUM];

void DFS(TGraph *G, int i)
{
	ENode *p;
	printf("%c", G->adjlist[i].data);
	visited[i] = 1;
	p = G->adjlist[i].fistarc;
	while(p){
		if(!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

typedef struct
{
	int data[MAXNUM];
	int front,count;	
}Queue;

void InQueue(Queue *q,int input)
{

	if(q->count == MAXNUM){
		printf("queue is full\n");
		return ;
	}

	q->data[(q->front+q->count) % MAXNUM] = input;
	q->count++;
//	q->front++;
}
int OutQueue(Queue *q)
{
	int output;
	if(q->count == 0){
		printf("queue is empty\n");
		exit(0);
	}
	output = q->data[q->front];
	q->front = (q->front + 1) % MAXNUM;

	return output;
}

int visited_B[MAXNUM] = {0};

void BFS(TGraph *G,int k)
{
	int i;
	Queue Q;
	ENode *p;
	printf("visit: %c \n",G->adjlist[k].data);
	visited_B[k] = 1;
	InQueue(&Q , k);
	while(Q.count != 0){
		i = OutQueue(&Q);
		p = G->adjlist[i].fistarc;
		while(p){
			if(!visited[p->adjvex]){
				printf("visit: %c", p->adjvex);
				visited[p->adjvex] = 1;
				InQueue(&Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
}



int main()
{
	AdjGragh *G = (AdjGragh*)malloc(sizeof(AdjGragh));
	CreatMGraph(G);
	getchar();
	fflush(stdin);
	PrintMGraph(G);
	printf("\n%d",GetDegeee(G));

//	TGraph *G = (TGraph*)malloc(sizeof(TGraph));
//	CreatTGraph(G);
//	getchar();
//	fflush(stdin);
//	DFS(G);
//	getchar();
//	fflush(stdin);
//	BFS(G);
//	
	return 0;
}

