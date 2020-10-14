#include<bits/stdc++.h>
using namespace std;
vector <int> adj[26];
stack <int> s;
int visited[26];
void dfs(int i)
{
    visited[i]=1;
    vector <int> :: iterator j;
    for(j=adj[i].begin();j!=adj[i].end();j++)
    {
        if(visited[*j]==0)
        {
            dfs(*j);
        }
    }
    s.push(i);
}
string findOrder(string dict[], int N, int K)
{
    int i,j,index=-1;
    for(i=0;i<N-1;i++)
    {
        for(j=0;j<min(dict[i].size(),dict[i+1].size());j++)
        {
            if(dict[i][j]!=dict[i+1][j])
            {
                if(index==-1)
                    index=dict[i][j]-'a';
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                break;
            }
        }
    }
    for(i=0;i<26;i++)
    visited[i]=0;
    for(i=0;i<26;i++)
    {
        if(visited[i]==0 && adj[i].size()!=0)
            dfs(i);
    }
    string str="";
    while(!s.empty())
    {
        str+=(char)(s.top()+97);
        s.pop();
    }
    for(i=0;i<26;i++)
    adj[i].clear();
    return str;
}
int main()
{
    string words[]={"baa","abcd", "abca" ,"cab", "cad"};
    cout<<findOrder(words,5,4)<<endl;
    return 0;
}

