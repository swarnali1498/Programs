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
    int i,c=0;
    float n=((xn-x0)/h);
    float x,y=y0,y1;
    float y2=y0,x2=x0;
    for(i=1;i<=n;i++)
    {
        x=x0+i*h;
        y=y2+h*f(x2,y2);
        y1=y2+(h/2)*(f(x2,y2)+f(x,y));
        //printf("\n%f",y1);
        while(fabs(y1-y)>0.0001)
        {
            y=y1;
            y1=y2+(h/2)*(f(x2,y2)+f(x,y));
        }
        printf("\n%f",y1);
        y2=y1;
        x2=x;
    }
    return 0;
}
