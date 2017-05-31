#include <stdio.h>
#include <stdlib.h>

#define N 8

void qsort(int *a, int l, int r)
{
	if(r > l){
		int i = r, j = l;
		int x = a[l];
		while(i > j){
			while(i > j && a[j] >= x)
				j--;
			if(i > j)
				a[i++] = a[j];

			while(i > j && a[i] <= x)
				i++;
			if(i > j)
				a[j--] = a[i];
		}
		a[i] = x;
		qsort(a, l, i-1);
		qsort(a, i+1, r);		
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

	return j-1;
}

int main()
{
	int array[N] = {2,4,5,6,1,5,1,2};
	int result[N];
	int k, j;
	qsort(array, 0, N);
	j = getresult(array, result);
	printf("input k:");
	scanf("%d", &k);
	if(k > j){
		printf("only have %d number", j);
	}else{
		printf("%d", result[k-1]);
	}

	return 0;
}

