#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,cap;
    printf("\nEnter number of items and capacity of bag: ");
    scanf("%d%d",&n,&cap);
    int b[n+1][cap+1],w[n+1],c[n+1];
    printf("\nEnter weights with benefits: ");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&w[i],&c[i]);
    }
    for(i=0;i<=n;i++)
    {
        b[i][0]=0;
    }
    for(i=0;i<=cap;i++)
    {
        b[0][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=cap;j++)
        {
            if(w[i-1]<=j)
            {
                if((c[i-1]+b[i-1][j-w[i-1]])>b[i-1][j])
                {
                    b[i][j]=c[i-1]+b[i-1][j-w[i-1]];
                }
                else
                {
                    b[i][j]=b[i-1][j];
                }
            }
            else
            {
                b[i][j]=b[i-1][j];
            }
        }
    }
    printf("Resultant matrix: \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            printf(" %d ",b[i][j]);
        }
        printf("\n");
    }
    i=n;
    int k=cap,a[n],d=0;
    while(i>0 && k>0)
    {
        if(b[i][k]!=b[i-1][k])
        {
            a[d++]=i;
            k=k-w[i-1];
        }
        i--;
    }
    int weight=0,benefit=0;
    for(i=0;i<d;i++)
    {
        weight=weight+w[a[i]-1];
        benefit=benefit+c[a[i]-1];
    }
    printf("\nMaximum weight is %d and maximum benefit is %d",weight,benefit);
    printf("\nItems taken are: \n");
    for(i=d-1;i>=0;i--)
    {
        printf("(%d,%d)  ",w[a[i]-1],c[a[i]-1]);
    }
    return 0;
}
