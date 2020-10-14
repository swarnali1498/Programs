#include<bits/stdc++.h>
using namespace std;
void check(long int ar[], long int ar1[], long int n, long int i)
{
    if(i==n)
    return;
    if(ar[i-1]<ar[i])
    {
        ar1[i]=ar1[i-1]+1;
    }
    else if(ar[i-1]>=ar[i])
    {
        ar1[i]=1;
        if(ar1[i-1]==1)
        {
            long int j=i-1;
            while(ar1[j]<ar1[j-1])
            {
                ar1[j]++;
                if(j-1<0)
                break;
                j--;
            }
        }
    }
    check(ar,ar1,n,i+1);
}
int main()
{
    long int n,i,sum=0;
    cin>>n;
    long int ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    long int* ar1=(long int*)malloc(n*sizeof(long int));
    ar1[0]=1;
    check(ar,ar1,n,1);
    for(i=0;i<n;i++)
    sum=sum+ar1[i];
    /*for(i=0;i<n;i++)
    cout<<ar1[i]<<" ";
    cout<<endl;*/
    cout<<sum<<endl;
}
