 #include<bits/stdc++.h>
 using namespace std;
 vector <long> adj[1000000];
 set <long> s1,s2;
 void dfs(long u,long a,long c,int l)
 {
    int i;
    if(c==a)
    {
        if(l==1)
        s1.insert(u);
        else
        s2.insert(u);
    }
    for(i=0;i<adj[u].size();i++)
    {
        if(c==a)
        {
            dfs(adj[u][i],a,1,l);
        }
        else
        {
            dfs(adj[u][i],a,c+1,l);
        }
    }
 }
 int main()
 {
    int t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        long n,a,b,i,j,u;
        double sum=0;
        cin>>n>>a>>b;
        for(i=0;i<n-1;i++)
        {
            cin>>u;
            adj[i+1].push_back(u-1);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                s1.insert(i);
                dfs(i,a,0,1);
                s2.insert(j);
                dfs(j,b,0,2);
                set <long>::iterator itr;
                for(itr=s1.begin();itr!=s1.end();itr++)
                {
                    if(s2.find(*itr)!=s2.end())
                    {
                        s2.erase(*itr);
                    }
                }
                cout<<i+1<<" "<<j+1<<" "<<s1.size()+s2.size()<<endl;
                sum+=s1.size()+s2.size();
                s1.clear();
                s2.clear();
            }
        }
        for(i=0;i<n;i++)
        adj[i].clear();
        cout<<"Case #"<<x<<": "<<sum/(n*n)<<endl;
    }
    return 0;
 }
