#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    printf("\nEnter number of equations: ");
    scanf("%d",&n);
    float ar[n][n+1];
    printf("\nEnter coefficients of equations :");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&ar[i][j]);
        }
    }
    float d;
    for(k=0;k<n-1;k++)
    {
        for(i=k+1;i<n;i++)
        {
            d=ar[i][k]/ar[k][k];
            for(j=0;j<n+1;j++)
            {
                ar[i][j]=ar[i][j]-d*ar[k][j];
            }
        }
    }
    printf("\nAugmented matrix:");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n+1;j++)
        {
            printf("%f   ",ar[i][j]);
        }
    }
    float x[n],sum=0;
    x[n-1]=ar[n-1][n]/ar[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
        {
            sum=sum+ar[i][j]*x[j];
        }
        x[i]=(ar[i][n]-sum)/ar[i][i];
    }
    for(i=0;i<n;i++)
    {
        printf("\n%f",x[i]);
    }
    return 0;
}
