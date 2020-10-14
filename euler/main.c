#include <stdio.h>
#include <stdlib.h>

float f(float x,float y)
{
    return x*y;
}
int main()
{
    float h,x0,y0,xn,yn;
    printf("\nEnter step size,initial value of x,y and final value of x: ");
    scanf("%f%f%f%f",&h,&x0,&y0,&xn);
    int i;
    float n=((xn-x0)/h);
    float x,y=y0;
    for(i=1;i<=n;i++)
    {
        y=y+h*f(x,y);
        x=x0+i*h;
        printf("\n%f",y);
    }
    return 0;
}
