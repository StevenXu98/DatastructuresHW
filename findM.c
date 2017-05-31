#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct{
	int num;
	int lengh;
}number;

void qsort(int a[], int l, int r)
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

int findM(*array, *num)
{
	int i = 1;
	int j = 0;
	num[0].num = array[0];
	num[0].lengh++;
	while(i < N){
		if(array[i-1] == array[i]){
			i++;
			num[j].length++;
		}
		else{
			j++;
			num[j].num = array[i];
			i++;
		}
	}
	return j-1;
}

int main()
{
	int array[N];
	number num[N];
	memset(num, 0, 20*sizeof(number));
	int j;

	qsort(array, 0, N);
	j = findM(array,num);
	qsort_length(num, 0, j);

	printf("%d", num[j].num);

	return 0;
}