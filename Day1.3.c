#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
void merge(int *A,int p,int q,int r)
{
	int n1,n2,*L,*R,i,j,k;
	n1=q-p+1;
	n2=r-q;
	L=(int*)calloc(n1+1,sizeof(int));
	R=(int*)calloc(n2+1,sizeof(int));
	for(i=0;i<n1;i++)
	{
		L[i]=A[p+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=A[q+j+1];
	}
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		A[k]=L[i++];
		else
		A[k]=R[j++];
	}
	free(L);
	free(R);
}
void mergesort(int *A,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}
void max_heapify(int *A,int n,int i)
{
	int l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if(l<n && A[l]>A[i])
		largest=l;
	else
		largest=i;
	if(r<n && A[r]>A[largest])
		largest=r;
	if(largest!=i)
	{
		int t=A[i];
		A[i]=A[largest];
		A[largest]=t;
		max_heapify(A,n,largest);
	}
}
void build_max_heap(int *A,int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	max_heapify(A,n,i);
}
void heapsort(int* A,int n)
{
	int i,t;
	build_max_heap(A,n);
	for(i=n-1;i>0;i--)
	{
		t=A[i];
		A[i]=A[0];
		A[0]=t;
		max_heapify(A,i,0);
	}
}
int randomized_partition(int* A, int p, int r)
{
	int i,j;
	int q=rand()%(r-p)+p;
	int t=A[q];
	A[q]=A[r];
	A[r]=t;
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(A[j]<A[r])
		{
			i++;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return (i+1);
}
void quicksort(int* A, int p, int r)
{
	if(p<r)
	{
		int q=randomized_partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
void write_to_file(int *A,int n)
{
	FILE *fp;
	fp=fopen("abc.txt","w");
	if(fp==NULL)
	{
		printf("\nFile not found");
		return;
	}
	int c=0,num;
	while(c<n)
	{
		num=rand()%n+1;
		if(!A[num-1])
		{
			A[num-1]=1;
			c++;
			fprintf(fp,"%d\n",num);
		}
	}
	fclose(fp);
}
int main()
{
	srand(time(NULL));
	clock_t s,e;
	float time;
	int d,*A,i,n,num;FILE *fp,*fp1,*fp2;
	printf("\nEnter limit :");
	scanf("%d",&n);
	A=(int*)malloc(n*sizeof(int));
	i=0;
	write_to_file(A,n);
	while(1)
	{
		printf("\nEnter 1/2/3/4 for heapsort,mergesort,randomized quicksort and exit:");
		scanf("%d",&d);
		switch(d)
		{
			case 1: 
				fp=fopen("abc.txt","r+");
				if(fp==NULL)
				{
					printf("\nFile not found");
					return;
				}
				while(fscanf(fp,"%d",&num)!=EOF)
				{
					A[i++]=num;
				}
				fclose(fp);
				s=clock();
				heapsort(A,n);
				e=clock();
				time=(float)(e-s)/CLOCKS_PER_SEC;
				/*for(i=0;i<n;i++)
				printf("\n%d",A[i]);*/
				printf("\nTime taken by heapsort is %f",time);
				i=0;
				break;
			case 2: printf("\n2");
				fp1=fopen("abc.txt","r+");
				if(fp1==NULL)
				{
					printf("\nFile not found");
					return;
				}
				while(fscanf(fp1,"%d",&num)!=EOF)
				{
					A[i++]=num;
				}
				fclose(fp1);
				s=clock();
				mergesort(A,0,n-1);
				e=clock();
				time=(float)(e-s)/CLOCKS_PER_SEC;
				/*for(i=0;i<=n-1;i++)
				printf("\n%d",A[i]);*/
				printf("\nTime taken by mergesort is %f",time);
				i=0;
				break;
			case 3:  
				fp2=fopen("abc.txt","r+");
				if(fp2==NULL)
				{
					printf("\nFile not found");
					return;
				}
				while(fscanf(fp2,"%d",&num)!=EOF)
				{
					A[i++]=num;
				}
				fclose(fp2);
				s=clock();
				quicksort(A,0,n-1);
				e=clock();
				time=(float)(e-s)/CLOCKS_PER_SEC;
				/*for(i=0;i<n;i++)
				printf("\n%d",A[i]);*/
				printf("\nTime taken by randomized quicksort is %f",time);
				break;
			case 4: free(A);
				exit(0);
				break; 
			default: printf("\nWrong choice");
		}
	}
}
