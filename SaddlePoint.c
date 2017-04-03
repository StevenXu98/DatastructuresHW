#include <stdio.h>
#define N 4
#define M 4

int main()
{
//	int martix[N][M];
	int i,j,judge = 0;
	int max[M],min[N];

//	for(i = 0; i < N; i++){
//		for(j = 0; j < M; j++){
//			scanf("%d", &martix[i][j]);
//		}
//	}
	int martix[N][M]= {{1,2,3,4},{5,6,6,3},{4,2,3,1},{6,7,8,9}};
	for(i = 0; i < N; i++){
		min[i] = martix[i][0];
		for(j = 0; j < M; j++){			
			if(martix[i][j] < min[i]){
				min[i] = martix[i][j];
			}
		}
	}
	for(j = 0; j < M; j++){
		max[j] = martix[0][j];
		for(i = 0; i < N; i++){
			if(max[j] < martix[i][j]){
				max[j] = martix[i][j];
			}
		}
	}

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if(min[i] == max[j]) printf("%d ", max[i]);
			judge = 1;
		}
	}
//	for(i = 0; i < N; i++)printf("%d ",min[i]);
//	for(j = 0; j < M; j++)printf("%d ",max[j]);
	
	if(!judge)printf("no found");


	return 0;
}
