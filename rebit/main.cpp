#include <bits/stdc++.h>
using namespace std;

long gcd1(long a, long b, long *x, long *y)
{
    if (a==0)
    {
        *x = 0, *y = 1;
        return b;
    }
    long x1,y1;
    long gcd=gcd1(b%a, a, &x1, &y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}

long modinv(long a, long m)
{
    long x, y;
    long g = gcd1(a, m, &x, &y);
    long res = (x%m + m) % m;
    return res;
}

long mul(long a, long b)
{
    long result=0;
    a=a%998244353;
    while(b)
    {
        if(b&1)
        result=(result+a)%998244353;
        a=(2*a)%998244353;
        b=b>>1;
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char l[100005],post[100005];
        cin>>l;
        long i,j,k=0; long q1=0;
        stack <char> s;
       // cout<<strlen(l)<<endl;
        for(i=0;i<strlen(l);i++)
        {
            if(l[i]=='#')
            q1++;
            else if(l[i]==')')
            {
                post[k++]=s.top();
                s.pop();
            }
            else if(l[i]!='(')
            {
                s.push(l[i]);
            }
        }
        while(s.size()!=0)
        {
            post[k++]=s.top();
            s.pop();
        }
        /*for(i=0;i<k;i++)
        cout<<post[i];
        cout<<endl;*/
        char a[4][4]={'0','0','0','0','0','a','0','a','0','0','A','A','0','a','A','1'};
        char o[4][4]={'0','a','A','1','a','a','1','1','A','1','A','1','1','1','1','1'};
        char x[4][4]={'0','a','A','1','a','0','1','A','A','1','0','a','1','A','a','0'};
        char ar[4]={'0','a','A','1'};
        long int count[4];
        long int temp[4];
        for(i=0;i<4;i++)
        {
            count[i]=0;
            temp[i]=0;
        }
        if(post[0]=='^')
        {
            temp[0]=4;
            temp[1]=4;
            temp[2]=4;
            temp[3]=4;
        }
        else if(post[0]=='|')
        {
            temp[0]=1;
            temp[1]=3;
            temp[2]=3;
            temp[3]=9;
        }
        else if(post[0]=='&')
        {
            temp[0]=9;
            temp[1]=3;
            temp[2]=3;
            temp[3]=1;
        }
       /* for(j=0;j<4;j++)
        {
            cout<<temp[j]<<endl;
        }*/
        long res=1;
        for(j=0;j<q1;j++)
        {
            res=(res*4)%998244353;
        }
        q1=res;
        int p,q,r;
        for(j=1;j<k;j++)
        {
            //cout<<"post[j]="<<post[j]<<endl;
            if(post[j]=='&')
            {
                for(p=0;p<4;p++)
                {
                    for(q=0;q<4;q++)
                    {
                        char ch=a[p][q];
                        for(r=0;r<4;r++)
                        {
                            if(ar[r]==ch)
                            break;
                        }
                        count[r]=(count[r]+temp[p])%1000000007;
                    }
                }
            }
            else if(post[j]=='|')
            {
              //  cout<<"yes"<<endl;
                for(p=0;p<4;p++)
                {
                    for(q=0;q<4;q++)
                    {
                        char ch=o[p][q];
                        for(r=0;r<4;r++)
                        {
                            if(ar[r]==ch)
                            break;
                        }
                        count[r]=(count[r]+temp[p])%1000000007;
                    }
                }
            }
            else if(post[j]=='^')
            {
                for(p=0;p<4;p++)
                {
                    for(q=0;q<4;q++)
                    {
                        char ch=x[p][q];
                        for(r=0;r<4;r++)
                        {
                            if(ar[r]==ch)
                            break;
                        }
                        count[r]=(count[r]+temp[p])%1000000007;
                    }
                }
            }
            for(p=0;p<4;p++)
            {
                temp[p]=count[p];
                count[p]=0;
               // cout<<temp[p]<<" ";
            }
           //  cout<<endl;
        }
        for(j=0;j<4;j++)
        {
            if(temp[j]==0)
            temp[j]=1;
            cout<<temp[j]<<" ";
        }
     //   cout<<endl;
        q1=modinv(q1,998244353);
      //  cout<<mul(25000,modinv(q1,998244353))<<endl;
        cout<<mul(temp[0],q1)<<" "<<mul(temp[3],q1)<<" "<<mul(temp[1],q1)<<" "<<mul(temp[2],q1)<<endl;
    }
	return 0;
}
