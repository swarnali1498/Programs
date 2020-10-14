#include <stdio.h>
#include <stdlib.h>
long int fact(int size)
{
    long int p=1,i;
    for(i=1;i<=size;i++)
    {
        p=(p*i)%1000000007;
    }
    return p;
}
long int compute(long int p,int st,int size,int size1,int n)
{
    int i;
   // if(size==size1)
     //   printf("%d ",st);
    if(st>n)
        return p;
    if(size==1)
    {
       // printf("  size1=%d,p=%ld  ",size1,p);
        p=(p+fact(size1));
       // printf("   p=%d    \n",p);
        return p;
    }
    for(i=st+2;i<=n;i++)
    {
       // printf(" %d ",i);
        p=compute(p,i,size-1,size1,n);
    }
    return p;
}
int main()
{
    int n,i,j,size;
    long int p;
    printf("\nEnter n:");
    scanf("%d",&n);
    p=n;
    if(n>=1 && n<=2000)
    {
        if(n%2==0)
            size=n/2;
        else
            size=n/2+1;
        for(i=1;i<=n;i++)
        {
            for(j=2;j<=size;j++)
            {
                p=compute(p,i,j,j,n);
                //printf("\nMAIN: p=%ld",p);
            }
            if(i%2!=0 && n%2!=0)
            {
                size--;
            }
            else if(i%2==0 && n%2==0)
            {
                size--;
            }
        }
        printf("%ld",p);
    }
    return 0;
}
