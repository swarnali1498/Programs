#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print_optimal_parens(int** s,int i,int j)
{
	if(i==j)
	{
		printf("A%d",i+1);
	}
	else
	{
		printf("(");
		print_optimal_parens(s,i,s[i][j]);
		print_optimal_parens(s,s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int i,j,l,k,n;
	long int q;
	printf("\nEnter limit of matrix dimensions array :");
	scanf("%d",&n);
	int p[n];
	printf("\nEnter matrix dimensions in array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	int **m,**s;
	m=(int**)calloc((n),sizeof(int*));
	for(i=0;i<n;i++)
	{
		m[i]=(int*)calloc((n-1),sizeof(int));
	}
	s=(int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	{
		s[i]=(int*)calloc((n-1),sizeof(int));
	}
	for(l=2;l<n;l++)
	{
		for(i=0;i<n-l;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j])
				{

					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("\n");
	print_optimal_parens(s,0,n-2);
	for(i=0;i<n;i++)
	free(m[i]);
	free(m);
	for(i=0;i<n;i++)
	free(s[i]);
	free(s);
}
