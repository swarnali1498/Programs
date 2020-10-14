#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long int t,i,j,d,count=0,x;
	char a[1000000000],b[100000000];
	cin>>t;
	if(t>=1 && t<=100000)
	{
	    for(x=0;x<t;x++)
	    {
	    cin>>a;
	    cin>>b;
	    long int m=strlen(a);
	    long int n=strlen(b);
	    if(m>=1 && n>=1 && m<=100000 && n<=100000 && m+n<=1000000)
	    {
	        for(i=0;i<m;i++)
	        {
	            if(a[i]!='0' && a[i]!='1')
	            exit(0);
	        }
	        for(i=0;i<n;i++)
	        {
	            if(b[i]!='0' && b[i]!='1')
	            exit(0);
	        }
	        int p=0;
	        for(i=0;i<n;i++)
	        {
	            if(b[i]=='1')
	            p=1;
	        }
	       // a[m+1]='2';
//	        a[m+2]='\0';
	        //cout<<m<<" "<<n<<" "<<a[m+1];
	       if(p==0)
	        cout<<0<<endl;
	        while(1)
	        {
	            count++;
	        long int max;
	        if(m>n)
	        {
	            max=m;
	            d=m-n;
	            for(i=0;i<d;i++)
	            {
	                for(j=i+n-1;j>=i;j--)
	                {
	                    b[j+1]=b[j];
	                }
	                b[i]='0';
	            }
	        }
	        else
	        {
	            max=n;
	            d=n-m;
	            for(i=0;i<d;i++)
	            {
	                for(j=i+m-1;j>=i;j--)
	                {
	                    a[j+1]=a[j];
	                }
	                a[i]='0';
	            }
	        }
	        char c[1000000000],d[1000000000];
	        for(i=0;i<max;i++)
	        {
	               if(a[i]==b[i])
	               c[i]=0;
	               else
	               c[i]='1';
	               if(a[i]=='1' && b[i]=='1')
	               d[i]='1';
	               else
	               d[i]='0';
	        }
	        long int k=0;
	        for(i=0;i<max;i++)
	        {
	            if(d[i]=='1')
	            {
	                k++;
	            }
	        }
	        if(k==0)
	        break;
	        else
	        {
	            for(i=0;i<max;i++)
	            {
	                a[i]=c[i];
	                b[i]=d[i];
	            }
	            b[max]='0';
	        }
	        }
	        cout<<count<<endl;

	    }
	    }
	}
	return 0;
}
