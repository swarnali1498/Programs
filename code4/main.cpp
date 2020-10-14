#include <bits/stdc++.h>
using namespace std;

int func(int n,char** ar)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ar[i][j]=='D')
            {
                ar[i][j]=' ';
            }
        }
    }
    int col[n];
    for(i=0;i<n;i++)
        col[i]=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(ar[i][j]=='C')
                col[j]++;
        }

        for(i=0;i<n;i++)
            ar[i][j]='_';
        i=n-1;
            //cout<<col[j]<<endl;
        long int z=col[j];
        while(z!=0)
        {
            ar[i][j]='C';
            i--;
            z--;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    int row[n],column[n];
    for(i=0;i<n;i++)
    {
        int r=0;
        for(j=0;j<n;j++)
        {
            if(ar[i][j]=='_')
                r++;
        }
        row[i]=r;
    }
    for(i=0;i<n;i++)
    {
        int c=0;
        for(j=0;j<n;j++)
        {
            if(ar[j][i]=='_')
                c++;
        }
        column[i]=c;
    }
    multimap <int,int> map;
    multimap <int,int>:: iterator itr1;
    for(i=0;i<n;i++)
    {
        if(map.find(column[i])==map.end())
        {
            map.insert({column[i],1});
        }
        else
        {
            itr1=map.find(column[i]);
            itr1->second++;
    //    cout<<row[i]<<" "<<column[i]<<endl;
        }
    }
    int ans;
    multimap <int,int>:: iterator itr;
    for(itr=map.begin();itr!=map.end();itr++)
    {
        if(itr->first==itr->second)
            ans=itr->first;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    char ar[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
    }
    int tr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tr[i][j]=ar[j][i];
        }
    }
    int v1=func(n,&ar);
    int v2=func(n,tr);
    cout<<max(v1,v2);
    return 0;
}
