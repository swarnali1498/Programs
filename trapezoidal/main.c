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
    float sum=0;
    int i;
    for(i=1;i<n;i=i+1)
    {
        x=x0+i*h;
        sum=sum+f(x);
    }
    float yn;
    yn=(h/2)*(f(x0)+f(xn)+2*sum);
    printf("\n%f",yn);
    return 0;
}
