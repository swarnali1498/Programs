#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
        int data;
        struct node *link;
}N;
N* create()
{
    N* nu;
    int v;
    printf("\nEnter element to be inserted : ");
    scanf("%d",&v);
    nu=(N*)malloc(sizeof(N));
    nu->data=v;
    nu->link=NULL;
    return nu;
}
void display(N* start)
{
    N* ptr;
    for(ptr=start; ptr!=NULL; ptr=ptr->link)
        printf("%d ",ptr->data);
    printf("\n");
}
N* reverse(N* ptr, N* cur, N* prev)
{
    if(ptr==NULL)
        return prev;
    ptr=cur->link;
    cur->link=prev;
    prev=cur;
    cur=ptr;
    reverse(ptr,cur,prev);
}
int main()
{
    N *nu,*start=NULL,*ptr;
    int i,n;
    printf("\nEnter number of elements in linklist : ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        if(start==NULL)
            start=create();
        else
        {
            nu=create();
            for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
            ptr->link=nu;
        }
    }
    printf("\nOriginal linklist : ");
    display(start);
    start=reverse(start,start,NULL);
    printf("\nReversed linklist : ");
    display(start);
    return 0;
}
