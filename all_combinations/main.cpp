#include <bits/stdc++.h>
using namespace std;
vector <int> s;
int present(int sum,vector<int>s)
{
    int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]==sum)
            return 1;
    }
    return 0;
}
void compute(int l,int ar[],int r,int sum)
{
    if(present(sum,s)==0)
        s.push_back(sum);
    if(l>r)
    {
        return;//cout<<sum<<endl;
    }
    else
    {
        compute(l+1,ar,r,sum+ar[l]);
        compute(l+1,ar,r,sum);
    }
}
int main()
{
    int ar[]={1,2,3},n,i;
    n=3;
    compute(0,ar,2,0);
    for(i=0;i<s.size();i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
