#include<bits/stdc++.h>
using namespace std;
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        long int ar[2*n-1],i,j,len=2*n-1;
      //  set <long int, greater<long int>> s;
        for(i=0;i<len;i++)
        {
            ar[i]=i+1;
            cout<<i+1<<" ";
        }
        cout<<endl;
        i=len-1;
        cout<<i<<endl;
        while(i>0)
        {
            cout<<i<<ar[2]\<<endl;
            long int a=ar[i];
            cout<<a<<endl;
            long int b=ar[i-1];
            cout<<b<<endl;
            long int c=ar[i-2];
            cout<<c<<endl;
            long int sum=(a+b+c+a*b+a*c+b*c+a*b*c)%1000000007;
            cout<<"sum="<<sum<<" "<<a<<" "<<b<<" "<<c<<endl;
            ar[i-2]=sum;
            i=i-2;
        }
        cout<<ar[0]<<endl;
    }
}
