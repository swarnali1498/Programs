#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define fill(a,x) memset(a,x,sizeof(a))
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

string decbin(int c)
{
    //const int y=p;
    string k=bitset<64>(c).to_string();
    const auto x=k.find('1');
    if(x!=string::npos)
    return k.substr(x);
    return "0";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */
    //cout<<"Hello World"<<"\n";
    int x,y,n,i,j,k,c,p=0;
    cin>>n;
    int a[n];
    vector<pair<int,int>>v(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
          p=a[i];
        else
        {
          if(a[i]>p)
            p=a[i];
        }
        x=__builtin_popcount(a[i]);
        y=((int)log2(a[i])+1)-x;
        //cout<<"for a[i]="<<a[i]<<" x="<<x<<" y="<<y<<"\n";
        v[i].fi=y;
        v[i].se=x;
    }
    //p=*max_element(a,a+n);
    k=(int)log2(p)+1;
    c=0;
    for(int b=1;b<(1<<n);b++)
    {
        vector<int>sub;
        for(i=0;i<n;i++)
        {
            if(b&(1<<i))
            sub.pb(i);
        }
        x=y=0;
        int s2=sub.size();
        for(i=0;i<s2;i++)
        {
            //cout<<sub[i]<<" ";
            x+=v[sub[i]].fi;
            y+=v[sub[i]].se;
        }
        //cout<<"\n";
        //cout<<"x="<<x<<" y="<<y<<"\n";
        if(x==y)
        c++;
    }
    //cout<<"c="<<c<<"\n";
    string str=decbin(c);
    int s1=str.length();
    if(s1>=k)
    cout<<str;
    else
    {
        k=k-s1;
        for(i=1;i<=k;i++)
        str='0'+str;
        cout<<str;
    }

    //cout<<str;

    return 0;
}
