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
        cout<<"Case #"<<x<<":"<<endl;
        int n;
        cin>>n;
        string in1,out1;
        cin>>in1>>out1;
        //cout<<in1<<endl<<out1<<endl;
        int i,j;
        int in[n],out[n];
        for(i=0;i<n;i++)
        {
            if(in1[i]=='Y')
                in[i]=1;
            else
                in[i]=0;
            if(out1[i]=='Y')
                out[i]=1;
            else
                out[i]=0;
        }
        char mat[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mat[i][j]='B';
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    mat[i][j]='Y';
                else
                {
                    if(in[j]==0)
                        mat[i][j]='N';
                    else if(out[i]==0)
                        mat[i][j]='N';
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(mat[i][j]=='B')
                {
                    if(out[j+1]==1 || j+1==i)
                    mat[i][j]=mat[i][j+1];
                    else
                    mat[i][j]='N';
                }
            }
            for(j=i+1;j<n;j++)
            {
                if(mat[i][j]=='B')
                {
                    if(out[j-1]==1 || j-1==i)
                    mat[i][j]=mat[i][j-1];
                    else
                    mat[i][j]='N';
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
