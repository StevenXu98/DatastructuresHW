#include <stdio.h>
#define TERM_NUM 15


typedef struct martix
{
	int row;
	int col;
	int data;	
}Martix;


void martix_init(Martix *M);
void martix_print(Martix *M);
void martix_oper(Martix *in, Martix *out);

int main()
{
	Martix in[TERM_NUM];
	Martix out[TERM_NUM];

	martix_init(in);
	martix_print(in);
	martix_oper(in, out);
	printf("\n");
	martix_print(out);

	return 0;
}



void martix_init(Martix* M)
{
	int test[][5] = {{1,2,3,4,5},{0,1,2,3,4},{0,0,1,2,3},{0,0,0,1,2},{0,0,0,0,1}};
	int count = 1;
	int i,j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(test[i][j] != 0)
			{
				M[count].row = i;
				M[count].col = j;
				M[count].data = test[i][j];
				count++;
			}
		}
	}
	M[0].col = 5;
	M[0].row = 5;
	M[0].data = --count;

}

void martix_print(Martix *M)
{
	int i,j;
	int count = 1;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(M[count].row == i && M[count].col == j)
			{
				printf("%d ",M[count].data);
				count++;
			}else printf("0 ");		
		}
		printf("\n");
	}
}

void martix_oper(Martix *in, Martix *out)
{

	int term[5],star[5];
	int n = in[0].data;
	int i,j,k;
	int b_star;

	for(i = 0; i < 5; i++)    
		term[i] = 0;

	for(j = 1; j <= n; j++)
		term[in[j].col]++;

	star[0] = 1;
	for(k = 1; k < 5; k++)
		star[k] = star[k - 1] + term[k - 1];

	out[0].col = in[0].col;
	out[0].row = in[0].row;
	out[0].data = in[0].data;
	
	for(i = 1;i <= n;i++)
	{
		b_star = star[in[i].col]++;
		out[b_star].col = in[i].row;
		out[b_star].row = in[i].col;
		out[b_star].data = in[i].data;
	}

}

