#include <stdio.h>
#include <stdlib.h>

#define N 8

void Qsort(int *a, int l, int r)
{
	if(l < r){
		int i = l, j = r;
		int x = a[l];
		while(i < j){
			while(i < j && a[j] >= x)
				j--;
			if(i < j)
				a[i++] = a[j];

			while(i < j && a[i] <= x)
				i++;
			if(i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		Qsort(a, l, i-1);
		Qsort(a, i+1, r);		
	}
}

int getresult(int *array, int *result)
{
	int i = 1,j = 0;
	result[0] = array[0];

	while(i < N){
		if(array[i-1] == array[i]){
			i++;
		}else{
			j++;
			result[j] = array[i];
			i++;
		}
	}

	return j;
}

int main()
{
	int array[N] = {2,4,5,6,1,5,1,2};
	int result[N];
	int k, j;
	Qsort(array, 0, 8);
//	for(int i = 0; i < N; i++){
//		printf("%d ", array[0]);
//	}
	
	j = getresult(array, result);
	printf("input k:");
	scanf("%d", &k);
	if(k > j+1){
		printf("only have %d number", j+1);
	}else{
		printf("%d", result[k-1]);
	}


	return 0;
}

