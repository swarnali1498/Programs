#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;
    int l=s.length(),i,ar[26]={0};
    cout<<"length="<<l<<endl;
    for(i=0;i<l;i++)
    {
        int index=((int)s[i])-97;
        ar[index]++;
    }
    for(i=0;i<26;i++)
    cout<<ar[i]<<" ";
    cout<<endl;
    int ar1[100000]={0},k=0;
    for(i=0;i<26;i++)
    {
        ar1[ar[i]]++;
        if(k<ar[i])
        {
            k=ar[i];
     //       cout<<"k="<<k<<endl;
        }
    }
    for(i=0;i<=k;i++)
    cout<<ar1[i]<<" ";
    cout<<endl;
    int count=0;
    for(i=1;i<=k;i++)
    {
        if(ar1[i]!=0)
        {
            count++;
        }
    }
    if(count>2)
    {
        cout<<"NO";
        return 0;
    }
    for(i=0;i<=k;i++)
    {
        if(ar1[i]!=0 && ar1[i+1]==1)
        {
            cout<<"YES";
            return 0;
        }
        else if(ar1[1]==1)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
