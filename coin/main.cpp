#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int v,n,i,j;
        cin>>v>>n;
        long int c[n];
        for(i=0;i<n;i++)
            cin>>c[i];
        long int ar[n][v+1];
        sort(c,c+n);
        for(i=0;i<n;i++)
        {
            ar[i][0]=0;
        }
       // cout<<"ok"<<endl;
        for(i=1;i<v+1;i++)
        {
            if(i%c[0]==0)
                ar[0][i]=i/c[0];
            else
                ar[0][i]=INT_MAX;
        }
        cout<<"ok1"<<endl;
        for(i=1;i<n;i++)
        {
            for(j=1;j<v+1;j++)
            {
                if(j<c[i])
                    ar[i][j]=ar[i-1][j];
                else
                {
                    if(j%c[i]==0)
                    ar[i][j]=min(ar[i-1][j],j/c[i]);
                    else
                    {
                        long int d=j/c[i];
                        ar[i][j]=min(ar[i-1][j],(ar[i][d*c[i]]+ar[i][j-(d*c[i])]));
                    }
                }
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<v+1;j++)
            {
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<ar[n-1][v]<<endl;
    }
	return 0;
}
