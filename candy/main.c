#include <stdio.h>
#include <stdlib.h>
int* compute(int* arr,int* d,int n)
{

}
int main()
{
    int n;
    printf("\nn= ");
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int)),*d=(int*)malloc(nsizeof(int));
    int i;
    printf("\nRatings: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        d[i]=-1;
    }
    d=compute(arr,d,n);
}
