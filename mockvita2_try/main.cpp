#include <bits/stdc++.h>
using namespace std;

int same(long in[],long n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(in[i]!=i+1)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,i,j,c=1;
        cin>>n;
        long ar[n],in[n],temp[n];
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
            in[i]=i+1;
        }
        while(1)
        {
            for(i=0;i<n;i++)
            {
                temp[ar[i]-1]=in[i];
            }
            for(i=0;i<n;i++)
            {
                in[i]=temp[i];
            }
            if(same(in,n))
                break;
            c++;
        }
        cout<<c<<endl;
    }
    return 0;
}
