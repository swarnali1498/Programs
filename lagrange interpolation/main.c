#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("\nEnter number of data points :");
    scanf("%d",&n);
    float a[n],d[n],x,p=1,sum1=0;
    printf("\nEnter data points :");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&a[i],&d[i]);
    }
    printf("\nEnter interpolating point: ");
    scanf("%f",&x);
    for(i=0;i<n;i++)
    {
        p=1;
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                p=p*((x-a[j])/(a[i]-a[j]));
            }
        }
        sum1=sum1+p*d[i];
    }
    printf("\n%f",sum1);
    return 0;
}
