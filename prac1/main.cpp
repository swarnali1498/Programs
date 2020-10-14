#include <bits/stdc++.h>
using namespace std;
// Complete the solve function below.
int gcd(int a,int b)
{
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int calc(int a,int b)
{
    int g;
    if(a>b)
    g=gcd(a,b);
    else
    g=gcd(b,a);
    return g;
}
string solve(vector<int> a)
{
    int i,j,n=a.size();
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(calc(a[i],a[j])==1)
            return "YES";
        }
    }
    return "NO";
}

int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a;
        int i,j;
        for(i=0;i<n;i++)
        {
            cin>>j;
            a.push_back(j);
        }
        string result = solve(a);
        cout<<result<<endl;
    }
    return 0;
}
