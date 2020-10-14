#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int x,y,count=0;
        cin>>x>>y;
        long int sum=x,s=0;
        if(x==1)
        {
            cout<<1<<" "<<0<<endl;
        }
        else
        {
            while(sum!=0)
            {
                int r=sum%10;
                sum=sum/10;
                s=s+r;
            }
            if(s%10==0)
                cout<<1<<" "<<2<<endl;
            else
            {
                while((x%10)!=0)
                {
                    count++;
                    x=x+y;
                    sum=x; s=0;
                    while(sum!=0)
                    {
                        int r=sum%10;
                        sum=sum/10;
                        s=s+r;
                    }
                    if(s%10==0)
                    {
                        count++;
                        break;
                    }
               // cout<<x<<" "<<count<<endl;
                }
                cout<<1<<" "<<count+1<<endl;
            }
        }
    }
    return 0;
}
