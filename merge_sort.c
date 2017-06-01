#include <stdio.h>
#include <stdlib.h>

#define N 8



void merge(int *a, int l, int mid, int r)
{
	int i = l, j = l, k = mid+1;
	int b[N];
	while(i <= mid && k <= r){
		if(a[i] < a[k]) b[j++] = a[i++];
		else b[j++] = a[k++]; 
	}
	while(i <= mid) b[j++] = a[i++];
	while(k <= r) b[j++] = a[k++];
	for(i = l; i <= r; i++){ a[i] = b[i];
	printf("%d ",a[i]);}
}


void merge_sort(int *a,int l, int r)
{
	int mid;
	if(l < r){
		int i;
		mid = (l+r)/2;
		merge_sort(a, l, mid);
		merge_sort(a, mid+1, r);
		printf("{");
		for( i = l; i <= mid; ++i)
			printf("%d ", a[i]);
		printf("}");
		printf("{");
		for( i = mid+1; i <= r; ++i)
			printf("%d ", a[i]);
		printf("}");

		merge(a, l, mid, r);
		
		printf(" after merge ");
		printf("{");
		for( i = l; i <= r; ++i)
			printf("%d ", a[i]);
		printf("}");
		printf("\n");

	} 
}

int main()
{
	int a[N] = {7, 9, 11, 2, 8, 3, 4, 6};
	int b[N];
	int i;
	
	for(i = 0; i < N; ++i) printf("%d ", a[i]);
	printf("\n");
	merge_sort(a, 0, N);

	for(i = 0; i < N; ++i) printf("%d ", a[i]);

	getchar();
	return 0;
}
