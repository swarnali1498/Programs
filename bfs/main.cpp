#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,q,i,id,k; long int x,y,lastanswer=0;
    cin>>n>>q;
    vector <long int> ar[n];
    for(i=0;i<q;i++)
    {
        cin>>id>>x>>y;
        if(id==1)
        {
            k=(x^lastanswer)%n;
            ar[k].push_back(y);
            //cout<<1<<endl;
        }
        else
        {
            k=(x^lastanswer)%n;
            lastanswer=ar[k][y%ar[k].size()];
            cout<<lastanswer<<endl;
            //cout<<2<<endl;
        }
    }
}
