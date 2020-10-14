#include <stdio.h>
#include <stdlib.h>

int main()
{
    #include<stdio.h>
#include<stdlib.h>
void main()
{
    int t,i,k,l,cost,m,n,x1,y1,x2,y2,p;
    scanf("%d %d",&m,&n);
    if(n<1 || m>1000000)
    return;
    scanf("%d %d",&x1,&y1);
    if(n<0 || m<0)
    return;
    scanf("%d %d",&x2,&y2);
    if(x2>n-1 || y2>m-1)
    return;
    scanf("%d",&p);
    if(p<1 || p>10)
    return;
    int a[m][n];
    k=fabs(x1-x2);
    l=fabs(y1-y2);
    cost =p*(k+l);
    printf("%d\n",cost);
    if(cost<=1000)
    printf("You saved the group");
    else
    printf("Let go of the group");
}
}
