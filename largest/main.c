//MAKE THE LARGEST POSSIBLE NUMBER FROM ARRAY ELEMENTS GIVEN BY USER(ELEMENTS CAN BE OF VARYING SIZES)
#include <stdio.h>
#include <stdlib.h>
void display(int *ar,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");
}
int count_digits(int a)
{
    int r,c=0;
    while(a!=0)
    {
        r=a%10;
        a=a/10;
        c++;
    }
    return c;
}
int divide(int n,int p,int d)
{
    int i=d-1,r;
    while(i>=p)
    {
        r=n%10;
        n=n/10;
        i--;
    }
    return r;
}
void sort(int *ar,int* d,int n,int p)
{
    int j,k;
    j=0;
    while(j<n-1)
    {
        k=j+1;
        if(d[j]>p)
        {
            while(k<n)
            {
                if(d[k]>p)
                {
                    if((divide(ar[j],p,d[j]))<(divide(ar[k],p,d[k])))
                    {
                        int t=ar[j];
                        ar[j]=ar[k];
                        ar[k]=t;
                        int t1=d[j];
                        d[j]=d[k];
                        d[k]=t1;
                    }
                }
                k++;
            }
        }
        j++;
    }
}
int main()
{
    int i,*ar,*d,n;
    printf("\nEnter limit of array : ");
    scanf("%d",&n);
    ar=(int*)malloc(n*sizeof(int));
    d=(int*)malloc(n*sizeof(int));
    printf("\nEnter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    for(i=0;i<n;i++)
    {
        d[i]=count_digits(ar[i]);
    }
    display(ar,n);
   // display(d,n);
    int max=d[0];
    for(i=0;i<n;i++)
    {
        if(d[i]>max)
            max=d[i];
    }
  //  printf("%d",max);
   // printf("\n%d",divide(ar[0],1,d[0]));
    for(i=0;i<max;i++)
    {
        sort(ar,d,n,i);
        display(ar,n);
    }

    return 0;
}
