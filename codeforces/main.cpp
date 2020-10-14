#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s[9][9],i,j; long s1;
        for(i=0;i<9;i++)
        {
            cin>>s1;
            for(j=8;j>=1;j--)
            {
                s[i][j]=s1%10;
                s1=s1/10;
            }
            s[i][j]=s1;
        }
        for(i=0;i<9;i++)
        {
            s[i][i]=((s[i][i]+1)%9);
            if(s[i][i]==0)
            s[i][i]=9;
        }
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
}
