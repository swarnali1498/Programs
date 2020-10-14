#include <stdio.h>
#include <stdlib.h>
int find_qr(int p,int q,int r,int c,int n)
{
    int max=1;
   // printf("\n%d %d %d",p,q,r);
    if(r==0)
        return c;
    if(p>q)
    {
        if(p>r)
            max=p;
        else
            max=r;
    }
    else
    {
        if(q>r)
            max=q;
        else
            max=r;
    }

    if((p==q && p!=max) || (q==r && q!=max) || (p==r && p!=max) || (p!=q && q!=r && p!=r))
    {
        c++;
     //   printf("\n(print) %d %d %d",p,q,r);
    }
    q++;
    r--;
    find_qr(p,q,r,c,n);
}
int find_p(int p,int c,int n)
{
    if(p==n-1)
    return c;
    c=find_qr(p,1,n-(p+1),c,n);
    p++;
    find_p(p,c,n);
}
int main()
{
    int n,t,c;
    printf("\nEnter n and t : ");
    scanf("%d%d",&n,&t);
    if(n<1 || n>1000 || t<1 || t>100)
    {
        return;
    }
    while(t!=0)
    {
        c=find_p(1,0,n);
        printf("\n%d",c);
        t--;
    }
    return 0;
}
