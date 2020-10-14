#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,y=2,z,a;
    X=(y*=2)+(z=a=y);
    printf("%d",X);
    return 0;
}
