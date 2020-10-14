#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	if(t>=1 && t<=100)
	{
	    while(t--)
	    {
	        long int n;
	        cin>>n;
	        if(n>=1 && n<=10000000)
	        {
	            long int i,ar[n],z;
	            for(i=0;i<n;i++)
	            {
	                cin>>z;
	                if(z>=0 && z<=10000000)
	                {
	                    ar[i]=z;
	                }
	            }
	            i=0;
	            long int c=0;
	            while(1)
	            {
	                if(ar[i]==0)
	                {
	                    cout<<-1;
	                    return 0;
	                }
	                if(i+ar[i]>=n-1)
                    {
                        c++;
                        break;
                    }
	                else
	                {
	                    long int m=0,j,pos;
	                    for(j=i+1;j<i+1+ar[i];j++)
	                    {
	                        if(ar[j]>m)
	                        {

	                            m=ar[j];
	                            pos=j;
	                            cout<<m<<" "<<pos<<"\n";
	                        }
	                    }
	                    i=pos;
	                    c++;
	                }
	            }
	            cout<<c<<"\n";
	        }
	    }
	}
	return 0;
}
