#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0,m,ar[50],x=1;
    cin>>n;
    for(x=0;x<n;x++)
        cin>>ar[x];
    int i,j,sum=0;
    for(i=0;i<n;i++)
        sum+=ar[i];
    int dp[n+1][sum+1];
    for(i=0;i<n+1;i++)
        dp[i][0]=1;
    for(i=1;i<sum+1;i++)
        dp[0][i]=0;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(j<ar[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]||dp[i-1][j-ar[i-1]];
        }
    }
    int hsum=sum/2;
   // cout<<sum<<endl;
    for(i=hsum;i>=0;i--)
    {
        if(dp[n][i]>0)
            break;
    }
    cout<<max(i,sum-i);
    return 0;
}
