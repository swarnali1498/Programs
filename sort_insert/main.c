#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}N;
N* createlist(N*);
N* create(int);
N* insert_at_pos(N*,int,int);
N* del_at_beg(N*);
N* del_at_end(N*);
N* del_at_pos(N*,int);
void display(N*);
int main()
{
    int a,p,c,v;
    N* start=NULL,*ptr;
    start=createlist(start);
    while(1)
    {
        c=1;
        printf("\nEnter 1/2/3/4/5/6 for insertion, deletion at beg, end, any intermediate position, display and exit : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1: printf("\nEnter inserting element : ");
                    scanf("%d",&v);
                    ptr=start;
                    while(ptr!=NULL)
                    {
                        if(v<ptr->data)
                            break;
                        ptr=ptr->link;
                        c++;
                    }
                    start=insert_at_pos(start,c,v);
                    break;
            case 2: start=del_at_beg(start);
                    break;
            case 3: start=del_at_end(start);
                    break;
            case 4: printf("\nEnter position : ");
                    scanf("%d",&p);
                    start=del_at_pos(start,p);
                    break;
            case 5: display(start);
                    break;
            case 6: exit(0);
                    break;
            default: printf("\nWrong choice");
        }
    }
    return 0;
}
N* createlist(N* start)
{
    int n,i=0,v;
    N *ptr;
    printf("\nEnter number of elements in list : ");
    scanf("%d",&n);
    while(i!=n)
    {
        i++;
        printf("\nEnter element : ");
        scanf("%d",&v);
        if(i==1)
        {
            start=create(v);
            ptr=start;
        }
        else
        {
            ptr->link=create(v);
            ptr=ptr->link;
        }
    }
    return start;
}
N* create(int v)
{
    N* nu;
    nu=(N*)malloc(sizeof(N));
    nu->data=v;
    nu->link=NULL;
    return nu;
}
N* insert_at_pos(N* start,int p,int v)
{
    N *nu,*ptr,*prev;
    if(p==1)
    {
        nu=create(v);
        if(start==NULL)
            start=nu;
        else
        {
            nu->link=start;
            start=nu;
        }
    }
    else
    {
        ptr=prev=start;
        nu=create(v);
        int c=0;
        while(ptr!=NULL)
        {
            c++;
            if(c==p)
            break;
            prev=ptr;
            ptr=ptr->link;
        }
        if(p>(c+1))
        {
            printf("\nNot possible");
            return;
        }
        prev->link=nu;
        nu->link=ptr;
    }
    return start;
}
N* del_at_beg(N* start)
{
    N* ptr;
    ptr=start;
    if(ptr->link==NULL)
       start=NULL;
    else
       start=start->link;
    printf("\nDeleted element is %d",ptr->data);
    free(ptr);
    return start;
}
N* del_at_end(N* start)
{
    N* ptr,*prev;
    ptr=prev=start;
    if(ptr->link==NULL)
    {
        printf("\nDeleted element is %d",ptr->data);
        start=NULL;
        return start;
    }
    while(ptr->link!=NULL)
    {
        prev=ptr;
        ptr=ptr->link;
    }
    prev->link=NULL;
    printf("\nDeleted element is %d",ptr->data);
    free(ptr);
    return start;
}
N* del_at_pos(N* start,int p)
{
    N* ptr,*prev;
    if(p==1)
        start=del_at_beg(start);
    else
    {
        ptr=prev=start;
        int c=0;
        while(ptr->link!=NULL)
        {
            c++;
            if(c==p)
            break;
            prev=ptr;
            ptr=ptr->link;
        }
        if(p>c)
        {
            printf("\nNot possible");
            return;
        }
        prev->link=ptr->link;
        printf("\nDeleted element is %d",ptr->data);
        free(ptr);
    }
    return start;
}
void display(N* start)
{
    N* ptr;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    for(ptr=start; ptr!=NULL; ptr=ptr->link)
        printf("%d ",ptr->data);
}
