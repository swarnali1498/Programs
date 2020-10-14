#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int x,y,a,b,min1;
        cin>>x>>y>>a>>b;
        long int diff=(abs)(x-y);
        unsigned long long int sum=(diff*a),sum1,sum2;
        if(x<y)
        min1=x;
        else
        min1=y;
        cout<<sum<<" "<<min1<<" "<<b<<endl;
        cout<<1000000000*1000000000<<endl;
        sum1=(sum+min1*b);
        sum2=(a*(x+y));
        if(sum1<sum2)
            sum=sum1;
        else
            sum=sum2;
        cout<<sum<<endl;
    }
}
