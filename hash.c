#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 6

typedef struct hash
{
	int data;
	struct hash * next;
}Lhash, *Phash;

void hash_create1(int *a, int *hash)
{
	int i, j, flag = 1; 
	for(i = 0; i < N; i++){
		if(hash[a[i] % M] == -1){
			hash[(a[i] % M)] = a[i];
			printf("one :%d in %d \n", a[i], a[i]%M);
		}else{
			for(j = 1; j < M; ++j){
				flag = 1;
				if(hash[(a[i]+j) % M] == -1){
					hash[(a[i]+j) % M] = a[i];
					printf("two :%d in %d \n", a[i], (a[i]+j)%M);
					flag = 0;
					break;
				} //if
			}// for
			if(flag){
				printf("hash is full %d input fail \n", a[i]);
				for(i = 0; i < N; i++) printf("%d ", hash[i]);
				return ;
			} //if
		} //else
	} //for
	for(i = 0; i < N; i++) printf("%d ", hash[i]);
} //hash_create1

void hash_search1(int *hash, int key)
{
	int d;
	for(d = 0; d < M; ++d){
		printf("%d %d \n", (key+d)%M,hash[(key+d)%M]);
		if(hash[(key+d)%M ] == -1){
			printf("no found ");
			return ;
		}
		if(hash[(key+d)%M] == key){
			printf("found %d ", key);
			return;
		}
	}

	return ;
}

void hash_create2(int *a,Phash *hash)
{
	int i ;
	Phash temp;
	Phash phash; 
	for(i = 0; i < N; i++){
		temp = (Phash)malloc(sizeof(Lhash));
		temp->next = NULL;
		temp->data = a[i];
		phash = hash[a[i] % M];
		if(phash->data != -1){
			while(phash->next != NULL)
				phash = phash->next;
			phash->next = temp;
		}else{
			phash->data = a[i];
		} //else
	} // for
} // hash_create2

void hash_search2(Phash *hash, int key)
{
	while(hash[key % M]){
		if(hash[key % M]->data == -1){
			printf("no found");
			return ;
		}
		if(hash[key % M]->data == key){
			printf("found %d", key);
			return ;
		}
		hash[key % M] = hash[key % M]->next;
	}
	printf("no found2");
	return ;
}

int main()
{
	int array[N] = {121,131,141,133,135,140};
	int i;
	Phash hash[M];
	for(i = 0; i < M; i++){
		hash[i] = (Phash)malloc(sizeof(Lhash));
		hash[i]->data = -1;
		hash[i]->next = NULL;
	}

	hash_create2(array, hash);
	printf("%d %d \n",hash[0]->data ,hash[0]->next->data);
	printf("%d %d %d \n",hash[1]->data ,hash[1]->next->data,hash[1]->next->next->data);
//	printf("%d %d \n",hash[2]->data ,hash[2]->next->data);
	printf("%d \n",hash[3]->data);
//	printf("%d %d \n",hash[4]->data ,hash[4]->next->data);
	hash_search2(hash, 131);

	

	return 0;
}
