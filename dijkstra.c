#include <stdlib.h>
#include <stdio.h>
#include <limit.h>

#define N 6 

typedef struct{
 	char vexs[MAXNUM];
 	int edges[MAXNUM][MAXNUM];
 	int n ,e;		//定点数与边数
}AdjGragh;

void dijkstra(AdjGraph G, int v0, int *path,int *dist)
{
	int S[N] = 0;
	int i;
	S[v0] = 1;
	for(i = 0 ; i < G.n; i++){
		dist[i] = G.arc[vo][i];
		if(dist[i] < INT_MAX) path[i] = v0;
		else path[i] = -1; 
	}

	for(i = 0; i < G.n; i++){
		int min = INT_MAX, v = -1;
		int k;
		for(k = 0; k < N; k++){
			if(S[k] == 0 && dist[k] < min){
				v = k;
				min = dist[k];
			}
		}
		if(v == -1) break;
		S[v] = 1;
		for(k = 0; k < N; k++){
			if(S[k] == 0 && (min + G.arc[v][k]) < dist[k]){
				dist[k] = min + G.arc[v][k];
				path[k] = v;
			}
		}
	}
}