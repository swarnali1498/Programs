#include <bits/stdc++.h>
using namespace std;

long binsearch(long p[],long l,long r,long s)
{

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,k,i,j,m;
        cin>>n>>k;
        long p[n];
        for(i=0;i<n;i++)
        {
            cin>>p[i];
        }
        long index[n];
        for(i=0;i<n;i++)
        {
            index[p[i]-1]=i;
        }
        long mat[1000][3];
        long last=n-1;
        long c=0;
        while(last>2)
        {
            long s=index[last];
            if(last-s<2)
            {
                s=last-2;
            }
            while(p[last]!=last+1)
            {
                long t1=p[s];
                p[s]=p[last];
                p[last]=p[last-1];
                p[last-1]=t1;
                long t2=index[p[s]-1];
                index[p[s]-1]=index[p[last-1]-1];
                index[p[last-1]-1]=index[p[last]-1];
                index[p[last]-1]=t2;
                mat[c][0]=s+1;
                mat[c][1]=last;
                mat[c][2]=last+1;
                //cout<<mat[c][0]<<" "<<mat[c][1]<<" "<<mat[c][2]<<endl;
                c++;
                if(c>k)
                break;
            }
            if(c>k)
            break;
            last--;
        }
        //cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
        if(p[0]==1 && p[1]==2 && p[2]==3)
        {
            if(c>k)
            cout<<-1<<endl;
            else
            {
                cout<<c<<endl;
                for(i=0;i<c;i++)
                {
                    cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
                }
            }
        }
        else if(p[0]==3 && p[1]==1 && p[2]==2)
        {
            if(c+2>k)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<c+2<<endl;
                for(i=0;i<c;i++)
                {
                    cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
                }
                cout<<1<<" "<<2<<" "<<3<<endl;
                cout<<1<<" "<<2<<" "<<3<<endl;
            }
        }
        else if(p[0]==2 && p[1]==3 && p[2]==1)
        {
            if(c+1>k)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<c+1<<endl;
                for(i=0;i<c;i++)
                {
                    cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
                }
                cout<<1<<" "<<2<<" "<<3<<endl;
            }
        }
        else
        {
            cout<<-1<<endl;
        }
    }
	return 0;
}
