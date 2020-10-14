#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int test;
    for(test=1;test<=t;test++)
    {
        long int n,b,i,j;
        cin>>n>>b;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        long int sum=0;
        if(a[0]>b)
        {
            cout<<test<<" "<<0<<endl;
        }
        else
        {
            int f=0;
            for(i=0;i<n;i++)
            {
                sum=sum+a[i];
                if(sum>b)
                {
                    //f=1;
                    break;
                }

            }
            /*if(f==1)
            cout<<test<<" "<<i-1<<endl;
            else
              */  cout<<test<<" "<<i<<endl;
        }
    }
}
