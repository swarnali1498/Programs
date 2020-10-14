#include <bits/stdc++.h>
using namespace std;

vector <vector <long> > v;
void subsequence(long i, long ar[], long n, vector <long> vect, long val)
{
    if(val!=-1)
        vect.push_back(val);
    if(i==n)
    {
        v.push_back(vect);
        return;
    }
    subsequence(i+1,ar,n,vect,ar[i]);
    subsequence(i+1,ar,n,vect,-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,i,j;
        cin>>n;
        long ar[n];
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        vector <long> vect;
        subsequence(0,ar,n,vect,-1);
       /* for(i=0;i<v.size();i++)
        {
            for(j=0;j<v[i].size();j++)
                cout<<v[i][j];
            cout<<endl;
        }*/
        vector <int> f(5005);
        vector <long> freq(n+1);
        fill(freq.begin(),freq.end(),0);
        for(i=0;i<v.size()-1;i++)
        {
            fill(f.begin(),f.end(),0);
            for(j=0;j<v[i].size();j++)
            {
                //cout<<v[i][j];
                f[v[i][j]]++;
                //cout<<"max "<<max1<<endl;
            }
            long pos=0,m1=f[0];
            for(j=0;j<=n;j++)
            {
                if(f[j]>m1)
                {
                    m1=f[j];
                    pos=j;
                }
            }
            freq[pos]++;
        }
        for(i=1;i<=n;i++)
            cout<<freq[i]<<" ";
        cout<<endl;
        freq.clear();
        vect.clear();
        f.clear();
        for(i=0;i<v.size();i++)
        v[i].clear();
        v.clear();
    }
        return 0;
}
