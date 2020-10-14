#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long long int p1;
        cin>>p1;
        long long int p=0,q=0,r,count=0,i;
        for(i=1;;i++)
        {
            if(i*i>q)
            {
            //    cout<<i-r<<" "<<count<<endl;
                r=i;
            }
            else if(p1*p1<q)
            {
                cout<<count<<endl;
                break;
            }
            else
            {
                i=sqrt(q)+1;
            }
            p=r;
            q=q+i*i;
            count++;
            if(p==p1)
            {
                cout<<count<<endl;
                break;
            }
        }
    }
    return 0;
}
