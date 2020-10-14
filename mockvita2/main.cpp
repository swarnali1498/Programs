#include<bits/stdc++.h>
using namespace std;

int prime(int i)
{
    int j;
    for(j=2;j<=sqrt(i);j++)
    {
        if(i%j==0)
            return 0;
    }
    return 1;
}
int convert(int a, int b)
{
    string str1=to_string(a);
    string str2=to_string(b);
    string str=str1+str2;
    int i=stoi(str);
    if(prime(i))
        return i;
    return -1;
}
int main()
{
    int n1,n2,i,j,k=0,ar[10000],ar1[10000],l=0;
    cin>>n1>>n2;
    for(i=n1;i<=n2;i++)
    {
        if(prime(i))
            ar[k++]=i;
    }
    set <int> s;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            if(i!=j)
            {
                int p=convert(ar[i],ar[j]);
                if(p!=-1 && s.find(p)==s.end())
                ar1[l++]=p;
                s.insert(p);
            }
        }
    }
    int max1=0,min1=999999;
    for(i=0;i<l;i++)
    {
        max1=max(max1,ar1[i]);
        min1=min(min1,ar1[i]);
    }
    long fibo[l];
    fibo[0]=min1;
    fibo[1]=max1;
    for(i=2;i<l;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    cout<<fibo[l-1];
}
