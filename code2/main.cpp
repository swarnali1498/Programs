#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n,b,h;
    cin>>n>>b>>h;
    long int i,j,g[n];
    for(i=0;i<n;i++)
        cin>>g[i];
    long int len=0,count=0;
    for(i=0;i<n;i++)
    {
        len=len+g[i]%1000000007;
    }
    long int vol=(len*b*h)%1000000007;
    int flag=0; long int a1,b1;
    for(i=0;i<n;i++)
    {
        a1=i; b1=i;
        while(1)
        {
            flag=0;
            if(b1<n-1 && g[b1+1]>=g[i])
            {
                flag++;
                b1++;
            }
            if(a1>=1 && g[a1-1]>=g[i])
            {
                flag++;
                a1--;
            }
            if(!flag)
                break;
        }
        if(b1>=n || g[b1]<g[i])
            b1--;
        if(a1<0 || g[a1]<g[i])
            a1++;
        if(count<((b1-a1+1)*g[i]*b*h)%1000000007)
        count=((b1-a1+1)*g[i]*b*h)%1000000007;
    }
    cout<<abs(vol-count)%1000000007<<endl;
    return 0;
}
