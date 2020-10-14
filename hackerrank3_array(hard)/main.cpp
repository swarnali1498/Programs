#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,m,i;
    cin>>n>>m;
    long int ar[m][3];
    for(i=0;i<m;i++)
    {
        cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    }
    long int ar1[n],max,j;
    for(i=0;i<n;i++)
    ar1[i]=0;
    for(i=0;i<m;i++)
    {
        int a=ar[i][0]-1;
        int b=ar[i][1]-1;
        int k=ar[i][2];
        for(j=a;j<=b;j++)
        {
            ar1[j]=ar1[j]+k;
        }
    }
    max=ar1[0];
    for(i=0;i<n;i++)
    {
        if(max<ar1[i])
        {
            max=ar1[i];
        }
    }
    cout<<max<<endl;
}
