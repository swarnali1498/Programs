#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i;
    printf("\nEnter n:");
    scanf("%d",&n);
    float x[n],y[n];
    printf("\nEnter x and y:");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    float sumx=0,sumy=0,meanx,meany;
    for(i=0;i<n;i++)
    {
        sumx=sumx+x[i];
        sumy=sumy+y[i];
    }
    meanx=sumx/n;
    meany=sumy/n;
    sumx=0;
    sumy=0;
    for(i=0;i<n;i++)
    {
        sumx=sumx+pow((x[i]-meanx),2);
        sumy=sumy+pow((y[i]-meany),2);
    }
    float sdx,sdy,sum=0;
    sdx=sqrt(sumx/n);
    sdy=sqrt(sumy/n);
    for(i=0;i<n;i++)
    {
        sum=sum+(x[i]-meanx)*(y[i]-meany);
    }
    float cov,r,byx;
    cov=sum/n;
    r=cov/(sdx*sdy);
    byx=(r*sdy)/sdx;
    printf("\ny-%f=%f(x-%f)",meany,byx,meanx);
    return 0;
}
