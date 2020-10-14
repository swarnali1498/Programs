/* WRITE A MENU DRIVEN PROGRAM TO IMPLEMENT A SINGLY LINKED LIST WITH THE OPERATIONS:
1.	CREATE THE LIST
2.	INSERT AN ELEMENT IN ANY GIVEN POSITION ( FRONT, END OR INTERMEDIATE )
3.	DELETE AN ELEMENT FROM ANY GIVEN POSITION ( FRONT, END OR INTERMEDIATE )
4.	DISPLAY THE LIST      */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}N;
N* createlist(N*);
N* create(int);
N* insert_at_beg(N*,int);
N* insert_at_end(N*,int);
N* insert_at_pos(N*,int,int);
N* del_at_beg(N*);
N* del_at_end(N*);
N* del_at_pos(N*,int);
void display(N*);
int main()
{
    int a,p,v;
    N* start=NULL;
    start=createlist(start);
    while(1)
    {
        printf("\nEnter 1/2/3/4/5/6/7/8 for insertion at beg, end, any intermediate position, deletion at beg, end, any intermediate position, display and exit : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1: printf("\nEnter inserting element : ");
                    scanf("%d",&v);
                    start=insert_at_beg(start,v);
                    break;
            case 2: printf("\nEnter inserting element : ");
                    scanf("%d",&v);
                    start=insert_at_end(start,v);
                    break;
            case 3: printf("\nEnter inserting element : ");
                    scanf("%d",&v);
                    printf("\nEnter position : ");
                    scanf("%d",&p);
                    start=insert_at_pos(start,p,v);
                    break;
            case 4: start=del_at_beg(start);
                    break;
            case 5: start=del_at_end(start);
                      break;
            case 6: printf("\nEnter position : ");
                    scanf("%d",&p);
                    start=del_at_pos(start,p);
                    break;
            case 7: display(start);
                    break;
            case 8: exit(0);
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
N* insert_at_beg(N* start,int v)
{
    N* nu;
    nu=create(v);
    if(start==NULL)
    start=nu;
    else
    {
        nu->link=start;
        start=nu;
    }
    return start;
}
N* insert_at_end(N* start,int v)
{
    N *nu,*ptr;
    nu=create(v);
    if(start==NULL)
        start=nu;
    else
    {
        for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
        ptr->link=nu;
    }
    return start;
}
N* insert_at_pos(N* start,int p,int v)
{
    N *nu,*ptr,*prev;
    if(p==1)
        start=insert_at_beg(start,v);
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
        while(ptr!=NULL)
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
