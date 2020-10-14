#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(int n, int k, string s) {
    int ar[n],i,j;
    ar[0]=0;
    for(i=1;i<n;i++)
    {
        if(s[i-1]=='1')
            ar[i]=ar[i-1]+1;
        else
            ar[i]=ar[i-1];
        if(i-k-1>=0 && s[i-k-1]=='1')
            ar[i]--;
    }
    long c=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='1')
        c++;
    }
    //cout<<endl;
    long long int num=c,den=pow(n,2),gcd;
    for(i=0;i<n;i++)
    {
        if(s[i]=='1' && ar[i]!=0)
        {
            num=num+2*ar[i];
        }
    }
    //cout<<n<<" "<<pow(100000,2)<<" "<<den<<endl;
    gcd=__gcd(num,den);
    //cout<<num<<"/"<<den<<endl;
    num=num/gcd;
    den=den/gcd;
    cout<<num<<"/"<<den<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("INPUT.txt","r",stdin);
        freopen("OUTPUT.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int t;
    cin >> t;
    while(t--)
    {
        long n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        solve(n, k, s);
    }
    return 0;
}

