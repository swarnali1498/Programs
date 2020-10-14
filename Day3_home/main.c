#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}N;
N* createlist(N*);
void count(N*);
N* reverse(N*);
void display(N*);
int main()
{
    int n,c;
    N* start=NULL;
    while(1)
    {
        printf("\nEnter 1/2/3/4/5 for creating linklist, count number of nodes, reverse the linklist, display and exit : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: start=createlist(start);
                    break;
            case 2: count(start);
                    break;
            case 3: start=reverse(start);
                    break;
            case 4: display(start);
                    break;
            case 5: exit(0);
                    break;
            default: printf("\nWrong choice");
        }
    }
    return 0;
}
N* createlist(N* start)
{
    int v=1;     N* nu,*ptr;
    printf("\nEnter elements in linklist [0 for exit]");
    while(v!=0)
    {
        printf("\nEnter element : ");
        scanf("%d",&v);
        if(v!=0)
        {
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
    }
    return start;
}
void count(N* start)
{
    int c=0;   N* ptr;
    for(ptr=start; ptr!=NULL; ptr=ptr->link)
        c++;
    printf("\nNumber of nodes in linklist is %d",c);
    return c;
}
N* reverse(N* start)
{
  N* ptr,*prev,*cur;
  cur=start;
  prev=NULL;
  if(start==NULL)
    printf("\nList is empty");
  else
  {
      while(cur!=NULL)
      {
          ptr=cur->link;
          cur->link=prev;
          prev=cur;
          cur=ptr;
      }
      start=prev;
  }
}
void display(N* start)
{
    N* ptr;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    for(ptr=start;ptr!=NULL;ptr=ptr->link)
        printf("%d ",ptr->data);
}
