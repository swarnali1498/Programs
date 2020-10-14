#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,i,x,y,id,k,lastanswer=0,p[n];
    cin>>n>>q;
    int ar[n][n];
    for(i=0;i<n;i++)
    {
        p[i]=0;
    }
    for(i=0;i<q;i++)
    {
        cin>>id>>x>>y;
        if(id==1)
        {
            k=(x^lastanswer)%n;
            ar[k][p[k]++]=y;
        }
        else
        {
            k=(x^lastanswer)%n;
            lastanswer=ar[k][y%p[k]];
            cout<<lastanswer<<endl;
        }
    }

}
