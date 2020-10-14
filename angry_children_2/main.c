#include<stdio.h>
#include<stdlib.h>
void quick(int ar[],int l,int r)
{
    if(l<r)
    {
        int p=getpivot(ar,l,r);
        quick(ar,l,p-1);
        quick(ar,p+1,r);
    }
}
int getpivot(int ar[],int l,int r)
{
    int p=ar[r],c;
    int i=l-1,j;
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
int min_diff(int a,int* copy, int n,int* pos,int j,int k)
{
    int i,d,min=9999999,t;
        for(i=0;i<n;i++)
        {
            if(copy[i]!=-1 && copy[i]>=a)
            {
                d=copy[i]-a;
                if(d<min)
                {
                    min=d;
                    t=i;
                }
            }
        }
        return t;
}
int* func(int a,int* copy,int n,int* pos,int j,int k)
{
    int t,i;
    while(k--)
    {
        t=min_diff(a,copy,n,pos,j,k);
        a=copy[t];
        copy[t]=-1;
        pos[j++]=t;
    }
    return pos;
}
int compute_unfairness(int* c,int k,int* packets)
{
    int i,j,sum=0;
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            sum=sum+(packets[c[j]]-packets[c[i]]);
        }
    }
    return sum;
}
int main()
{
    int n,k,i,j;
    printf("\nn:");
    scanf("%d",&n);
    printf("\nk:");
    scanf("%d",&k);
    if(n>=2 && n<=10000 && k>=2 && k<=n)
    {
        int packets[n],t;
        printf("\npackets(i):");
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t>=0 && t<=1000000000)
            {
                packets[i]=t;
            }
        }
        quick(packets,0,n-1);
      /* for(i=0;i<n;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(packets[j]>packets[j+1])
                {
                    int t=packets[j];
                    packets[j]=packets[j+1];
                    packets[j+1]=t;
                }
            }
        }*/
        printf("\nPACKETS SORTED");
        for(i=0;i<n;i++)
        {
            printf("\n%d",packets[i]);
        }
        int copy[n],j,*c,d,f;
        int diff[n-2];
        c=(int*)(malloc(k*sizeof(int)));
        for(i=0;i<n-2;i++)
        {
            for(j=0;j<n;j++)
            {
                copy[j]=packets[j];
            }
            copy[i]=-1;
            c[0]=i;
            c=func(packets[i],copy,n,c,1,k-1);
            d=compute_unfairness(c,k,packets);
            diff[i]=d;
        }
        int min,p;
        min=diff[0];
        for(i=1;i<n-2;i++)
        {
            if(diff[i]<min)
            {
                min=diff[i];
                p=i;
            }
        }
        printf("\nDIFF");
        printf("\n%d",min);
        printf("\ni=");
        scanf("%d",&i);
    }
    return 0;
}
