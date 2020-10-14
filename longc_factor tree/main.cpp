#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define mod 1000000007
#define fill(a,x) memset(a,x,sizeof(a))
using namespace std;
ll n;

bool isprime(ll x)
{
    ll i;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
vector<ll>route;
void bfs(ll s,ll y,vector<vector<ll>>&v)
{
    queue<ll>Q;
    vector<bool>visited(n,false);
    //fill(visited,false);
    vector<ll>dist(n,0),prev(n,-1);
    //fill(visited,false);
    //fill(dist,0);
    Q.push(s);
    //fill(prev,-1);
    visited[s]=true;
    while(!Q.empty())
    {
        ll v1=Q.front();
        Q.pop();
        vector<vector<l1>>::u;
        for(u:v[v1])
        {
            if(!visited[u])
            {
                visited[u]=true;
                Q.push(u);
                dist[u]=dist[v1]+1;
                prev[u]=v1;
            }
        }
    }
    route.clear();
    for(ll i=y;i!=-1;i=prev[i])
    route.pb(i);
    reverse(route.begin(),route.end());
}

const ll N=1000000;
ll prime[N+1];
vector<ll>pr;
void sieve_linear()
{
    ll i,j,k,p;
    /*
    fill(prime,0);
    for (i=2; i<=N; i++)
    {
        if (prime[i] == 0) {
            prime[i] = i;
            pr.pb (i);
        }
        for (j=0; j<(ll)pr.size() && pr[j]<=prime[i] && i*pr[j]<=N; j++)
        prime[i * pr[j]] = pr[j];
    }

    for(i=0;i<20;i++)
    {
        cout<<"prime[i]="<<prime[i]<<" "<<"pr[i]="<<pr[i]<<"\n";
    }
    cout<<"\n";
    */
    fill(prime,true);
    prime[0]=prime[1]=false;
    for(i=2;i*i<=N;i++)
    {
        if(prime[i])
        {
            for(j=i*i;j<=N;j+=i)
            prime[j]=false;
        }
    }
}

void sieve(ll n1,vector<ll>&check_prime)
{
    ll i,j;
    /*
    vector<bool>is_prime(n1+1,true);
    //fill(is_prime,true);
    is_prime[0]=is_prime[1]=false;
    //fill(is_prime,false);
    for(i=2;i*i<=n1;i++)
    {
        if(is_prime[i])
        {
            for(j=i*i;j<=n1;j+=i)
            is_prime[j]=false;
        }
    }

    for(i=2;i<=n1;i++)
    {
        if(is_prime[i])
        check_prime.pb(i);
    }
    */
    //i=0;
    //cout<<"Factors till largest number :"<<"\n";
    /*
    for(i=2;i<=n1;i++)
    {
        if(find(pr.begin(),pr.end(),i)!=pr.end())
        {
            check_prime.pb(i);
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    */
    for(i=2;i<=n1;i++)
    {
        if(prime[i])
        {
            //cout<<i<<" ";
            check_prime.pb(i);
        }
    }
    //cout<<"\n";
}

ll count_fact(vector<ll>vect, ll n1)
{
    ll i,j,k,p;
    i=*max_element(vect.begin(),vect.end());
    //cout<<"Max element :"<<i<<"\n";
    vector<ll>check_prime;
    sieve(i,check_prime);
    unordered_map<ll,ll>mymap;
    i=0;
    while(i<n1)
    {
        for(j=0;j<check_prime.size();j++)
        {
            while(vect[i]>1 && vect[i]%check_prime[j]==0)
            {
                vect[i]=vect[i]/check_prime[j];
                mymap[check_prime[j]]++;
            }
        }
        if(vect[i]!=1)
        mymap[vect[i]]++;
        i++;
    }
    k=1;
    for(auto it:mymap)
    k=k*(it.second + 1L)%mod;
    return k%mod;
}

ll fact(ll ans)
{
    ll i,c=0;
    for(i=2;i<=ans;i++)
    {
        if(ans%i==0)
            c=(c+1)%mod;
    }
    return c+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello World"<<"\n";
    ll t,i,j,k,p,c,m,x,y;
    cin>>t;
    sieve_linear();
    while(t--)
    {
        cin>>n;
        vector<vector<ll>>v(n);
        for(i=0;i<n-1;i++)
        {
            cin>>x>>y;
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
        }
        /*
        cout<<"Adjacency list :"<<"\n";
        for(i=0;i<n;i++)
        {
            for(auto it1:v[i])
                cout<<it1<<" ";
            cout<<"\n";
        }
        */
        ll a[n];
        for(i=0;i<n;i++)
        cin>>a[i];

        ll q;
        cin>>q;
        while(q--)
        {
            cin>>x>>y;
            x--;
            y--;
            bfs(x,y,v);
            vector<ll>vect;
            ll ans=1;
            for(auto it:route)
            {
                //cout<<it<<" ";
                vect.pb(a[it]);
                //ans*=a[it];
            }
            //cout<<"\n"<<"Answer :"<<"\n";

            cout<<count_fact(vect,vect.size())%mod<<"\n";
            //cout<<fact(ans)%mod<<"\n";
            vect.clear();
        }
    }
    return 0;
}

