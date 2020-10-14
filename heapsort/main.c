#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
void max_heapify(int *a,int n,int i)
{
    int l,r,largest,t;
    l=2*i+1;
    r=2*i+2;
    if(l<n && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<n && a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        max_heapify(a,n,largest);
    }
}
void build_max_heap(int *a,int n)
{
    int i;
    for(i=n/2;i>=0;i--)
        max_heapify(a,n,i);
}
void heapsort(int *a,int n)
{
    build_max_heap(a,n);
    int i,t,n1=n;
    for(i=n1-1;i>=1;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        n--;
        max_heapify(a,n,0);
    }
}
void merge(int *b,int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int l1[n1+1],l2[n2+1];
    for(i=0;i<n1;i++)
    {
        l1[i]=b[p+i];
    }
    for(i=0;i<n2;i++)
    {
        l2[i]=b[q+i+1];
    }
    l1[n1]=INT_MAX;
    l2[n2]=INT_MAX;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(l1[i]<=l2[j])
        {
            b[k]=l1[i++];
        }
        else
        {
            b[k]=l2[j++];
        }
    }
}
void mergesort(int *b,int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(b,p,q);
        mergesort(b,q+1,r);
        merge(b,p,q,r);
    }
}
void quick(int d[],long l,long r)
{
    if(l<r)
    {
        int p=getpivot(d,l,r);
        quick(d,l,p-1);
        quick(d,p+1,r);
    }
}
int getpivot(int *d,long l,long r)
{
    int s=rand()%(r-l)+l;
    int t=d[s];
    d[s]=d[r];
    d[r]=t;
    int p=d[r];
    long i=l-1,j;
    for(j=l;j<=r-1;j++)
    {
        if(d[j]<=p)
        {
            i++;
            int t=d[i];
            d[i]=d[j];
            d[j]=t;
        }
    }
    t=d[i+1];
    d[i+1]=d[r];
    d[r]=t;
    return (i+1);
}
int main()
{
    srand(time(NULL));
    clock_t s,e;
    int i,n,*a,*b,*d,num,c=0;
    double time;
    printf("Enter limit: ");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    b=(int*)calloc(n,sizeof(int));
    d=(int*)calloc(n,sizeof(int));
    FILE* fp;
    fp=fopen("heap.txt","w");
    if(fp==NULL)
    {
        printf("File not found");
        return;
    }
    while(c<n)
    {
        num=rand()%n;
        if(!a[num])
        {
            a[num]=1;
            c++;
            fprintf(fp,"%d\n",num);
        }
    }
    fclose(fp);
    fp=fopen("he ap.txt","r");
    if(fp==NULL)
    {
        printf("File not found");
        return;
    }
    i=0;
    while(fscanf(fp,"%d",&num)!=EOF)
    {
        a[i]=num;
        b[i]=num;
        d[i]=num;
        i++;
    }
    s=clock();
    heapsort(a,n);
    /*printf("\nSorted array : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);*/
    e=clock();
    time=(double)(e-s)/CLOCKS_PER_SEC;
    printf("\nTime taken by heapsort is %lf",time);
    s=clock();
    mergesort(b,0,n-1);
    /*printf("\nSorted array : \n");
    for(i=0;i<n;i++)
        printf("%d ",b[i]);*/
    e=clock();
    time=(double)(e-s)/CLOCKS_PER_SEC;
    printf("\nTime taken by mergesort is %lf",time);
    s=clock();
    quick(d,0,n-1);
    /*printf("\Sorted array : \n");
    for(i=0;i<n;i++)
        printf("%d ",d[i]);*/
    e=clock();
    time=(double)(e-s)/CLOCKS_PER_SEC;
    printf("\nTime taken by randomized quicksort is %lf",time);
}
