#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int sum=a+b;
        int r1,r2,r3,r4,s[4],i,max=0;
        if(a<10 && b<10)
            max=a+b;
        else if(a<10 && b>10)
        {
            r1=a;
            r3=b/10;
            r4=b%10;
            s[0]=r1+r3*10+r4;
            s[1]=r3+r1*10+r4;
            s[2]=r4+r3*10+r1;
            for(i=0;i<3;i++)
            {
          //  cout<<s[i]<<" ";
                if(s[i]>=max)
                max=s[i];
            }
        }
        else if(a>10 && b<10)
        {
            r1=a/10;
            r2=a%10;
            r3=b;
            s[0]=r1*10+r2+r3;
            s[1]=r3*10+r2+r1;
            s[2]=r1*10+r3+r2;
            for(i=0;i<3;i++)
            {
          //  cout<<s[i]<<" ";
                if(s[i]>=max)
                max=s[i];
            }
        }
        else
        {
            r1=a/10;
            r2=a%10;
            r3=b/10;
            r4=b%10;
            s[0]=r1*10+r3+r2*10+r4;
            s[1]=r1*10+r4+r3*10+r2;
            s[2]=r3*10+r2+r1*10+r4;
            s[3]=r4*10+r2+r3*10+r1;
            for(i=0;i<4;i++)
            {
          //  cout<<s[i]<<" ";
                if(s[i]>=max)
                max=s[i];
            }
       // cout<<endl;
            if(max<sum)
            max=sum;
        }
        cout<<max<<endl;
    }
	return 0;
}
