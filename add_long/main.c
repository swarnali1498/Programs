#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right,*left;
}N;
void list_create(N**,N**,char*,int);
void display(N**);
void add(N**,N**,N**,N**,N**,N**);
N* create(int v)
{
    N *nu;
    nu=(N*)malloc(sizeof(N));
    nu->data=v;
    nu->right=NULL;
    nu->left=NULL;
}
int main()
{
    char a[100],b[100];
    char ch;
    int i,c=0,d=0;
    FILE* fp;
    fp=fopen("Input.txt","r");
    if(fp==NULL)
    {
        printf("\nFile not found");
        return;
    }
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
        if(ch==' ')
            break;
        a[c]=ch;
        c++;
    }
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
        if(ch!=' ')
            b[d]=ch;
            d++;
    }
    N* nu;
    N *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL,*head3=NULL,*tail3=NULL;
    list_create(&head1,&tail1,a,c);
    list_create(&head2,&tail2,b,d);
    printf("\nFirst number : ");
    display(&head1);
    printf("\nSecond number : ");
    display(&head2);
    add(&head1,&tail1,&head2,&tail2,&head3,&tail3);
    printf("\nResultant added number : ");
    display(&head3);
    fclose(fp);
}
void list_create(N** head,N** tail,char* a,int c)
{
    int i=c-1;
    N* nu;
    while(i!=-1)
    {
        int r=((int)a[i])-48;
        i--;
        nu=create(r);
        if(*head==NULL)
            *head=*tail=nu;
        else
        {
            (*head)->left=nu;
            nu->right=*head;
            *head=nu;
        }
    }
}
void display(N** head)
{
    N* ptr=*head;
    if(ptr==NULL)
        printf("\nList is empty");
    else
    {
        for(;ptr!=NULL;ptr=ptr->right)
            printf("%d ",ptr->data);
        printf("\n");
    }
}
void add(N** head1,N** tail1,N** head2,N** tail2,N** head3,N** tail3)
{
    int sum,carry=0,data;
    N *ptr1=*tail1,*ptr2=*tail2,*nu;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        sum=ptr1->data+ptr2->data;
        if(carry==1)
            sum++;
        if(sum>9)
        {
            sum=sum-10;
            carry=1;
        }
        else
        carry=0;
        nu=create(sum);
        if(*head3==NULL)
            *head3=*tail3=nu;
        else
        {
            (*head3)->left=nu;
            nu->right=*head3;
            *head3=nu;
        }
        ptr1=ptr1->left;
        ptr2=ptr2->left;
    }
    while(ptr1!=NULL)
    {
        if(carry==1)
        {
            data=ptr2->data+carry;
            if(data>9)
            {
                data=data-10;
                carry=1;
            }
            else
                carry=0;
            nu=create(data);
        }
        else
            nu=create(ptr1->data);
        (*head3)->left=nu;
        nu->right=*head3;
        *head3=nu;
        ptr1=ptr1->left;
    }
    while(ptr2!=NULL)
    {
        if(carry==1)
        {
            data=ptr2->data+carry;
            if(data>9)
            {
                data=data-10;
                carry=1;
            }
            else
                carry=0;
            nu=create(data);
        }
        else
        {
            nu=create(ptr2->data);
        }
        (*head3)->left=nu;
        nu->right=*head3;
        *head3=nu;
        ptr2=ptr2->left;
    }
    if(carry==1)
    {
        nu=create(carry);
        N* ptr=*tail3;
        for(;ptr->left!=NULL;ptr=ptr->left);
        ptr->left=nu;
        nu->right=ptr;
        *head3=nu;
    }
}
