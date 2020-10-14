#include <bits/stdc++.h>
using namespace std;

long int n,s,e;
int bin_search(long int l, long int h)
{
    char ch,ch1;
    cout<<l<<" "<<h<<" "<<s<<" "<<e<<endl;
    if(l<h)
    {
        long int mid=(l+h)/2;
        cout<<mid<<endl;
        cin>>ch;
        if(ch=='E')
        {
            cout<<mid<<endl;
            return 0;
        }
        else
        {
            cout<<mid<<endl;
            cin>>ch1;
            if(ch==ch1)
            {
                if(ch=='L')
                {
                    e=mid-1;
                    bin_search(s,mid-1);
                }
                else
                {
                    s=mid+1;
                    bin_search(mid+1,e);
                }
            }
            else
            {
                int x=bin_search(l,mid-1);
                if(x==-1)
                {
                    bin_search(mid+1,h);
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin>>n;
    s=1;
    e=n;
    bin_search(1,n);
	return 0;
}
