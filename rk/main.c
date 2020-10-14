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
    float x=x0,y=y0,k1,k2,k3,k4;
    int i,c=0;
    float n=((xn-x0)/h);
    for(i=1;i<=n;i++)
    {
        k1=h*f(x,y);
        k2=h*f(x+h/2,y+k1/2);
        k3=h*f(x+h/2,y+k2/2);
        k4=h*f(x+h,y+k3);
        x=x0+i*h;
        y=y+(k1+2*k2+2*k3+k4)/6;
        printf("\n%f",y);
    }
    return 0;
}
