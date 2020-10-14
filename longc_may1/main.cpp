#include <bits/stdc++.h>
using namespace std;

long fout(long p[],long n)
{
    long i,c=0;
    for(i=0;i<n;i++)
    {
        if(p[i]!=i+1)
        c++;
    }
    return c;
}
long firstout(long p[],long n)
{
    long i;
    for(i=0;i<n;i++)
    {
        if(p[i]!=i+1)
        break;
    }
    return i;
}
long nextout(long a, long b, long p[], long n)
{
    long i;
    for(i=0;i<n;i++)
    {
        if(p[i]!=i+1 && p[i]!=a && p[i]!=b)
        {
            //cout<<p[i]<<endl;
            break;
        }
    }
    return i;
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
        set <long> s;
        for(i=0;i<n;i++)
        {
            if(p[i]!=i+1)
                s.insert(i);
        }
        long mat[10000][3];
        long count=0,f=0,out=fout(p,n);
        while(1)
        {
            if(out==2)
            {
                f=1;
                break;
            }
            else if(out==0)
            break;
            i=*s.begin();
            long a=p[i];
            long b=p[a-1];
            long c=p[b-1];
            if(a==c)
            {
                c=*s.begin();
                if(c==a)
                {
                    c=*(s.begin()+1);
                    if(c==b)
                    {
                        c=*(s.begin()+2);
                    }
                }
                p[a-1]=a;
                p[b-1]=p[c];
                p[c]=b;
                mat[count][0]=a;
                mat[count][1]=c+1;
                mat[count][2]=i+1;
                out=out-1;
                s.erase(a-1);
            }
            else
            {
                p[a-1]=a;
                p[b-1]=b;
                p[i]=c;
                mat[count][0]=a;
                mat[count][1]=b;
                mat[count][2]=i+1;
                s.erase(a-1);
                s.erase(b-1);
                if(c==i+1)
                {
                    s.erase(i);
                    out=out-3;
                }
                else
                    out=out-2;
            }
            /*cout<<i<<" "<<a<<" "<<b<<" "<<c<<endl;
            for(i=0;i<n;i++)
                cout<<p[i]<<" ";
            cout<<endl;*/
            //cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
            count++;
        }
        if(f==1)
        cout<<-1<<endl;
        else
        {
            cout<<count<<endl;
            for(i=0;i<count;i++)
            {
                cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
            }
        }
    }
	return 0;
}
