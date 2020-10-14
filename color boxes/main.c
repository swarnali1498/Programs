#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,m,i,p=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        p=p*i;
    }
    printf("%d",p);
}
