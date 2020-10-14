#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial
{
    int coef,exp;
}poly;
void display(poly* p,int l)
{
    int i;
    for(i=0;i<l;i++)
    {
        printf("%dx^%d",p[i].coef,p[i].exp);
        if(i!=l-1)
            printf(" + ");
    }
    printf("\n");
}
int main()
{
    int i=0,c,l1,l2;
    poly *p1,*p2,*p3,*p4,*p;
    p1=(poly*)malloc(20*sizeof(poly));
    p2=(poly*)malloc(20*sizeof(poly));
    p3=(poly*)malloc(20*sizeof(poly));
    p4=(poly*)malloc(20*sizeof(poly));
    printf("\nEnter dividend : ");
    while(1)
    {
        printf("\nEnter coefficient(0 for exit) : ");
        scanf("%d",&c);
        if(c==0)
            break;
        p1[i].coef=c;
        printf("\nEnter exponent : ");
        scanf("%d",&p1[i].exp);
        i++;
    }
    l1=i;
    i=0;
    p1=(poly*)realloc(p1,l1*sizeof(poly));
    //display(p1,l1);
    printf("\nEnter divisor : ");
    while(1)
    {
        printf("\nEnter coefficient(0 for exit) : ");
        scanf("%d",&c);
        if(c==0)
            break;
        p2[i].coef=c;
        printf("\nEnter exponent : ");
        scanf("%d",&p2[i].exp);
        i++;
    }
    l2=i;
    p2=(poly*)realloc(p2,l2*sizeof(poly));
    //display(p2,l2);
    i=0;
    int j=0,k=0,l=0,diff;
    printf("\nDividend : ");
    display(p1,l1);
    printf("\nDivisor : ");
    display(p2,l2);
    while(i!=l1)
    {
        if(i==0)
        {
            p3[k].exp=p1[i].exp-p2[j].exp;
            p3[k].coef=p1[i].coef/p2[j].coef;
        }
        else
        {
            p=p4;
            printf("\n%d",p[])
            p3[k].exp=p[i].exp-p2[j].exp;
            p3[k].coef=-p[i].coef/p2[j].coef;
        }
        j=0,l=0;
        while(j!=l2)
        {
            if(i==0)
            {
                if(p1[j].exp==p2[j].exp)
                {
                    diff=p1[j].coef-p3[k].coef*p2[j].coef;
                    if(diff!=0)
                    {
                        p4[l].coef=diff;
                        p4[l].exp=p1[j].exp;
                        l++;
                    }
                }
                else
                {
                    if(p1[j].exp>p2[j].exp*p3[k].exp)
                    {
                        p4[l].coef=p1[j].coef;
                        p4[l++].exp=p1[j].exp;
                        p4[l].coef=-p2[j].coef*p3[k].coef;
                        p4[l++].exp=p2[j].exp*p3[k].exp;
                    }
                    else
                    {
                        p4[l].coef=-p2[j].coef*p3[k].coef;
                        p4[l++].exp=p2[j].exp*p3[k].exp;
                        p4[l].coef=p1[j].coef;
                        p4[l++].exp=p1[j].exp;
                    }
                }
            }
            else
            {
             /*   printf("\np : ");
                display(p,l2+1);*/
                diff=p[j].coef-p3[k].coef*p2[j].coef;
                if(diff!=0)
                {
                    p4[l].coef=diff;
                    p4[l].exp=p[j].exp;
                    l++;
                }
            }
            j++;
            if(j==l2-1)
            {
                p4[l].coef=p1[j].coef;
                p4[l].exp=p1[j].exp;
                l++;
            }
        }
        i++;
        k++;
    }
    printf("\nQuotient : ");
    display(p3,k);
    printf("\nRemainder : ");
    display(p4,l);
    return 0;
}
