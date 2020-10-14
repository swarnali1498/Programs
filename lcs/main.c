#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_lcs(int** b,char* x, int i, int j)
{
	if(i==-1||j==-1)
	return;
	if(b[i][j]==0)
	{
		print_lcs(b,x,i-1,j-1);
		printf("%c",x[i]);
	}
	else if(b[i][j]==1)
	{
		print_lcs(b,x,i-1,j);
	}
	else
	{
		print_lcs(b,x,i,j-1);
	}
}
int main()
{
	char x[100],y[100];
	printf("\nEnter first string : ");
	scanf("%s",x);
	printf("\nEnter second string : ");
	scanf("%s",y);
	int m,n,i,j;
	m=strlen(x);
	n=strlen(y);
	int** b,**c;
	b=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	b[i]=(int*)malloc(n*sizeof(int));
	c=(int**)malloc((m+1)*sizeof(int*));
	for(i=0;i<(m+1);i++)
	c[i]=(int*)malloc((n+1)*sizeof(int));
	for(i=0;i<=m;i++)
	{
		c[i][0]=0;
	}
	for(i=0;i<=n;i++)
	{
		c[0][i]=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x[i]==y[j])
			{
				c[i+1][j+1]=c[i][j]+1;
				b[i][j]=0;
			}
			else if(c[i][j+1]>=c[i+1][j])
			{
				c[i+1][j+1]=c[i][j+1];
				b[i][j]=1;
			}
			else
			{
				c[i+1][j+1]=c[i+1][j];
				b[i][j]=2;
			}
		}
	}
	printf("\nLongest common subsequence is: \n");
	print_lcs(b,x,m-1,n-1);
}

