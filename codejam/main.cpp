#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,z;
    cin>>t;
    for(z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int s[n],e[n],i,j;
        for(i=0;i<n;i++)
        {
            cin>>s[i]>>e[i];
        }
        char str[1000]; int k=0;
        vector <int> s1,s2,e1,e2;
        s1.push_back(s[0]); e1.push_back(e[0]);
        str[k++]='C'; int f=0,f1=0;
        for(i=1;i<n;i++)
        {
            f=0;
            for(j=0;j<s1.size();j++)
            {
                if(s[i]>=s1[j] && s[i]<e1[j] || e[i]>s1[j] && e[i]<=e1[j] || s[i]<=s1[j] && e[i]>=e1[j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                s1.push_back(s[i]);
                e1.push_back(e[i]);
                str[k++]='C';
            }
            else
            {
                f=0;
                for(j=0;j<s2.size();j++)
                {
                   // cout<<s2[j]<<" "<<e2[j]<<endl;
                    if(s[i]>=s2[j] && s[i]<e2[j] || e[i]>s2[j] && e[i]<=e2[j] || s[i]<=s2[j] && e[i]>=e2[j])
                    {
                        //cout<<"2"<<endl;
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    s2.push_back(s[i]);
                    e2.push_back(e[i]);
                    str[k++]='J';
                }
                else
                {
                /*    cout<<1<<endl;
                    for(i=0;i<s1.size();i++)
                        cout<<s1[i]<<" "<<e1[i]<<endl;
                    cout<<2<<endl;
                    for(i=0;i<s2.size();i++)
                        cout<<s2[i]<<" "<<e2[i]<<endl;
                    */cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl;
                    f1=1;
                    break;
                }
            }
        }
        if(f1==0)
        {
            cout<<"Case #"<<z<<": ";
            for(i=0;i<k;i++)
            cout<<str[i];
            cout<<endl;
        }
    }
}
