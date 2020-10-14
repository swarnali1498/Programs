#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        char s[n];
        cin>>s;
        long int i; int f=0;
        for(i=0;i<n-1;i++)
        {
            if(s[i]=='L' && s[i+1]=='R' || s[i]=='R' && s[i+1]=='L' ||s[i]=='U' && s[i+1]=='D'||s[i]=='D' && s[i+1]=='U')
            {
                cout<<i+1<<" "<<i+2<<endl;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            long int j;
            for(j=0;j<n;j++)
            {
            long int l=0,r=0,u=0,d=0;
            for(i=j;i<n;i++)
            {
                if(s[i]=='L')
                l++;
                else if(s[i]=='R')
                r++;
                else if(s[i]=='U')
                u++;
                else
                d++;
                if(l==r && u==d)
                {
                    cout<<j+1<<" "<<i+1<<endl;
                    f=1;
                    break;
                }
            }
            }
            if(f==0)
                cout<<-1<<endl;
        }
    }
}
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,copy,sum=0;
        cin>>n;
        copy=n;
        while(copy!=0)
        {
            if(copy>=1000000000)
            {
                copy=copy-1000000000;
                copy=copy+100000000;
                sum=sum+1000000000;
            }
            else if(copy>=100000000)
            {
                copy=copy-100000000;
                copy=copy+10000000;
                sum=sum+100000000;
            }
            else if(copy>=10000000)
            {
                copy=copy-10000000;
                copy=copy+1000000;
                sum=sum+10000000;
            }
            else if(copy>=1000000)
            {
                copy=copy-1000000;
                copy=copy+100000;
                sum=sum+1000000;
            }
            else if(copy>=100000)
            {
                copy=copy-100000;
                copy=copy+10000;
                sum=sum+100000;
            }
            else if(copy>=10000)
            {
                copy=copy-10000;
                copy=copy+1000;
                sum=sum+10000;
            }
            else if(copy>=1000)
            {
                copy=copy-1000;
                copy=copy+100;
                sum=sum+1000;
            }
            else if(copy>=100)
            {
                copy=copy-100;
                copy=copy+10;
                sum=sum+100;
            }
            else if(copy>=10)
            {
                copy=copy-10;
                copy=copy+1;
                sum=sum+10;
            }
            else
            {
                sum=sum+copy;
                copy=0;
            }
        }
        cout<<sum<<endl;
    }
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,copy,sum=0;
        cin>>n;
        copy=n;
        while(copy!=0)
        {
            if(copy>=100)
            {
                copy=copy-100;
                copy=copy+10;
                sum=sum+100;
            }
            else if(copy>=10)
            {
                copy=copy-10;
                copy=copy+1;
                sum=sum+10;
            }
            else
            {
                sum=sum+copy;
                copy=0;
            }
        }
        cout<<sum<<endl;
    }
}
*/
