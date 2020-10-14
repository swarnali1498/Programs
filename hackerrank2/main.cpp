#include<bits/stdc++.h>
using namespace std;
int check(int ar[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(ar[i]!=i+1)
        return 0;
    }
    return 1;
}
int main()
{
    int n,i,j,c=0;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    /*for(i=0;i<n;i++)
    {
        if(ar[i]!=i+1)
        {
            for(j=i+1;j<n;j++)
            {
                if(ar[j]==i+1)
                {
                    int t=ar[i];
                    ar[i]=ar[j];
                    ar[j]=t;
                    c++;
                    break;
                }
            }
        }
        if(check(ar,n))
        {
             break;
        }
    }
    cout<<c<<endl;*/
    i=0;
    int total=0;
    while(check(ar,n)==0)
    {
        for(i=0;i<n;i++)
    {
        if(ar[i]!=i+1)
        break;
    }
        int b=ar[i];
        int p=ar[i];
        c=0;
        do
        {
            int t=ar[p-1];
            ar[p-1]=p;
            p=t;
            c++;
        }while(b!=p);
        total=total+c-1;
    }
    cout<<total<<endl;
}
