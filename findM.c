#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct{
	int num;
	int length;
}number;

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
void Qsort_length(number *a, int l, int r)
{
	if(l < r){
		int i = l, j = r;
		number x = a[l];
		while(i < j){
			while(i < j && a[j].length >= x.length)
				j--;
			if(i < j)
				a[i++] = a[j];

			while(i < j && a[i].length <= x.length)
				i++;
			if(i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		Qsort_length(a, l, i-1);
		Qsort_length(a, i+1, r);		
	}
}

int findM(int *array, number *num)
{
	int i = 1;
	int j = 0;
	num[0].num = array[0];
	num[0].length++;
	while(i < N){
		if(array[i-1] == array[i]){
			i++;
			num[j].length++;
		}
		else{
			j++;
			num[j].num = array[i];
			num[j].length++;
			i++;
		}
	}
//	printf("j is %d \n", j);
	return j;
}

int main()
{
	int array[N] = {6,6,4,2,1};
//	int array[N] = {2,4,5,6,1,5,1,2};
	int i;
	number num[N];
	memset(num, 0, N*sizeof(number));
	int j;

	Qsort(array, 0, N);
	for(i = 0; i < N; i++) printf("%d ", array[i]);
	printf("\n");
	
	j = findM(array,num);
	Qsort_length(num, 0, j);

	for(i = 0; i < N; i++) printf("%d %d \n", num[i].num, num[i].length);

	printf("%d", num[j].num);

	return 0;
}
