#include <stdio.h>
#include <stdlib.h>
#include<time.h>
long c=0;
void bubble(int ar[],long n)
{
    c=0;
    long i,j,pos,bound=n-1;
    int swap=1;
    for(i=0; i<n; i++)
    {
        swap=0;
        for(j=0; j<bound; j++)
        {
            c++;
            if(ar[j]>ar[j+1])
            {
                swap=1;
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
                pos=j;
            }
        }
        bound=pos;
        if(swap==0)
            break;
    }
    printf("\nNumber of comparisons is : %ld ",c);
}
void cocktail_shaker(int ar[],long n)
{
    long start=0,end=n-1,pos,i;
    c=0;
    int swap=1;
    while(swap==1)
    {
        swap=0;
        for(i=start; i<end; i++)
        {
            c++;
            if(ar[i]>ar[i+1])
            {
                swap=1;
                int t=ar[i];
                ar[i]=ar[i+1];
                ar[i+1]=t;
                pos=i;
            }
        }
        if(swap==0)
        break;
        end=pos;
        swap=0;
        for(i=end;i>start;i--)
        {
            c++;
            if(ar[i]<ar[i-1])
            {
                swap=1;
                int t=ar[i];
                ar[i]=ar[i-1];
                ar[i-1]=t;
                pos=i;
            }
        }
        if(swap==0)
            break;
        start=pos;
    }
    printf("\nNumber of comparisons is : %ld",c);
}
void quick(int ar[],long l,long r)
{
    if(l<r)
    {
        int p=getpivot(ar,l,r);
        quick(ar,l,p-1);
        quick(ar,p+1,r);
    }
}
int getpivot(int ar[],long l,long r)
{
    int p=ar[r];
    long i=l-1,j;
    for(j=l;j<=r-1;j++)
    {
        c++;
        if(ar[j]<=p)
        {
            i++;
            int t=ar[i];
            ar[i]=ar[j];
            ar[j]=t;
        }
    }
    int t=ar[i+1];
    ar[i+1]=ar[r];
    ar[r]=t;
    return (i+1);
}
int main()
{
    int *ar,*p,*q;
    long i,n;
    int j;
    srand(time(NULL));
    printf("\nEnter limit of array : ");
    scanf("%ld",&n);
    ar=(int*)malloc(n*sizeof(int));
    p=(int*)malloc(n*sizeof(int));
    q=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        j=rand()%101;
        ar[i]=j;
        p[i]=j;
        q[i]=j;
    }
    printf("\nOriginal array : \n");
  /*  for(i=0;i<n;i++)
        printf("%d ",ar[i]);*/
    printf("\nQuick sort : ");
    quick(ar,0,n-1);
     printf("\nNumber of comparisons is : %d ",c);
 /*    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);*/
     printf("\nCocktail shaker sort : ");
    cocktail_shaker(p,n);
  /*    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",p[i]);*/
    printf("\nBubble sort : ");
    bubble(q,n);
 /*     printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",q[i]);*/
    return 0;
}
