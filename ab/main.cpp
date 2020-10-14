#include<iostream>
using namespace std;
int check(char** a,int i,int j,int n,int m,int c)
{
    if(i>=m && j>=n)
    {
        return c;
    }
    if(a[i][j]=='/' && a[i+1][j]=='\\' && a[i][j+1]=='\\' && a[i+1][j+1]=='/')
    {
        c++;
        c=c+check(a,i,j+2,n,m,c);
        c=c+check(a,i+2,j,n,m,c);
    }
    else
    {
        c=c+check(a,i,j+1,n,m,c);
        c=c+check(a,i+1,j,n,m,c);
    }
}
int main()
{
    int z,i,t,n,m,j,c=0;
    cin>>t;
    if(t>=1 && t<=5)
    {
        for(z=1;z<=t;z++)
        {
            cin>>n>>m;
            if(n>=2 && m<=1000)
            {
                char** a;
                a=(char**)malloc(n*sizeof(char*));
                for(i=0;i<m;i++)
                a[i]=(char*)malloc(m*sizeof(char));
                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        cin>>a[i][j];
                    }
                }
                int c;
                c=check(a,0,0,n,m,0);
                cout<<c;
            }
        }
    }
    return 0;
}
