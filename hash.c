#include <stdio.h>
#include <stdlib.h>

typedef struct hash
{
	int data;
	struct hash * next;
}Lhash, *Phash;

void hash_create1(int *a, int n, int *hash, int m)
{
	int i, j, flag = 1; 
	for(i = 0; i < n; i++){
		if(hash[a[i] % m] == -1){
			hash[(a[i] % m)] = a[i];
			printf("one :%d in %d \n", a[i], a[i]%m);
		}else{
			for(j = 0; j < m; ++j){
				if(hash[(a[i]+j) % m] == -1){
					hash[(a[i]+j) % m] == a[i];
					printf("two :%d in %d \n", a[i], a[i]%m);
					flag = 0;
					break;
				} //if
			}// for
			if(flag){
				printf("hash is full ");
				
				return ;
			} //if
		} //else
	} //for
	for(i = 0; i < n; i++) printf("%d ", hash[i]);
} //hash_create1

void hash_search1(int *hash, int m, int key)
{
	int d;
	for(d = 0; d < m; ++d){
		if(hash[key % m+d] == -1){
			printf("no found ");
			return ;
		}
		if(hash[key % m+d] == key){
			printf("found %d ", key);
			return;
		}
	}
	printf("no found & full");
	return ;
}

// void hash_create2(int *a, int n, Phash hash, int m)
// {
// 	int i ;
// 	Phash temp = (Phash)malloc(sizeof(Lhash));
// 	temp->next = NULL;
// 	for(i = 0; i < n; i++){
// 		temp->data = a[i];
// 		if(hash[a[i] % m]->data != -1){
// 			hash[a[i] % m]->next = temp;
// 		}else{
// 			hash[a[i] % m]->data = a[i];
// 		} //else
// 	} // for
// } // hash_create2

// void hash_search2(Phash hash, int key, int m)
// {
// 	while(hash[key % m]->next){
// 		if(hash[key % m]->data == -1){
// 			printf("no found");
// 			return ;
// 		}
// 		if(hash[key % m]->data == key){
// 			printf("found %d", key);
// 			return ;
// 		}
// 		hash[key % m] = hash[key % m]->next;
// 	}
// 	printf("no found");
// 	return ;
// }

int main()
{
	int hash[5] = {-1, -1, -1, -1, -1};
	int i;
	for(i = 0; i < 5; i++) printf("%d ", hash[i]);
	int array[5] = {121,132,122,133,135};

	hash_create1(array, 5, hash, 5);
	getchar();
	hash_search1(array, 5, 121);
	getchar();

	return 0;
}