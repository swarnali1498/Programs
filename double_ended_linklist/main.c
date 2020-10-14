#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right,*left;
}N;
N* create();
void createlist(N**,N**);
void insert_front(N**,N**);
void insert_end(N**,N**);
void insert_pos(N**,N**);
void delete_front(N**,N**);
void delete_end(N**,N**);
void delete_pos(N**,N**);
void display(N**);
int count(N**);
int main()
{
    int a;
    N* head=NULL,*tail=NULL;
    while(1)
    {
        printf("\nEnter 1/2/3/4/5/6/7/8/9 for creating list, inserting element at front, end, given position, deleting element from front, end, given position, display and exit : ");
        scanf("%d",&a);
        switch(a)
        {
            case 1: createlist(&head,&tail);
                    break;
            case 2: insert_front(&head,&tail);
                    break;
            case 3: insert_end(&head,&tail);
                    break;
            case 4: insert_pos(&head,&tail);
                    break;
            case 5: delete_front(&head,&tail);
                    break;
            case 6: delete_end(&head,&tail);
                    break;
            case 7: delete_pos(&head,&tail);
                    break;
            case 8: display(&head);
                    break;
            case 9: exit(0);
                    break;
            default: printf("\nWrong choice");
        }
    }
}
N* create()
{
    int v;
    printf("\nEnter data : ");
    scanf("%d",&v);
    N* nu=(N*)malloc(sizeof(N));
    nu->left=nu->right=NULL;
    nu->data=v;
}
void createlist(N** head,N** tail)
{
    int n,i;
    N *nu,*ptr;
    printf("\nEnter number of elements to be entered : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        nu=create();
        if(*head==NULL)
            *head=*tail=nu;
        else
        {
            (*tail)->right=nu;
            nu->left=*tail;
            *tail=(*tail)->right;
            (*tail)->right=NULL;
        }
    }
}
void display(N** head)
{
    N* ptr;
    if(*head==NULL)
        printf("\nList is empty");
    else
    {
        for(ptr=*head;ptr!=NULL;ptr=ptr->right)
            printf("%d ",ptr->data);
    }
}
int count(N** head)
{
    int c=0;
    N* ptr;
    for(ptr=*head;ptr!=NULL;ptr=ptr->right)
        c++;
    return c;
}
void insert_front(N** head,N** tail)
{
     N* nu;
     nu=create();
     if(*head==NULL)
         *head=*tail=nu;
     else
     {
         nu->right=*head;
         (*head)->left=nu;
         *head=nu;
     }
}
void insert_end(N** head,N** tail)
{
     N* nu;
     nu=create();
     if(*head==NULL)
         *head=*tail=nu;
     else
     {
         (*tail)->right=nu;
         nu->left=*tail;
         *tail=nu;
     }
}
void insert_pos(N** head,N** tail)
{
     int p,i=1;
     N *nu,*prev=*head,*ptr=*head;
     printf("\nEnter position : ");
     scanf("%d",&p);
     if(*head==NULL)
         *head=*tail=nu;
     if(p>(count(head)+1))
     {
         printf("\nNot possible");
         return;
     }
     else if(p==1)
        insert_front(head,tail);
     else if(p==(count(head)+1))
        insert_end(head,tail);
     else
     {
         nu=create();
         while(i<=p)
         {
             i++;
             prev=ptr;
             ptr=ptr->right;
             if(i==p)
                break;
         }
         nu->right=ptr;
         ptr->left=nu;
         nu->left=prev;
         prev->right=nu;
     }
}
void delete_front(N** head,N** tail)
{
    N* ptr;
    ptr=*head;
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if(count(head)==2)
    {
        *head=(*head)->right;
        (*head)->right=NULL;
        (*head)->left=NULL;
        *tail=*head;
        printf("\nDeleted element is %d",ptr->data);
        free(ptr);
    }
    else if(count(head)==1)
    {
        printf("\nDeleted element is %d",ptr->data);
        *head=*tail=NULL;
    }
    else
    {
        printf("\nDeleted element is %d",ptr->data);
        *head=(*head)->right;
        (*head)->left=NULL;
        free(ptr);
    }
}
void delete_end(N** head,N** tail)
{
    N* ptr;
    ptr=*tail;
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    else if(count(head)==2)
    {
        *tail=(*tail)->left;
        (*tail)->right=NULL;
        (*tail)->left=NULL;
        *head=*tail;
        printf("\nDeleted element is %d",ptr->data);
        free(ptr);
    }
    else if(count(head)==1)
    {
        printf("\nDeleted element is %d",ptr->data);
        *head=*tail=NULL;
    }
    else
    {
        printf("\nDeleted element is %d",ptr->data);
        *tail=(*tail)->left;
        (*tail)->right=NULL;
        free(ptr);
    }
}
void delete_pos(N** head,N** tail)
{
     int p,i=1;
     N *prev=*head,*ptr=*head;
     printf("\nEnter position : ");
     scanf("%d",&p);
     if(*head==NULL)
     {
         printf("\nList is empty");
         return;
     }
     if(p>count(head))
     {
         printf("\nNot possible");
         return;
     }
     else if(p==1)
        delete_front(head,tail);
     else if(p==(count(head)+1))
        delete_end(head,tail);
     else
     {
         while(i<=p)
         {
             i++;
             prev=ptr;
             ptr=ptr->right;
             if(i==p)
                break;
         }
         printf("\nDeleted element is %d",ptr->data);
         prev->right=ptr->right;
         (ptr->right)->left=prev;
         free(ptr);
     }
}
