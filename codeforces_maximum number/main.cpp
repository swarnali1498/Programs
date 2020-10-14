#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n,copy,c=0,i;
    cin>>n;
    copy=n;
    if(n==0||n==1)
        cout<<0<<endl;
    else
    {
        while(copy>1)
        {
            c++;
            copy=copy-2;
        }
  //  cout<<c<<endl;
        if(n%2==0)
        {
            for(i=0;i<c;i++)
            {
                cout<<1;
            }
        }
        else
        {
            cout<<7;
            for(i=0;i<c-1;i++)
            {
                cout<<1;
            }
        }
        cout<<endl;
    }
    return 0;
}
