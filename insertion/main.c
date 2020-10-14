#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion(int*,int);
int main()
{
    int *ar,n,i;
    srand(time(NULL));
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    ar=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        ar[i]=rand()%101;
    printf("\nOriginal array is : \n");
    for(i=0; i<n; i++)
        printf("%d  ",ar[i]);
    insertion(ar,n);
    printf("\nSorted array is : \n");
    for(i=0; i<n; i++)
        printf("%d  ",ar[i]);
    return 0;
}
void insertion(int* ar,int n)
{
    int i,p,k,c=0;
    for(i=0; i<n; i++)
    {
        k=ar[i];
        p=i;
        while(p>0 && k<ar[p-1])
        {
            c++;
            ar[p]=ar[p-1];
            p--;
        }
        ar[p]=k;
    }
    printf("\nNumber of comparisons is %d ",c);
}
