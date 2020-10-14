#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("\nEnter limit :");
    scanf("%d",&n);
    float a[n][n+1],x[n],x1[n];
    printf("\nEnter coefficients of equations: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        x[i]=0;
        x1[i]=0;
    }
    int c=0;
    float sum=0;
    while(1)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(j!=i)
                sum=sum+a[i][j]*x1[j];
            }
            x1[i]=(a[i][n]-sum)/a[i][i];
        }
        c=0;
        for(i=0;i<n;i++)
        {
            if(fabs(x[i]-x1[i])<0.00001)
            {
                c++;
            }
        }
        if(c==3)
            break;
        for(i=0;i<n;i++)
            x[i]=x1[i];
    }
    for(i=0;i<n;i++)
    {
        printf("\n%f",x1[i]);
    }
    return 0;
}
