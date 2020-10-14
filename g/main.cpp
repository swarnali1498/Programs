#include <bits/stdc++.h>
using namespace std;

/*int main() {
	int t,n,i,z,j;
	cin>>t;
	if(t>=1 && t<=100)
	{
	    for(z=0;z<t;z++)
	    {
	        cin>>n;
	        if(n>=2 && n<=10000)
	        {
	            long int y,ar[n];
	            for(i=0;i<n;i++)
	            {
	                cin>>y;
	                if(y>=0 && y<=10000000)
	                {
	                    ar[i]=y;
	                }
	            }
	            long int t1,t2,max1=0;
	            for(i=0;i<n;i++)
	            {
	                for(j=i+1;j<n;j++)
	                {
	                    t1=(ar[i]|(ar[i]&ar[j]))^(ar[j]&(ar[j]|ar[i]));
	                    t2=(ar[j]|(ar[j]&ar[i]))^(ar[i]&(ar[i]|ar[j]));
	                    cout<<t1<<" "<<t2<<endl;
	                    if(t1>=t2 && t1>=max1)
	                    {
	                        max1=t1;
	                    }
	                    else if(t2>=t1 && t2>=max1)
	                    {
	                        max1=t2;
	                    }
	                }
	            }
	            cout<<max1<<endl;
	        }
	    }
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int prime(int a)
{
    int c=0,j;
    if(a==0||a==1||a<0)
    return 0;
    else if(a==2)
    return 1;
	            for(j=2;j<a;j++)
	            {
	                if(a%j==0)
	                c++;
	            }
	            if(c==0)
	            return 1;
	            else
	            return 0;
}*/
int prime(long int a)
{
    int c=0,j;
    if(a==0||a==1||a<0)
    return 0;
    else if(a==2)
    return 1;
	            for(j=2;j<a;j++)
	            {
	                if(a%j==0)
	                {
	                    c++;
	                    break;
	                }
	            }
	            if(c==0)
	            return 1;
	            else
	            return 0;
}
int main()
{
	int t,n,i,j,z;
	cin>>t;
	if(t>=1 && t<=100)
	{
	    for(z=0;z<t;z++)
	    {
	        cin>>n;
	        if(n>=1 && n<=1000)
	        {
	            long int ar[n],y;
	            for(i=0;i<n;i++)
	            {
	                cin>>y;
	                if(y>=0 && y<=10000000)
	                {
	                    ar[i]=y;
	                }
	            }
	            int c=0,k=0; long int ar1[n];
	            for(i=0;i<n;i++)
	            {
	                if(prime(ar[i]) && prime(ar[i]-2))
	                {
	                    ar1[k++]=ar[i];
	                    ar[i]=-1;
	                }
	            }
	            sort(ar1,ar1+k);
	            int j=0;
	            for(i=0;i<n;i++)
	            {
	                if(ar[i]==-1)
	                ar[i]=ar1[j++];
	            }
	            for(i=0;i<n;i++)
	            {
	                cout<<ar[i]<<" ";
	            }
	            cout<<endl;
	        }
	    }
	}
	return 0;
}
