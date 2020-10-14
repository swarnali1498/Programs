#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //cout<<pow(2,5)<<" ";
    cin>>n;
    if(n>=1 && n<=10)
    {
        long int i,j,m;
        m=pow(2,n);
        //cout<<m;
        long int a[m][m];
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i>j)
                {
                    cin>>a[i][j];
                }
            }
        }
        long int b[m];
        for(i=0;i<m;i++)
        {
            b[i]=i;
           // cout<<b[i]<<" ";
        }
        //cout<<endl;
        while(m!=1)
        {
            long int k=0;
            for(i=0;i<m;i=i+2)
            {
                if(a[b[i+1]][b[i]]==1)
                {
                    b[k++]=b[i+1];
                }
                else
                {
                    b[k++]=b[i];
                }
            }
            m=m/2;
          /*  for(i=0;i<m;i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<"\n";*/
            //cout<<b[m-1];
        }
        cout<<b[m-1]+1;
    }
    return 0;
}
