#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coef,exp;
    struct node *link;
}N;
N* create(N*);
N* insert(N*,int,int);
N* add(N*, N*, N*);
void display(N*);
int main()
{
    N* st1=NULL;
    N* st2=NULL;
    N* st3=NULL;
    printf("\nFirst polynomial creation : ");
    st1=create(st1);
    printf("\nSecond polynomial creation : ");
    st2=create(st2);
    st3=add(st1,st2,st3);
    printf("\nFirst polynomial : ");
    display(st1);
    printf("\nSecond polynomial : ");
    display(st2);
    printf("\nResultant added polynomial : ");
    display(st3);
    return 0;
}
N* add(N* st1, N* st2, N* st3)
{
    N* ptr;
    for(ptr=st1; ptr!=NULL; ptr=ptr->link)
    {
        st3=insert(st3,ptr->coef,ptr->exp);
    }
    for(ptr=st2; ptr!=NULL; ptr=ptr->link)
    {
        st3=insert(st3,ptr->coef,ptr->exp);
    }
    return st3;
}
N* create(N* st)
{
    int a,b;
    while(1)
    {
        printf("\nEnter coefficient(0 to exit)");
        scanf("%d",&a);
        if(a==0)
            break;
        printf("\nEnter exponent : ");
        scanf("%d",&b);
        st=insert(st,a,b);
    }
    return st;
}
N* insert(N* st, int a, int b)
{
    N *nu,*ptr,*prev;
    nu=(N*)malloc(sizeof(N));
    nu->coef=a;
    nu->exp=b;
    nu->link=NULL;
    if(st==NULL)
    {
        st=nu;
        return st;
    }
    ptr=prev=st;
    while(ptr!=NULL)
    {
        if(ptr->exp<=nu->exp)
            break;
        prev=ptr;
        ptr=ptr->link;
    }
    if(ptr==NULL)
        prev->link=nu;
    else if(ptr->exp==nu->exp)
        ptr->coef+=nu->coef;
    else if(ptr==st)
    {
        nu->link=st;
        st=nu;
    }
    else
    {
        prev->link=nu;
        nu->link=ptr;
    }
    return st;
}
void display(N* st)
{
    N* ptr;
    for(ptr=st;ptr!=NULL;ptr=ptr->link)
    {
        printf("%dx^%d",ptr->coef,ptr->exp);
        if(ptr->link!=NULL)
            printf(" + ");
    }
    printf("\n");
}
