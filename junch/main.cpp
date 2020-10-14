#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,x,i,j;
        cin>>n>>p;
        int a[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        }
        cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<endl;
        cin>>x;
        if(x==-1)
        exit(0);
        int tot=x,c=0,c1=0,rowtot=0;
        for(i=1;i<=n;i++)
        {
            if(i==n)
            {
                //cout<<tot<<" "<<rowtot<<endl;
                x=tot-rowtot;
            }
            else
            {
                cout<<1<<" "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
                cin>>x;
                if(x==-1)
                exit(0);
            }
            if(x==n)
            {
                for(j=0;j<n;j++)
                a[i-1][j]=1;
                c1=c1+n;
            }
            else if(x==0)
            continue;
            else
            {
                int rtot=x;
                rowtot+=rtot;
                for(j=n-1;j>=1;j--)
                {
                    cout<<1<<" "<<i<<" "<<1<<" "<<i<<" "<<j<<endl;
                    cin>>x;
                    if(x==-1)
                    exit(0);
                    a[i-1][j]=rtot-x;
                //    if(i==4)
              //      cout<<i-1<<" "<<j<<" "<<a[i-1][j]<<endl;
                    rtot=x;
                    c1=c1+a[i-1][j];
                    if(tot==c1)
                    break;
                }
                a[i-1][0]=rtot;
                c1=c1+a[i-1][0];
            }
            if(tot==c1)
            break;
        }
        cout<<2<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cin>>x;
        if(x==-1)
        exit(0);
    }
	return 0;
}
