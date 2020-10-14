#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int y,i,sum=0,count=0;
        cin>>y;
        if(y==1)
            cout<<1<<endl;
        else if(y==2)
            cout<<2<<endl;
        else
        {
            for(i=1;;i++)
            {
                if(sum>y)
                {
                    break;
                }
                sum=sum+i;
                count++;
            }
            long long int sum1=sum-i+1;
           // cout<<sum<<" "<<sum1<<endl;
            long long int time;
            if((y-sum1)<(sum-y))
            {
                time=1+count-2+(y-sum1);
            }
            else
            {
                time=1+count-1+(sum-y);
            }
            cout<<time<<endl;
        }
    }
    return 0;
}
