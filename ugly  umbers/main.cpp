#include <iostream>
using namespace std;
int ispf(long int num)
{
    while(num%2==0)
    {
        num=num/2;
    }
    while(num%3==0)
    {
        num=num/3;
    }
    while(num%5==0)
    {
        num=num/5;
    }
    if(num==1)
        return 1;
    else
        return 0;
}
int main() {
    long int t;
    cin>>t;
    if(t>=1 && t<=10000)
    {
        while(t--)
        {
            long int n;
            cin>>n;
            if(n>=1 && n<=10000)
            {
                long int i=0,j=1,ar[n],c=0;
                while(c<n)
                {
                    if(ispf(i))
                    {
                        ar[c++]=i;
                    }
                    i++;
                }
                //for(i=0;i<n;i++)
                cout<<ar[n-1]<<"\n";
            }
        }
    }
	return 0;
}
