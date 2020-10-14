#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("\nEnter number of data points :");
    scanf("%d",&n);
    float y[n][n],x[n],x1;
    printf("\nEnter data points: ");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i][0]);
    }
    printf("\nEnter interpolating point :");
    scanf("%f",&x1);
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    printf("\nTable:");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n-i;j++)
        {
            printf("%f   ",y[i][j]);
        }
    }
    float s,sum=y[0][0],p=1;
    s=(x1-x[0])/(x[1]-x[0]);
    for(i=0;i<n-1;i++)
    {
        p=p*(s-i)/(i+1);
        sum=sum+y[0][i+1]*p;
    }
    printf("\n%f",sum);
    return 0;
}
