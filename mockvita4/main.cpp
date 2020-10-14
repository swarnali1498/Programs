#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int r1,r2;
    cin>>r1>>r2;
    long long int r;
    cin>>r;
    int ar[365];
    for(i=1;i<=31;i++)
    {
        ar[i-1]=25+abs(i-15);
    }
    for(i=32;i<=59;i++)
    {
        ar[i-1]=16+abs(i-15);
    }
    for(i=60;i<=90;i++)
    {
        ar[i-1]=9+abs(i-15);
    }
    for(i=91;i<=120;i++)
    {
        ar[i-1]=4+abs(i-15);
    }
    for(i=121;i<=151;i++)
    {
        ar[i-1]=1+abs(i-15);
    }
    for(i=152;i<=181;i++)
    {
        ar[i-1]=abs(i-15);
    }
    for(i=182;i<=212;i++)
    {
        ar[i-1]=1+abs(i-15);
    }
    for(i=213;i<=243;i++)
    {
        ar[i-1]=4+abs(i-15);
    }
    for(i=244;i<=273;i++)
    {
        ar[i-1]=9+abs(i-15);
    }
    for(i=274;i<=304;i++)
    {
        ar[i-1]=16+abs(i-15);
    }
    for(i=305;i<=334;i++)
    {
        ar[i-1]=25+abs(i-15);
    }
    for(i=335;i<=365;i++)
    {
        ar[i-1]=36+abs(i-15);
    }
    long long int sum=0;
    for(i=0;i<365;i++)
    {
        sum=sum+ar[i];
    }
    sum=sum-r;
    long long int diff=r1-r2;

}
