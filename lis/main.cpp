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
int lis(int* seq,int i,int j,int n)
{
    if(j==n)
        return 1;
    if(seq[i]<seq[j])
        return max(lis(seq,j,j+1,n)+1,lis(seq,i,j+1,n));
    return lis(seq,i,j+1,n);
}
int main()
{
    int n,*seq,*c;
    cout<<"Enter n : ";
    cin>>n;
    seq=(int*)malloc(n*sizeof(int));
    c=(int*)malloc((n-1)*sizeof(int));
    cout<<"\nEnter sequence : \n";
    int i;
    for(i=0;i<n;i++)
        cin>>seq[i];
    cout<<"c";
    for(i=0;i<n-1;i++)
    {
        c[i]=lis(seq,i,i+1,n);
        cout<<endl<<c[i];
    }
    cout<<"\nOver";
    int max;
    max=c[0];
    for(i=0;i<n-1;i++)
    {

        if(c[i]>max)
            max=c[i];
    }
    cout<<"Longest Increasing subsequence is ";
    //if(max>1)
        cout<<max;
    //else
     //   cout<<1;
    return 0;
}
