#include <stdio.h>
#define TERM_NUM 15


typedef struct martix
{
	int row;
	int col;
	int data;
}Martix;

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

void martix_add(Martix *m1,Martix *m2,Martix *m3)
{
	int i = 0,j = 0,k = 0;
//	int count = 1;
	Martix temp;

	m3[0].row = m1[0].row;
	m3[0].col = m1[0].col;
//	printf("m1=%d m2= %d ",m1[0].data,m2[0].data);
	
	

	while(i<=m1[0].data || j<=m2[0].data){
		if(m1[i].row == m2[j].row){
			if(m1[i].col < m2[j].col){
				m3[k].row = m1[i].row;
				m3[k].col = m1[i].col;
				m3[k].data = m1[i].data;
				k++;
				i++;
			}else if(m1[i].col > m2[j].col){
				m3[k].row = m2[j].row;
				m3[k].col = m2[j].col;
				m3[k].data = m2[j].data;
				k++;
				j++;
			}else{
				temp.data = m1[i].data + m2[j].data;
				if(temp.data){
					m3[k].row = m1[i].row;
					m3[k].col = m1[i].col;
					m3[k].data = temp.data;
					k++;
				}
				i++;
				j++;
			}
		}else if(m1[i].row < m2[j].row){
			m3[k].row = m1[i].row;
			m3[k].col = m1[i].col;
			m3[k].data = m1[i].data;
			k++;
			i++;
		}else{
			m3[k].row = m2[j].row;
			m3[k].col = m2[j].col;
			m3[k].data = m2[j].data;
			k++;
			j++;
		}
//	martix_print(m3);
//	printf("\n");	
	}
	
	m3[0].data = k;
}

int main()
{
	Martix m1[TERM_NUM],m2[TERM_NUM],m3[TERM_NUM];
	martix_init(m1);
	martix_oper(m1,m2);
	martix_print(m1);
	printf("\n");
	martix_print(m2);
	printf("\n");
	martix_add(m1,m2,m3);
	printf("\n");
	martix_print(m3);

	return 0;
}
