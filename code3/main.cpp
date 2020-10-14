#include <bits/stdc++.h>
using namespace std;

int ispalin(string str, int start, int end)
{
    int i=start,j=end;
    while(i<j)
    {
        if(str[i]!=str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int main()
{
    string str;
    cin>>str;
    int i,j,flag=0;
    for(i=0;i<str.size()-2;i++)
    {
        if(ispalin(str,0,i))
        {
           // cout<<"1"<<endl;
            for(j=i+1;j<str.size()-1;j++)
            {
                if(ispalin(str,i+1,j))
                {
                   // cout<<2<<endl;
                    if(ispalin(str,j+1,str.size()-1))
                        flag=1;
                }
                if(flag==1)
                    break;
            }
        }
        if(flag==1)
            break;
    }
    int a,b,c;
    if(flag)
    {
    for(a=0;a<=i;a++)
        cout<<str[a];
    cout<<endl;
    for(b=i+1;b<=j;b++)
        cout<<str[b];
    cout<<endl;
    for(c=j+1;c<str.size();c++)
        cout<<str[c];
    }
    else
        cout<<"Impossible";
    return 0;
}
