#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n],i,j,bs[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        int num=ar[i];
        int a=num%10;
        num=num/10;
        int b=num%10;
        num=num/10;
        int c=num%10;
        num=num/10;
        int m1=max(a,max(b,c));
        int m2=min(a,min(b,c));
        int bit=m1*11+m2*7;
        if(bit/100>0)
        {
            bit=bit%100;
        }
        bs[i]=bit;
        //cout<<bs[i]<<" ";
    }
    //cout<<endl;
    int odd=0,even=0,total=0;
    for(i=0;i<=9;i++)
    {
        odd=0;
        even=0;
        for(j=0;j<n;j++)
        {
            if(bs[j]/10==i)
            {
                if(j%2==0)
                    odd++;
                else
                    even++;
            }
        }
        int pairs=((odd*(odd-1))/2)+(even*(even-1)/2);
        if(pairs>2)
            pairs=2;
        total+=pairs;
    }
    cout<<total;
    return 0;
}
