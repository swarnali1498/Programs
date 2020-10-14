#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float func(float x)
{
    return (pow(x,4)-x-10);
}
float func1(float x)
{
    return (4*pow(x,3)-1);
}
int main()
{
    int a=0,b=1;
    while(func(a)*func(b)>0)
    {
        a++;
        b++;
    }
    printf("\na=%d,b=%d",a,b);
    float x=b,x1;
    x1=x-(func(x)/func1(x));
    printf("\n%f %f %f",x1,x,func(x)/func1(x));
    //printf("\n%f",x1);
    while(fabs(x-x1)>0.00001)
    {
        x=x1;
        printf("\n%f",x);
        x1=x-(func(x)/func1(x));
    }
    printf("\n%f",x1);
    return 0;
}

