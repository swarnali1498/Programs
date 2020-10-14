#include <bits/stdc++.h>
using namespace std;

int isprime(long a)
{
    long i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    long int t,i,j;
    cin>>t;
    //sieve of eratosthenes
    int marked[100005];
    memset(marked,0,100005*sizeof(marked[0]));
    for(i=2;i<100005;i++)
    {
        if(isprime(i))
        marked[i]=1;
        for(j=2;i*j<100005;j=j+i)
        {
            marked[i*j]++;
        }
    }
    int dp[6][100005];
    for(i=0;i<6;i++)
    {
        for(j=0;j<100005;j++)
        {
            if(i==0)
            dp[i][j]=0;
            else
            {
                if(marked[j]==i)
                dp[i][j]=dp[i-1][j]+1;
            }
        }
    }
    while(t--)
    {
        long int a,b;
        int k;
        cin>>a>>b>>k;
        cout<<dp[k][b]-dp[k][a]<<endl;
    }
	return 0;
}
