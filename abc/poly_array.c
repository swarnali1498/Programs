typedef struct polynomial
{
    int coeff,exp;
}poly;
void create()
{
    int i,j,k,t1,t2;
    poly *p1,*p2,*p3;
    printf("\nEnter number of terms of first polynomial : ");
    scanf("%d",&t1);
    printf("\nEnter number of terms of second polynomial : ");
    scanf("%d",&t2);
    p1=(poly*)malloc(t1*sizeof(poly));
    p2=(poly*)malloc(t2*sizeof(poly));
    p3=(poly*)malloc((t1+t2)*sizeof(poly));
    printf("\nEnter coefficients and exponents of first polynomial : ");
    for(i=0; i<t1; i++)
    {
        scanf("%d%d",&p1[i].coeff,&p1[i].exp);
    }
    printf("\nEnter coefficients and exponents of second polynomial : ");
    for(i=0; i<t2; i++)
    {
        scanf("%d%d",&p2[i].coeff,&p2[i].exp);
    }
    i=0,j=0,k=0;
    while(i<t1 && j<t2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].exp=p1[i].exp;
            i++; j++; k++;
        }
        else if(p1[i].exp>p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].exp=p1[i].exp;
            i++; k++;
        }
        else if(p1[i].exp<p2[j].exp)
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].exp=p2[j].exp;
            j++; k++;
        }
    }
    while(i<t1)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].exp=p1[i].exp;
        i++; k++;
    }
    while(j<t2)
    {
        p3[k].coeff=p2[j].coeff;
        p3[k].exp=p2[j].exp;
        j++; k++;
    }
    k--;
    p3=(poly*)realloc(p3,(k+1)*sizeof(poly));
    printf("\nFirst polynomial : ");
    for(i=0;i<t1;i++)
    {
        if(p1[i].exp==0)
        printf("%d",p1[i].coeff);
        else if(p1[i].exp==1)
        printf("%dx",p1[i].coeff);
        else
        printf("%dx^%d",p1[i].coeff,p1[i].exp);
        if(i!=(t1-1))
            printf(" + ");
    }
    printf("\n");
    printf("\nSecond polynomial : ");
    for(i=0;i<t2;i++)
    {
        if(p2[i].exp==0)
        printf("%d",p2[i].coeff);
        else if(p2[i].exp==1)
        printf("%dx",p2[i].coeff);
        else
        printf("%dx^%d",p2[i].coeff,p2[i].exp);
        if(i!=(t2-1))
            printf(" + ");
    }
    printf("\n");
    printf("\nResultant added polynomial : ");
    for(i=0;i<(k+1);i++)
    {
        if(p3[i].exp==0)
        printf("%d",p3[i].coeff);
        else if(p3[i].exp==1)
        printf("%dx",p3[i].coeff);
        else
        printf("%dx^%d",p3[i].coeff,p3[i].exp);
        if(i!=k)
            printf(" + ");
    }
    printf("\n");
}
