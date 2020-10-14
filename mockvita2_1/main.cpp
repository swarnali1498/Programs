#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str1,str2;
    cin>>str1;
    cin>>str2;
    //cout<<str1<<" "<<str2;
    queue <char> q;
    int i,j;
    for(i=0;i<n;i++)
    {
        char c=str2[i];
        q.push(c);
    }
    int count=0;
    for(i=0;i<n;)
    {
        if(str1[i]==q.front())
        {
            i++;
            q.pop();
            count=0;
        }
        else
        {
            char c=q.front();
            q.pop();
            q.push(c);
            count++;
        }
        if(count==n)
        break;
    }
    cout<<n-i;
    return 0;
}
