#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float func(float x)
{
    return pow(x,4)-x-10;
}
int main()
{
    float a=0,b=1,x,x1;
    while(func(a)*func(b)>0)
    {
        a++;
        b++;
    }
    x=(a*func(b)-b*func(a))/(func(b)-func(a));
    if(func(x)*func(a)>0)
    {
        a=x;
    }
    else
    {
        b=x;
    }
    printf("\n%f",x);
    x1=(a*func(b)-b*func(a))/(func(b)-func(a));
    while(fabs(x-x1)>0.00001)
    {
        x=x1;
        if(func(x)*func(a)>0)
        {
            a=x;
        }
        else
        {
            b=x;
        }
        printf("\n%f",x);
        x1=(a*func(b)-b*func(a))/(func(b)-func(a));
    }
    printf("\n%f",x1);
    return 0;
}
