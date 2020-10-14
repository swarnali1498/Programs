#include <iostream>

using namespace std;
#include<stdlib.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void lis(int* seq,int i,int j,int n,int** a)
{
   // if(j==n)
     //   return;

    //cout<<a[i][j]<<" ... ";
}
int main()
{
    int n,*seq;
    cout<<"Enter n : ";
    cin>>n;
    if(n>=1 && n<=1000000)
    {
    seq=(int*)malloc(n*sizeof(int));
    cout<<"\nEnter sequence : \n";
    int i,j;
    for(i=0;i<n;i++)
    {
        int p;
        cin>>p;
        if(p<1 || p>100000)
        return 0;
        seq[i]=p;
    }
    int* a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(seq[i]<seq[j] && seq[j]<seq[j+1] && a[i]<=a[i-1])
                a[i]=a[i-1]+1;
            else
                a[i]=a[i-1];
        }
    }
    int max;
    max=a[0];
    for(i=1;i<n-1;i++)
    {
        if(a[i][n-1]>max)
            max=a[i][n-1];
    }
        cout<<max;
    return 0;
}
