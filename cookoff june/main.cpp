#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,m;
        cin>>n>>m;
        long int a[n],mex;
        long i,j;
        map <long int, long int> mp;
        map <long int,long int> ::iterator itr;
        set <long int> s;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
            if(mp.find(a[i])==mp.end())
            mp.insert({a[i],1});
            else
            {
                itr=mp.find(a[i]);
                itr->second++;
            }
        }
        for(i=1;;i++)
        {
            if(s.find(i)==s.end())
            {
                mex=i;
                break;
            }
        }
        if(s.find(m)==s.end())
        {
            if(mex==m)
            cout<<n<<endl;
            else
            cout<<-1<<endl;
        }
        else
        {
            if(mex<m)
            cout<<-1<<endl;
            else
            {
                //cout<<mex<<endl;
                s.erase(m);
                /*set <long int>:: iterator itr;
                for(itr=s.begin();itr!=s.end();itr++)
                    cout<<*itr<<" ";
                cout<<endl;*/
                mp.erase(m);
                long int sum=0;
                for(itr=mp.begin();itr!=mp.end();itr++)
                    sum=sum+itr->second;
                cout<<sum<<endl;
            }
        }
    }
	return 0;
}
