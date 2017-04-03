#include <stdio.h>

int main()
{
	int num[100];
	int *p ;
	p = num;


	int n = 0, m = 0;
	int out = 0;
	int i;
	int k = 0;

	printf("how many monkey : ");
	scanf("%d", &n);

	printf("what number out : ");
	scanf("%d", &out);

	for(i = 0; i < n ; i++){
		*(p+i) = i+1;
//		printf("NO. %d\n", *(p+i));
	}
	
	i = 0;
	while(m < n-1){

		if(*(p+i) != 0) k++;
		if(k == out){
//			printf("NO. %d out\n", *(p+i));
			*(p+i) = 0;
			k = 0;
			m++;
		}
		i++;
		if(i == n) i = 0;
	}

	for(i = 0; i < n; i++){
		if(*(p+i) != 0) printf("the last one is %d", *(p+i));
	}
}
