#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int path(int s,int dest,int pre[][5])
{
	if(s==dest)
	{
		return;
	}
	else
	{
		path(s,pre[s][dest]-1,pre);         
		printf("%d --> ",pre[s][dest]);
	}
}
int main()
{
	int n,s,dest,w,i,j,k,p,q,dist;
	printf("\nEnter number of rows : ");
	scanf("%d",&n);
	int d[n][n],a[n][n],pre[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			d[i][j]=0;
			else
			d[i][j]=1000;
		}
	}
	FILE* fp=fopen("abc.txt","r");
	if(fp==NULL)
	{
		printf("\nFile cannot be found");
		return;
	}
	while(fscanf(fp,"%d%d%d",&s,&dest,&w)!=EOF)
	{
		d[s-1][dest-1]=w;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(d[i][j]!=0||d[i][j]!=1000)
			pre[i][j]=i+1;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("    %d     ",d[i][j]);
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				p=d[i][j];
				q=d[i][k]+d[k][j];
				if(p<q)
				a[i][j]=p;
				else
				a[i][j]=q;
				if(d[i][j]>d[i][k]+d[k][j]) 
				pre[i][j]=pre[k][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				d[i][j]=a[i][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("  %d  ",d[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("  %d  ",pre[i][j]);
		}
	}
	printf("\nEnter source and destination : ");
	scanf("%d%d",&s,&dest);
	path(s-1,dest-1,pre);
	printf("%d",dest);
	printf("\nPath weight is %d",d[s-1][dest-1]);
}

			

