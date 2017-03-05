#include <stdio.h>

typedef struct 
{	
	int id;
	char name[21];	
}type_name;


void ListPrint(type_name *p,int num)
{
	for(int i = 0; i < num; i++){
		printf("%d ", p[i].id); // p[i] == *(p+i)
//		printf("%s", p[i].name);
	}
	printf("\n");
}

int main()
{

	type_name la[5], lb[5], lc[10];

	int i = 0, j = 0, k = 0, n = 0;

	for(i = 0; i < 5; i++)
		la[i].id = (2*i);		//表a赋值 
	

	for(i = 0; i < 5; i++)
		lb[i].id = (2*i+1);		//表b赋值 
		
	i = 0;

	while(i < 5 && j < 5){
		if(la[i].id == lb[j].id){
			lc[k++] = la[i++]; j++; n++;	//元素重复 指针同时后移  总长度减去n 
		}else if(la[i].id < lb[j].id)
			lc[k++] = la[i++];
		else
			lc[k++] = lb[j++];
	}

	while(i < 5) lc[k++] = la[i++];
	while(j < 5) lc[k++] = lb[j++];

	ListPrint(la, 5);
	ListPrint(lb, 5);
	ListPrint(lc, 10-n);


	return 0;
}


