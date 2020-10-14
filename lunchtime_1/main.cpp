//counting inversions_codechef
#include <bits/stdc++.h>
using namespace std;
long int compute(long int a,long int d)
{
    long int i,sum=0,n;
    if(d!=0)
    {
    if(a%d==0)
    n=(a/d);
    else
    n=(a/d)+1;
  //  cout<<"a="<<a<<"\n";
    sum=(n*(2*a+(n-1)*(-1)*d))/2;
//    cout<<"sum="<<sum<<"\n";
    }
    return sum;
}
int main(void) {
	// your code goes here
	int t,n;
	long int k,i,j;
	cin>>t;
	if(t>=1 && t<=1000)
	{
	    while(t--)
	    {
	        cin>>n>>k;
	        long int ar[n];
	        if(n>=1 && n<=100 && k>=1 && k<=1000000)
	        {
	            for(i=0;i<n;i++)
	            {
	                 long int z;
	                 cin>>z;
	                 if(z>=0 && z<=1000000000)
	                 {
	                     ar[i]=z;
	                 }
	            }
	            long int c=0,c1[n],c2[n];
	            for(i=0;i<n;i++)
	            {
	                c=0;
	               for(j=i+1;j<n;j++)
	               {
	                    if(ar[i]>ar[j])
	                    c++;
	                }
	                c1[i]=c;
	            }
	            for(i=0;i<n;i++)
	            {
	                c=0;
	               for(j=0;j<n;j++)
	               {
	                    if(ar[i]>ar[j])
	                    c++;
	                }
	                c2[i]=c;
	            }
	            long int p,sum=0;
	            for(i=0;i<n;i++)
	            {
	                p=c1[i]+(k-1)*c2[i];
	                sum=sum+compute(p,c2[i]);
	            }
	            cout<<sum<<"\n";
	        }
	    }
	}
	return 0;
}
