#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],i,j,sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
        }
        int dp[n+1][sum+1];
        //sort(a,a+n);
        for(i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }
        for(i=1;i<sum+1;i++)
        {
            dp[0][i]=0;
        }
        for(i=1;i<n+1;i++)
        {
            for(j=1;j<sum+1;j++)
            {
                if(j<a[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i-1]];
                    /*if(dp[i][j]<0)
                        cout<<dp[i-1][j]<<" "<<dp[i-1][j-a[i-1]]<<endl;*/
                }
            }
        }
        int hsum=sum/2;
        for(i=hsum;i>=0;i--)
        {
            if(dp[n][i]>0)
            break;
        }
        cout<<(sum-i)-i<<endl;
    }
	return 0;
}
