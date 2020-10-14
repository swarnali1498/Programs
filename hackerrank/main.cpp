#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,z;
    cin>>t;
    for(z=0;z<t;z++)
    {
        cin>>n;
        int ar[n],i,j,f=0,c=0,b=0;
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        for(i=n-1;i>0;i--)
        {
            if(ar[i-1]==i+1)
            {
                int t=ar[i-1];
                ar[i-1]=ar[i];
                ar[i]=t;
                c=c+1;
            }
            else if(ar[i-2]==i+1 && i-2>=0)
            {
                int t=ar[i-2];
                ar[i-2]=ar[i-1];
                ar[i-1]=ar[i];
                ar[i]=t;
                c=c+2;
            }
            else if(ar[i]!=i+1)
            {
                f=1;
                cout<<"Too chaotic"<<endl;
                break;
            }
        }
        if(f==0)
        cout<<c<<endl;
    }
}
