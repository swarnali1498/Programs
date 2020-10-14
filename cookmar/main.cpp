#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,i,j;
        cin>>n;
        long w[n];
        for(i=0;i<n;i++)
        {
            cin>>w[i];
        }
        long max=w[0];
        for(i=1;i<n;i++)
        {
            if(w[i]>max)
            max=w[i];
        }
        long d[n],k=0,l=0;
        for(i=0;i<n;i++)
        {
            if(w[i]==max)
            d[k++]=i;
        }
        long diff[n];
        for(i=0;i<k-1;i++)
        {
            diff[l++]=d[i+1]-d[i];
        }
        diff[l++]=d[0]-d[k-1]+n;
        max=diff[0];
        for(i=1;i<l;i++)
        {
            if(diff[i]>max)
            max=diff[i];
        }
      //  cout<<"max="<<max<<endl;
        if(l==1)
            cout<<n/2<<endl;
        else if(max<=n/2)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<max-n/2<<endl;
        }
    }
	return 0;
}
