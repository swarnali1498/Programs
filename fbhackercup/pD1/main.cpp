#include <bits/stdc++.h>
using namespace std;
long long int c[1000000],num,dp[1000000];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cout<<"Case #"<<x<<": ";
        long long int n,m,i,j;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>num;
            if(num==0)
            {
                c[i]=LLONG_MAX;
                dp[i]=LLONG_MAX;
            }
            else
                c[i]=num;
        }
        multimap <long long int,long long int> mymap;
        if(n<=m+1)
            cout<<0<<endl;
        else
        {
            for(i=1;i<=m;i++)
            {
                if(i<n && c[i]!=LLONG_MAX)
                {
                   // cout<<c[i]<<endl;
                    mymap.insert({c[i],i});
                    dp[i]=c[i];
                }
            }
            multimap <long long int, long long int>::iterator itr;
            /*for(itr=mymap.begin();itr!=mymap.end();itr++)
                cout<<itr->first<<" ";
            cout<<endl;*/
            int f=0;
            for(i=m+1;i<n-1;i++)
            {
                if(mymap.size()==0)
                {
                    f=1;
                    break;
                }
                if(c[i]!=LLONG_MAX)
                {
                    long long int val=(mymap.begin())->first+c[i];
                    mymap.insert({val,i});
                    dp[i]=val;
                }
                if(mymap.find(dp[i-m])!=mymap.end())
                {
                    mymap.erase(dp[i-m]);
                }
            }
            if(f==0 && mymap.size()!=0)
            cout<<(mymap.begin())->first<<endl;
            else
            cout<<-1<<endl;
        }
       mymap.clear();
    }
    return 0;
}
