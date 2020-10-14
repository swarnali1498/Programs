#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,i,j,c=0;
        cin>>n;
        long ar[n];
        set <long> s;
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
            s.insert(i+1);
        }
        long p=1;
        while(!s.empty())
        {
            i=*(s.begin())-1;
            long len=1;
            int a=ar[i];
            int b=i+1;
            s.erase(b);
            int start=b;
            while(a!=start)
            {
                len++;
                a=ar[ar[b-1]-1];
                b=ar[b-1];
                s.erase(b);
            }
            p=(p*len)/(__gcd(p,len));
        }
        cout<<p<<endl;
    }
    return 0;
}
