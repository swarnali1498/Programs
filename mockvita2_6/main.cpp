#include<bits/stdc++.h>
using namespace std;

long long int ar[21][100];
void factorial()
{
    int i,j;
    for(i=0;i<=20;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0||j==i)
                ar[i][j]=1;
            else
                ar[i][j]=(ar[i-1][j-1]+ar[i-1][j]);
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    factorial();
    int t;
    cin>>t;
    while(t--)
    {
    int a,h,l1,l2,m,c;
    cin>>a>>h>>l1>>l2>>m>>c;
    int s=(a+c);
    if(s*m<h)
        cout<<"RIP";
    else
    {
        long long int total=s*m,i=0,c1=1,pw=0,pl=0;
        while(total>=h)
        {
            c1=ar[m][i];
            total=total-c;
            pw+=(long long int)(pow(l1,(m-i)))*c1*(long long int)(pow((l2-l1),i));
            i++;
        }
        while(i<=m)
        {
            c1=ar[m][i];
            total=total-c;
            pl+=(long long int)(pow(l1,(m-i)))*c1*(long long int)(pow((l2-l1),i));
            i++;
        }
        //cout<<pw<<" "<<pl<<endl;
        long long int pt=pw+pl;
        long long int gcd=__gcd(pw,pt);
        cout<<pw/gcd<<"/"<<pt/gcd<<endl;
    }
    }
    return 0;
}
