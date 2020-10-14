#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int c;
    cin>>c;
    long int i,j;
    long double d[c],t[c],x[c],y[c],v[c];
    map <long double, long int> m;
    map <long double, long int>::iterator itr1;
    for(i=0;i<c;i++)
    {
        cin>>x[i]>>y[i]>>v[i];
        d[i]=sqrt(pow(x[i],2)+pow(y[i],2));
        t[i]=d[i]/v[i];
    //    cout<<d[i]<<" "<<v[i]<<" "<<t[i]<<endl;
        if(m.find(t[i])==m.end())
        m.insert({t[i],1});
        else
        {
            itr1=m.find(t[i]);
            itr1->second++;
        }
    }
    long int sum=0;
    for(itr1=m.begin();itr1!=m.end();itr1++)
    {
        long int n=itr1->second;
       // cout<<itr1->first<<" "<<n<<endl;
        sum=sum+(n*(n-1))/2;
    }
    cout<<sum<<endl;
}
