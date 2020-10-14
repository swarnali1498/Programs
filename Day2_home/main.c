#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coef,exp;
    struct polynomial *link;
}poly;
poly* create(poly*);
poly* mul(poly*,poly*,poly*);
void display(poly*);
int main()
{
    poly *s1,*s2,*s3;
    s1=s2=s3=NULL;
    s1=create(s1);
    s2=create(s2);
    s3=mul(s1,s2,s3);
    printf("\nFirst polynomial : ");
    display(s1);
    printf("\nSecond polynomial : ");
    display(s2);
    printf("\nResultant polynomial : ");
    display(s3);
    return 0;
}
poly* create(poly* start)
{
    int v;
    poly *nu,*ptr;
    while(1)
    {
        nu=(poly*)malloc(sizeof(poly));
        printf("\nEnter coefficient [0 to exit] : ");
        scanf("%d",&v);
        if(v==0)
            break;
        nu->coef=v;
        printf("\nEnter exponent : ");
        scanf("%d",&v);
       // printf("\nABC");
        nu->exp=v;

        nu->link=NULL;
         //printf("\nABC");
        if(start==NULL)
            start=nu;
        else
        {
            for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
            ptr->link=nu;
        }
    }
    return start;
}
poly* mul(poly* s1, poly* s2, poly* s3)
{
    int c,e,k=0;
    poly *nu,*ptr1,*ptr2,*ptr3,*prev;
    ptr1=s1;
    ptr2=s2;
    while(ptr1!=NULL)
    {
        ptr2=s2;
        while(ptr2!=NULL)
        {
            nu=(poly*)malloc(sizeof(poly));
            nu->link=NULL;
            c=ptr1->coef*ptr2->coef;
            e=ptr1->exp+ptr2->exp;
            if(s3==NULL)
            {
                nu->coef=c;
                nu->exp=e;
                s3=nu;
            }
            else
            {
                k=0;
                for(ptr3=s3; ptr3!=NULL; ptr3=ptr3->link)
                {
                    if(e==ptr3->exp)
                    {
                        k=1;
                        ptr3->coef=ptr3->coef+c;
                    }
                }
                if(k==0)
                {
                    nu->coef=c;
                    nu->exp=e;
                    prev=ptr3=s3;
                    while(ptr3!=NULL)
                    {
                        if(ptr3->exp<e)
                            break;
                        prev=ptr3;
                        ptr3=ptr3->link;
                    }
                    if(s3==ptr3 && ptr3->exp<e)
                    {
                        nu->link=ptr3;
                        s3=nu;
                    }
                    else
                    {
                        prev->link=nu;
                        nu->link=ptr3;
                    }
                }
            }
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return s3;
}
void display(poly* start)
{
    poly* ptr;
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        for(ptr=start;ptr!=NULL;ptr=ptr->link)
        {
            printf("%dx^%d",ptr->coef,ptr->exp);
            if(ptr->link!=NULL)
                printf(" + ");
        }
        printf("\n");
    }
}
