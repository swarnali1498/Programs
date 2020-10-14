#include <iostream>
using namespace std;
long int min(long int a,long int b,long int c,long int d)
{
    if(a<=b && a<=c && a<=d)
    return a;
    else if(b<=a && b<=c && b<=d)
    return b;
    else if(c<=a && c<=b && c<=d)
    return c;
    else
    return d;
}
int main() {
	int t,z;
	cin>>t;
	for(z=0;z<t;z++)
	{
	    int n,m,i,j,k,l;
	    cin>>n>>m;
	    long int ar[n][m],c=0;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            cin>>ar[i][j];
	        }
	    }
	    for(i=1;i<n-1;i++)
	    {
	        for(j=1;j<m-1;j++)
	        {
	            k=min(i,j,n-i-1,m-j-1);
	            for(l=1;l<=k;l++)
	            {
	                if(ar[i-l][j]==ar[i+l][j] && ar[i][j-l]==ar[i][j+l])
	                {
	                    c++;
	                }
	            }
	        }
	    }
	    cout<<c+m*n<<endl;
	}
	return 0;
}
