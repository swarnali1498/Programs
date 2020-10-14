#include <stdio.h>
#include <stdlib.h>
float f(float x)
{
    return (1/x);
}
int main()
{
    float x0,xn,x;
    int n;
    printf("\nEnter values of x0,xn,n:");
    scanf("%f%f%d",&x0,&xn,&n);
    float h=(xn-x0)/n;
    float sum1=0,sum2=0;
    int i;
    for(i=1;i<n;i=i+2)
    {
        x=x0+i*h;
        sum1=sum1+f(x);
    }
    for(i=2;i<n;i=i+2)
    {
        x=x0+i*h;
        sum2=sum2+f(x);
    }
    float yn;
    yn=(h/3)*(f(x0)+f(xn)+4*sum1+2*sum2);
    printf("\n%f",yn);
    return 0;
}
