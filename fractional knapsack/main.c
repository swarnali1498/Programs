#include <stdio.h>
#include <stdlib.h>
typedef struct item
{
    int w,b;
}item;
void max_heapify(item* a,int n,int i)
{
    int l,r,max;
    l=2*i+1;
    r=2*i+2;
    if(l<n && (a[l].b/a[l].w)>(a[i].b/a[i].w))
    {
        max=l;
    }
    else
    {
        max=i;
    }
    if(r<n && (a[r].b/a[r].w)>(a[max].b/a[max].w))
    {
        max=r;
    }
    if(max!=i)
    {
        item t;
        t=a[i];
        a[i]=a[max];
        a[max]=t;
        max_heapify(a,n,max);
    }
}
item extract_max(item* a,int n)
{
    item t;
    t=a[0];
    a[0]=a[n-1];
    a[n-1]=t;
    n--;
    max_heapify(a,n,0);
    return t;
}
int main()
{
    int n,i,cap;
    float ben=0;
    item t;
    printf("\nEnter number of items and capacity of bag: ");
    scanf("%d%d",&n,&cap);
    item* a=(item*)malloc(n*sizeof(item));
    printf("\nEnter benefits and weights of items: ");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].b,&a[i].w);
    }
    for(i=n/2;i>=0;i--)
    {
        max_heapify(a,n,i);
    }
    while(1)
    {
        t=extract_max(a,n);
        n--;
        if(cap-t.w<0)
            break;
        cap=cap-t.w;
        ben=ben+t.b;
    }
    ben=ben+cap*(t.b/t.w);
    printf("\nMaximum benefit is %f",ben);
    return 0;
}
