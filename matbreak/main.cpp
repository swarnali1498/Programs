#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        long int ar[n],i,j;
        for(i=0;i<n;i++)
        cin>>ar[i];
        int s,s1;
        long long int m1,sum=0;
        if(ar[0]>=0)
            s=0;
        else
            s=1;
        m1=ar[0];
        for(i=1;i<n;i++)
        {
            if(ar[i]>=0)
            s1=0;
            else
            s1=1;
            if(s==s1)
            {
                if(ar[i]>m1)
                m1=ar[i];
            }
            else
            {
                //cout<<m1<<endl;
                sum=sum+m1;
               // cout<<sum<<endl;
                if(ar[i]>=0)
                    s=0;
                else
                    s=1;
                m1=ar[i];
            }
        }
        sum=sum+m1;
        cout<<sum<<endl;
    }
}
