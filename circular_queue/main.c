#include <stdio.h>
#include <stdlib.h>
int cap,f,r;
int insert(int *ar)
{
    int v;
    if((f-r)==1||(r-f)==cap-1)
    {
        printf("\nCircular queue is filled");
        return;
    }
    printf("\nEnter element to be inserted : ");
    scanf("%d",&v);
    if(f==-1)
        f=r=0;
    else
        r=(r+1)%cap;
    ar[r]=v;
}
void delete(int *ar)
{
    if(f==-1)
    {
        printf("\nCircular queue is empty");
        return;
    }
    printf("\nDeleted element is %d",ar[f]);
    if(f==r)
    {
        f=r=-1;
        return;
    }
    f=(f+1)%cap;
}
void display(int *ar)
{
    int i;
    if(f==-1)
    {
        printf("\nCircular queue is empty");
        return;
    }
    for(i=f; i<=r; i++)
        printf("%d ",ar[i]);
}
int main()
{
    int *ar,n,i,a,v,p;
    printf("\nEnter number of elements in circular queue : ");
    scanf("%d",&n);
    ar=(int*)malloc(n*sizeof(int));
    cap=n;
    f=r=-1;
    while(1)
    {
        printf("\nEnter 1/2/3/4 for insert, delete, display and exit : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1: insert(ar);
                    break;
            case 2: delete(ar);
                    break;
            case 3: display(ar);
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nWrong choice. Enter again : ");
        }
    }
    return 0;
}
