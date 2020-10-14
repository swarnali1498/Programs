#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int max1(int a,int b,int c)
{
    if(a>=b && a>=c)
    return a;
    else if(b>=a && b>=c)
    return b;
    else
    return c;
}
int main()
{
    long int n,i;
    cin>>n;
    int ar[n],ar1[n],m;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    m=ar[0];
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            ar1[i]=ar[i];
        }
        else if(i==1)
        {
            ar1[i]=max(ar[i],ar[i-1]);
            if(ar1[i]>m)
            m=ar1[i];
        }
        else
        {
            ar1[i]=max1(ar[i],m,ar1[i-2]+ar[i]);
            if(ar1[i]>m)
            m=ar1[i];
        }
    }
    cout<<ar1[n-1]<<endl;
}
