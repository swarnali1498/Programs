/*#include<bits/stdc++.h>
using namespace std;
long int c=1;
void dfs(long int i,vector<vector <long int> > ar,int *visited)
{
    long int j;
    for(j=0;j<ar[i].size();j++)
    {
        if(visited[ar[i][j]]==0)
        {
            visited[ar[i][j]]=1;
            c++;
            dfs(ar[i][j],ar,visited);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        long int n,m,cl,cr,i,j;
        cin>>n>>m>>cl>>cr;
        long int u,v;
        vector <vector<long int> > ar(n);
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
            ar[u-1].push_back(v-1);
            ar[v-1].push_back(u-1);
        }
        int *visited=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        visited[i]=0;
        long long cost=0,ecost,lcost,edge;
        //i=0;
        long int count=0;
        while(1)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                if(visited[j]==1)
                count++;
                else
                break;
               // cout<<visited[j]<<" ";
               // cout<<endl;
            }
            if(count==n)
            break;
            else
            {
             //   cout<<"Inside"<<endl;
                visited[j]=1;
                dfs(j,ar,visited);
                edge=c-1;
                ecost=edge*cr+cl;
                lcost=c*cl;
                if(ecost<lcost)
                cost=cost+ecost;
                else
                cost=cost+lcost;
            }
            c=1;
        }
        cout<<cost<<endl;
    }
}

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
long nodes;

void DFS(int n)
{
    nodes++;
    visited[n] = true;
    for(vector<int>::iterator i = adj[n].begin(); i != adj[n].end() ; i++)
    {
        if(!visited[*i])
            DFS(*i);
    }
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N,M,a,b;
        long X,Y;
        cin >> N >> M >> X >> Y;

        for(int i = 0 ; i < M ; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        long cost=0;

        for(int i = 1 ; i <= N ; i++)
        {
            if(!visited[i])
            {
                nodes = 0;
                DFS(i);
                cost = cost + X;
                if(X > Y)
                    cost = cost + (Y*(nodes-1));
                else
                    cost = cost + (X*(nodes-1));
            }
        }

        cout << cost << endl;
        for(int i=0 ; i<=N ; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
    }

    return 0;
}
