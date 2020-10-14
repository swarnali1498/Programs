#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}N;
N* createlist(N*);
void sort(N*);
void display(N*);
N* insert_sort(N*);
int main()
{
    N* start=NULL;
     start=createlist(start);
    display(start);
    sort(start);
   // start=insert_sort(start);
    display(start);
    return 0;
}
N* insert_sort(N* start)
{
    int v=1;     N* nu,*ptr;
    printf("\nEnter elements in linklist [0 for exit]");
    while(1)
    {
        printf("\nEnter element : ");
        scanf("%d",&v);
        if(v==0)
        break;
        nu=(N*)malloc(sizeof(N));
        nu->link=NULL;
        nu->data=v;
        if(start==NULL)
        {
            start=nu;
        }
        else
        {
            N* prev;
            ptr=prev=start;
            while(ptr!=NULL)
            {
                if(v<ptr->data)
                break;
                prev=ptr;
                ptr=ptr->link;
            }
            if(ptr==start)
            {
                nu->link=start;
                start=nu;
            }
            else
            {
                prev->link=nu;
                nu->link=ptr;
            }
        }
    }
    return start;
}
N* createlist(N* start)
{
    int v=1;     N* nu,*ptr;
    printf("\nEnter elements in linklist [0 for exit]");
    while(1)
    {
        printf("\nEnter element : ");
        scanf("%d",&v);
        if(v==0)
        break;
        nu=(N*)malloc(sizeof(N));
        nu->link=NULL;
        nu->data=v;
        if(start==NULL)
            start=nu;
        else
        {
            for(ptr=start; ptr->link!=NULL; ptr=ptr->link);
            ptr->link=nu;
        }
    }
    return start;
}
void sort(N* start)
{
    int n=0,i,j;
    N *ptr,*ptr1,*prev;
    for(ptr=start;ptr!=NULL;ptr=ptr->link)
        n++;
    //printf("%d",n);
    ptr=prev=ptr1=start;
    for(i=0;i<n;i++)
    {
        ptr1=start->link;
        prev=start;
        for(j=0;j<n-1-i;j++)
        {
            if(prev->data>ptr1->data)
            {
                int temp=prev->data;
                prev->data=ptr1->data;
                ptr1->data=temp;
               //     printf("\n%d %d \n",prev->data,ptr1->data);
            }
            prev=ptr1;
            ptr1=ptr1->link;
        }
        ptr=ptr->link;
    }
}
void display(N* start)
{
    N* ptr;
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        for(ptr=start;ptr!=NULL;ptr=ptr->link)
            printf("%d ",ptr->data);
    }
    printf("\n");
}
