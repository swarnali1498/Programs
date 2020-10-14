#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i=1,c=0;
        while(n>=i)
        {
            i=i*2;
            c++;
        }
        cout<<c<<endl;
    }
}
