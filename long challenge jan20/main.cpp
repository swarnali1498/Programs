#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t,z,n,res,i;
	cin>>t;
	for(z=0;z<t;z++)
	{
	    long long int m=1,sum,a,b,d;
	    cin>>n;
	    for(i=1;i<=n;i++)
            m=m*10;
	    //cout<<m<<" ";
	    cin>>a;
	    sum=2*m+a;
	    //cout<<m<<" "<<a<<" "<<pow(10,n)<<endl;
	    cout<<sum<<endl<<flush;
	    //fflush(stdout);
	    cin>>b;
	    //cout<<endl<<m<<" "<<b<<endl;
	    cout<<m-b<<endl<<flush;
	    //fflush(stdout);
	    cin>>d;
	    cout<<m-d<<endl<<flush;
	    //fflush(stdout);
	    cin>>res;
	    if(res==-1)
	    exit(-1);
	}
	return 0;
}

