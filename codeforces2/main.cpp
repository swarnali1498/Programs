#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    char sub[1000];
    cin>>sub;
    int i,c=0;
    for(i=0;i<strlen(sub)-1;i++)
    {
        if(sub[i]==sub[i+1])
        c++;
    }
    if(c==strlen(sub)-1)
    cout<<sub<<endl;
    else
    {
        c=0;
        for(i=0;i<strlen(sub)-1;i++)
        {
            int a=(int)sub[i]-48;
            int b=(((int)sub[i+1]-48)+1)%2;
            if(a==b)
            c++;
        }
        if(c==strlen(sub)-1)
        cout<<sub<<endl;
        else
        {
            cout<<sub[0];
            for(i=1;i<strlen(sub);i++)
            {
                int a=(int)sub[i]-48;
                int b=(((int)sub[i-1]-48)+1)%2;
                if(a==b)
                cout<<sub[i];
                else
                cout<<b<<sub[i];
            }
            cout<<endl;
        }
    }
    }
}
