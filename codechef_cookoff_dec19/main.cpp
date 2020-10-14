#include <bits/stdc++.h>
using namespace std;
int check(char a[],int i,int k,int n)
{
    int l,j;
    if(k==0)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]=='0' && a[j+1]=='1' && j+1<n)
            {
          //      cout<<j<<endl;
                    return j;
            }
        }
        //cout<<-1<<endl;
        return -1;
    }
    if(k==1)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]=='1' && a[j+1]=='0' && j+1<n)
            {
            //    cout<<j<<endl;
                    return j;
            }
        }
        //cout<<-1<<endl;
        return -1;
    }
}
int min(int a,int b,int c,int d)
{
    cout<<"min"<<endl;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    if(a<=b && a<=c && a<=d)
    return a;
    else if(b<=a && b<=c && b<=d)
    return b;
    else if(c<=a && c<=b && c<=d)
    return c;
    else
    return d;
}
int func(char a[],int p,int k,int y,int s,int n)
{
	            int i,j,pos,l,d,f=0;
	            if(p==0 && k==0 || p==1 && k==1)
	            {
	                cout<<"p="<<p<<" k="<<k<<" y="<<y<<" s="<<s<<" n="<<n<<endl;
	                for(i=0;i<n;i++)
                    cout<<a[i];
                    cout<<endl;
	                for(l=y;l<n-1;l++)
                    {
                        a[l]=a[l+1];
                    }
                    n--;
                    for(i=0;i<n;i++)
                    cout<<a[i];
                    cout<<endl;
	            }
	            else if(p==1 && k==0 || p==0 && k==1)
	            {
	                cout<<"p="<<p<<" k="<<k<<" y="<<y<<" s="<<s<<" n="<<n<<endl;
	                for(i=0;i<n;i++)
                    cout<<a[i];
                    cout<<endl;
	                for(l=y+1;l<n-1;l++)
                    {
                        a[l]=a[l+1];
                    }
                    n--;
                    for(i=0;i<n;i++)
                    cout<<a[i];
                    cout<<endl;
	            }
	            for(i=0;i<n;i++)
	            {
	                if(a[i]=='0' && a[i+1]=='1')
	                {
	                    k=0;
	                    pos=i;
	                    d=check(a,pos+1,k,n);
	                    cout<<"01 : d="<<d<<endl;
	                    if(d!=-1)
	                    {
	                        cout<<"d="<<d<<" n="<<n<<endl;
	                        f=1;
	                        return 1+min(func(a,0,k,i,5,n),func(a,1,k,i,6,n),func(a,0,k,d,7,n),func(a,1,k,d,8,n));

	                    }
	                }
	                if(a[i]=='1' && a[i+1]=='0')
	                {
	                    k=1;
	                    pos=i;
	                    d=check(a,pos+1,k,n);
	                    cout<<"10 : d="<<d<<endl;
	                    if(d!=-1)
	                    {
	                        cout<<"d="<<d<<" n="<<n<<endl;
	                        f=1;
	                        cout<<"check"<<endl;
	                        cout<<func(a,1,k,i,1,n)<<endl;
	                        //cout<<"min is "<<min(0,0,0,1)<<endl;
	                        return 1+min(func(a,1,k,i,1,n),func(a,0,k,i,2,n),func(a,1,k,d,3,n),func(a,0,k,d,4,n));

	                    }
	                }
	            }
	            if(f==0)
	            return 0;
}
int main() {
	// your code goes here
	int t,z,i,count,n;
	char a[1000000];
	cin>>t;
	if(t>=1 && t<=40)
	{
	    for(z=0;z<t;z++)
	    {
            cin>>a;
	        if(strlen(a)>=1 && strlen(a)<=1000)
	        {
	            n=strlen(a);
	            for(i=0;i<n;i++)
	            {
	                if(a[i]!='0' && a[i]!='1')
	                exit(0);
	            }
                count=func(a,-1,-1,-1,0,n);
	            cout<<count<<endl;
	        }
	    }
	}
	return 0;
}
