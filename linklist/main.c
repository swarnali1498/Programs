#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coeff,exp;
    struct polynomial *link;
}poly;
poly* createlist(poly*);
poly* add(poly*,poly*,poly*);
void display();
int main()
{
    int a;
    poly *s1=NULL;
    poly *s2=NULL;
    poly *s3=NULL;
    while(1)
    {
        printf("\nEnter 1/2/3/4/5 for creating polynomial 1, creating polynomial 2, addition of the 2 polynomials, display of polynomials and exit :");
        scanf("%d",&a);
        switch(a)
        {
            case 1: s1=createlist(s1);
                    break;
            case 2: s2=createlist(s2);
                    break;
            case 3: s3=add(s3,s1,s2);
                    break;
            case 4: printf("\nFirst polynomial : ");
                    display(s1);
                    printf("\nSecond polynomial : ");
                    display(s2);
                    printf("\nResultant added polynomial : ");
                    display(s3);
                    break;
            case 5: exit(0);
                    break;
            default: printf("\nWrong choice");
        }
    }
    return 0;
}
poly* createlist(poly* s1)
{
    int c,e;
    poly *ptr=s1,*nu;
    while(1)
    {
        nu=(poly*)malloc(sizeof(poly));
        printf("\nEnter coefficient (0 for exit)  : ");
        scanf("%d",&c);
        if(c==0)
            break;
        printf("\nEnter exponent : ");
        scanf("%d",&e);
        nu->coeff=c;
        nu->exp=e;
        nu->link=NULL;
        if(s1==NULL)
        {
            s1=nu;
        }
        else
        {
            for(ptr=s1;ptr->link!=NULL;ptr=ptr->link);
            ptr->link=nu;
        }
    }
    return s1;
}
poly* add(poly *s3, poly *s1, poly *s2)
{
    poly *ptr1,*ptr2,*ptr3,*nu;
    ptr1=s1;
    ptr2=s2;
    ptr3=s3;
    while(ptr1!=NULL && ptr2!=NULL)
     {
        nu=(poly*)malloc(sizeof(poly));
        nu->link=NULL;
        if(ptr1->exp==ptr2->exp)
        {
            nu->coeff=ptr1->coeff+ptr2->coeff;
            nu->exp=ptr1->exp;
            if(s3==NULL)
            s3=nu;
            else
            ptr3->link=nu;
            ptr3=nu;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->exp>ptr2->exp)
        {
            nu->coeff=ptr1->coeff;
            nu->exp=ptr1->exp;
            if(s3==NULL)
            s3=nu;
            else
            ptr3->link=nu;
            ptr3=nu;
            ptr1=ptr1->link;
        }
        else if(ptr1->exp<ptr2->exp)
        {
            nu->coeff=ptr2->coeff;
            nu->exp=ptr2->exp;
            if(s3==NULL)
            s3=nu;
            else
            ptr3->link=nu;
            ptr3=nu;
            ptr2=ptr2->link;
        }
     }
    while(ptr1!=NULL)
    {
        nu=(poly*)malloc(sizeof(poly));
        nu->link=NULL;
        nu->coeff=ptr1->coeff;
        nu->exp=ptr1->exp;
        ptr3->link=nu;
        ptr3=nu;
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL)
    {
        nu=(poly*)malloc(sizeof(poly));
        nu->link=NULL;
        nu->coeff=ptr2->coeff;
        nu->exp=ptr2->exp;
        ptr3->link=nu;
        ptr3=nu;
        ptr2=ptr2->link;
    }
    return s3;
}
void display(poly *s)
{
    poly* ptr;
    for(ptr=s;ptr!=NULL;ptr=ptr->link)
    {
        if(ptr->exp==0)
        printf("%d",ptr->coeff);
        else if(ptr->exp==1)
        printf("%dx",ptr->coeff);
        else
        printf("%dx^%d",ptr->coeff,ptr->exp);
        if(ptr->link!=NULL)
            printf(" + ");
    }
    printf("\n");
}


