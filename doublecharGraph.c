#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 48
 
typedef struct node{
	int adjvex;
	struct node *nextarc;
	int info;
}ENode;

typedef struct vnode{
	int data;
	ENode *fistarc;
}VNode;

typedef struct{
	VNode adjlist[MAXNUM];
	int n, e;
}TGraph;

typedef struct{
	char left,right;	
}doublechar;

int getdoublechar(doublechar *C , int *a)
{
	doublechar temp;
	int i = 0, j,flag;
	while(1){
		fflush(stdin);
		temp.left = getchar();
		for(j = 65; j <= 90; j++)
			if(temp.left == j || temp.left == j+32) a[j]++;
		fflush(stdin);
		temp.right = getchar();
		for(j = 65; j <= 90; j++)
			if(temp.right == j || temp.left == j+32) a[j]++;

		if(temp.left == '#' || temp.right == '#'){
			flag = 0;
			return i;
		}else{
			C[i].left = temp.left;
			C[i].right = temp.right;
			i++;
		}
	}
}


void CreatTGraph(TGraph *G, int *a, doublechar *C,int e)
{
	int i = 0, j, k, r, n;
	ENode *S;
	G->n = 0;
	for(r = 0; r < 200; r++){
		if(a[r] != 0){
			(G->n)++;
			G->adjlist[i].data = r;
			G->adjlist[i].fistarc = NULL;
		}
	}

//	for(i = 0; i < G->n; i++){
//		G->adjlist[i].data = ;
//		G->adjlist[i].fistarc = NULL;
//	}
	G->e = e;
	for(k = 0; k < G->e; k++){
//		scanf("%d%d", &i, &j);
		i = (int)C[n].left;
		j = (int)C[n].right;

		S = (ENode*)malloc(sizeof(ENode));
		S->adjvex = j;
		S->nextarc = G->adjlist[i].fistarc;
		G->adjlist[i].fistarc = S;
	}
}

int main()
{
	TGraph *G = (TGraph*)malloc(sizeof(TGraph));
	doublechar C[100];
	int i ;
	int array[200] = {0};
	i = getdoublechar(C, array);
	CreatTGraph(G, array, C, i/2);

	return 0;
}