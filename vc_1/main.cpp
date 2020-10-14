//Acaius and string
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,j;
        string s;
        cin>>s;
        string sub="abacaba";
        int c=0,q=0,curq=-1,count=0,confirm=0,pos=-1;
        for(i=0;i<n-6;i++)
        {
            c=0; q=0; curq=-1;
            for(j=0;j<=6;j++)
            {
                if(s[i+j]==sub[j])
                {
                    c++;
                }
                else if(s[i+j]=='?')
                {
                    q++;
                    curq=i+j;
                }
            }
            if(c==7)
            confirm++;
            else if(c+q==7 && q!=0)
            {
                //cout<<"curq "<<curq<<" pos "<<pos<<endl;
                if(pos==-1)
                    pos=i;
                else if(pos!=-1 && curq!=-1 && curq <= pos+6)
                {
                    int f=0;

                    for(j=curq-1;j>=pos;j--)
                    {
                        if(s[j]=='?')
                        {
                            f=1;
                            break;
                        }
                    }
                    //cout<<"f "<<f<<endl;
                    if(f==1)
                        pos=i;
                    else
                        pos=-1;
                }
                //cout<<"pos "<<pos<<endl;
                count++;
            }
        }
        //cout<<count<<" "<<confirm<<endl;
        if(confirm>=2)
        cout<<"No"<<endl;
        else if(confirm==1)
        {
            cout<<"Yes"<<endl;
            for(i=0;i<n;i++)
            {
                if(s[i]=='?')
                    cout<<'d';
                else
                    cout<<s[i];
            }
            cout<<endl;
        }
        else if(count>0)
        {
            string str;
           // cout<<pos<<endl;
            if(pos==-1)
                cout<<"No"<<endl;
            else
            {
                for(i=0;i<n;i++)
                {
                    if(i!=pos && s[i]!='?')
                        str+=s[i];
                    else if(i==pos)
                    {
                        str+="abacaba";
                        i=i+6;
                    }
                    else if(s[i]=='?')
                    {
                        str+='d';
                    }
                    //cout<<str[i];
                }
                cout<<"Yes"<<endl;
                cout<<str<<endl;
            }
        }
        else
        cout<<"No"<<endl;
    }
}
