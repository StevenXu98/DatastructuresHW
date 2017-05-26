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
		if(hash[a[i] mod m] == -1){
			hash[(a[i] mod m)] = a[i];
		}else{
			for(j = 1, j < m, ++j){
				if(hash[(a[i]+j) mod m] == -1){
					hash[(a[i]+j) mod m] == a[i];
					flag = 0;
					break;
				} //if
			}// for
			if(flag){
				printf("hash is full");
				return ;
			} //if
		} //else
	} //for
} //hash_create1

void hash_search1(int *hash, int m, int key)
{
	int d
	for(d = 0; d < m; ++d){
		if(hash[key mod m+d] == -1){
			printf("no found ");
			return ;
		}
		if(hash[key mod m+d] == key){
			printf("found %d ", key);
			return;
		}
	}
	printf("no found & full");
	return ;
}

void hash_create2(int *a, int n, Lhash *hash, int m)
{
	int i ;
	Phash temp = (Phash)malloc(sizeof(Lhash));
	temp->next = NULL;
	for(i = 0; i < n; i++){
		temp->data = a[i];
		if(hash[a[i] mod m]->data != -1){
			hash[a[i] mod m]->next = temp;
		}else{
			hash[a[i] mod m]->data = a[i];
		} //else
	} // for
} // hash_create2

void hash_search2(Lhash *hash, int key)
{
	while(hash[key mod m]){
		if(hash[key mod m]->data == -1){
			printf("no found");
			return ;
		}
		if(hash[key mod m]->data == key){
			printf("found %d", key);
			return ;
		}
		hash[key mod m] = hash[key mod m]->next;
	}
	printf("no found");
	return ;
}

int main()
{
	

	return 0;
}