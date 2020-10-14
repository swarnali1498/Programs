#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}N;
N* create(int v)
{
    N* nu;
    nu=(N*)malloc(sizeof(N));
    nu->data=v;
    nu->link=NULL;
    return nu;
}
int count(N** tail)
{
    int c=0;
    N* ptr;
    for(ptr=(*tail)->link;ptr!=*tail;ptr=ptr->link)
        c++;
    return ++c;
}
void createlist(N** tail)
{
    int n,i,v;
    N* nu,*ptr;
    printf("\nEnter number of nodes to be created : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter data : ");
        scanf("%d",&v);
        nu=create(v);
        if(*tail==NULL)
        {
            *tail=nu;
            nu->link=*tail;
        }
        else
        {
            ptr=(*tail)->link;
            (*tail)->link=nu;
            nu->link=ptr;
            *tail=nu;
        }
    }
}
void display(N** tail)
{
    if(*tail==NULL)
    {
        printf("\nList is empty");
        return;
    }
    N* ptr=(*tail)->link;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }while(ptr!=(*tail)->link);
}
void insert_beg(N** tail)
{
    N *nu,*ptr;
    int v;
    printf("\nEnter value : ");
    scanf("%d",&v);
    nu=create(v);
    if(*tail==NULL)
    {
        *tail=nu;
        nu->link=*tail;
    }
    else
    {
        ptr=(*tail)->link;
        (*tail)->link=nu;
        nu->link=ptr;
    }
}
void insert_end(N** tail)
{
    N *nu,*ptr;
    int v;
    printf("\nEnter value : ");
    scanf("%d",&v);
    nu=create(v);
    if(*tail==NULL)
    {
        *tail=nu;
        nu->link=*tail;
    }
    else
    {
        ptr=(*tail)->link;
        (*tail)->link=nu;
        nu->link=ptr;
        *tail=nu;
    }
}
void insert_any_pos(N** tail)
{
    N *nu,*ptr,*prev;
    int v,p,i=1;
    printf("\nEnter position : ");
    scanf("%d",&p);
    if(p>count(tail)+1)
    {
        printf("\nNot possible");
        return;
    }
    if(*tail==NULL)
    {
        *tail=nu;
        nu->link=*tail;
    }
    else
    {
        if(p==1)
            insert_beg(tail);
        else if(p==count(tail)+1)
            insert_end(tail);
        else
        {
            printf("\nEnter data : ");
            scanf("%d",&v);
            nu=create(v);
            ptr=prev=(*tail)->link;
            while(ptr!=*tail)
            {
                i++;
                prev=ptr;
                ptr=ptr->link;
                if(i==p)
                    break;
            }
            prev->link=nu;
            nu->link=ptr;
        }
    }
}
void delete_beg(N** tail)
{
    N* ptr;
    if(*tail==NULL)
    {
        printf("List is empty");
        return;
    }
    if(count(tail)==1)
    {
        printf("\nDeleted element is %d ",(*tail)->data);
        *tail=NULL;
        return;
    }
    if(count(tail)==2)
    {
        ptr=(*tail)->link;
        (*tail)->link=*tail;
        printf("\nDeleted element is %d",ptr->data);
        free(ptr);
        return;
    }
    ptr=(*tail)->link;
    (*tail)->link=ptr->link;
    printf("\nDeleted element is %d",ptr->data);
    free(ptr);
}
void delete_end(N** tail)
{
    N* ptr,*prev;
    if(*tail==NULL)
    {
        printf("\nList is empty");
        return;
    }
    if((*tail)->link==*tail)
    {
        printf("\nDeleted element is %d ",(*tail)->data);
        *tail=NULL;
        return;
    }
    if(count(tail)==2)
    {
        ptr=*tail;
        printf("\nDeleted element is %d",ptr->data);
        *tail=(*tail)->link;
        (*tail)->link=*tail;
        free(ptr);
        return;
    }
    for(ptr=*tail;ptr->link!=*tail;ptr=ptr->link);
    prev=*tail;
    printf("\nDeleted element is %d",prev->data);
    *tail=ptr;
    ptr->link=prev->link;
    free(prev);
}
void delete_any_pos(N** tail)
{
    int p,i=1;
    N* ptr,*prev;
    if(*tail==NULL)
    {
        printf("\nList is empty");
        return;
    }
    if((*tail)->link==*tail)
    {
        printf("\nDeleted element is %d ",(*tail)->data);
        *tail=NULL;
        return;
    }
    printf("\nEnter position : ");
    scanf("%d",&p);
    if(p==1)
        delete_beg(tail);
    else if(p==count(tail))
    {
        printf("%d",count(tail));
        delete_end(tail);
    }
    else if(p>count(tail))
    {
        printf("\nNot possible");
        return;
    }
    else
    {
        ptr=prev=(*tail)->link;
        while(ptr!=*tail)
        {
            i++;
            prev=ptr;
            ptr=ptr->link;
            if(i==p)
                break;
        }
        printf("\nDeleted element is %d",ptr->data);
        prev->link=ptr->link;
        free(ptr);
    }
}
int main()
{
    int a,p;
    N* tail=NULL;
    while(1)
    {
        printf("\nEnter 1/2/3/4/5/6/7/8/9 for creating the list, inserting element at beg, tail, given position, deleting from beg, tail, given position, display and exit : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1: createlist(&tail);
                    break;
            case 2: insert_beg(&tail);
                    break;
            case 3: insert_end(&tail);
                    break;
            case 4: insert_any_pos(&tail);
                    break;
            case 5: delete_beg(&tail);
                    break;
            case 6: delete_end(&tail);
                    break;
            case 7: delete_any_pos(&tail);
                    break;
            case 8: display(&tail);
                    break;
            case 9: exit(0);
                    break;
            default: printf("\nWrong choice");
        }
    }
    return 0;
}
