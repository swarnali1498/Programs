#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cout<<"Case #"<<x<<": ";
        long n;
        cin>>n;
        string s;
        cin>>s;
        long i,j,c1=0,c2=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='A')
                c1++;
            else
                c2++;
        }
        if(abs(c1-c2)==1)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
