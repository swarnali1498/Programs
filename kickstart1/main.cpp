#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        long n,q,i,j,l,r,lroom,rroom,croom;
        cin>>n>>q;
        long d[n-1],s[q],k[q];
        for(i=0;i<n-1;i++)
        {
            cin>>d[i];
        }
        for(i=0;i<q;i++)
        {
            cin>>s[i]>>k[i];
        }
        cout<<"Case #"<<x<<": ";
        for(i=0;i<q;i++)
        {
            if(s[i]==1)
            {
                cout<<k[i]<<" ";
            }
            else if(s[i]==n)
            {
                cout<<n-k[i]+1<<" ";
            }
            else
            {
                l=s[i]-2;
                r=s[i]-1;
                lroom=s[i]-1;
                rroom=s[i]+1;
                croom=s[i];
                while(k[i]!=1)
                {
                    //cout<<l<<" "<<r<<" "<<d[l]<<" "<<d[r]<<endl;
                    if((l>=0 && r<n && d[l]<d[r]) || r==n)
                    {
                        l--;
                        croom=lroom;
                        lroom--;
                    //    cout<<"inside1"<<endl;
                    }
                    else if((l>=0 && r<n && d[l]>d[r]) || l==-1)
                    {
                        r++;
                        croom=rroom;
                        rroom++;
                      //  cout<<"inside2"<<endl;
                    }
                    k[i]--;
                    //cout<<croom<<endl;
                }
                cout<<croom<<" ";
            }
        }
        cout<<endl;
    }
}
