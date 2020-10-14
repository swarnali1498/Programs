#include <bits/stdc++.h>
using namespace std;
int isexists(int* ar,int a,int s,int n)
{
    int i;
    for(i=a+1;i<n;i++)
    {
        if(ar[i]==s)
        return i;
    }
    return 0;
}
int compute(int n)
{
    int i,sum=0;
    for(i=1;i<n;i++)
    {
        sum=sum+i;
    }
    return sum;
}
int main() {
	//code
	int t,n;
	cin>>t;
	if(t>=1 && t<=200)
	{
	    while(t--)
	    {
	        cin>>n;
	        if(n>=1 && n<=1000)
	        {
	            int i,j,*ar;
	            ar=(int*)malloc(n*sizeof(int));
	            for(i=0;i<n;i++)
	            cin>>ar[i];
	            int l=ar[n-1]-ar[0];
	            if(l==0)
	            cout<<n<<"\n";
	            else
	            {
	                int k,a[n][n];
	                l=compute(n);
	                int b[l];
	                for(i=0;i<n;i++)
	                {
	                    for(j=0;j<n;j++)
	                    {
	                        a[i][j]=0;
	                    }
	                }
	                for(i=0;i<l;i++)
	                b[i]=0;
	                for(i=0;i<n;i++)
	                {
	                 for(j=i+1;j<n;j++)
	                 {
	                     k=ar[j]-ar[i];
	                     a[i][j]=k;
	                 }
	                }
	                int m=0,c;
	                for(i=0;i<n;i++)
	                {
	                    for(j=i+1;j<n;j++)
	                    {
	                        c=1;
	                        k=1;
	                        k=isexists(ar,i,(a[i][j]+ar[i]),n);
	                        while(1)
	                        {
	                            if(k==0)
	                            {
	                                b[m++]=c;
	                                break;
	                            }
	                            else
	                            {
	                                c++;
	                                k=isexists(ar,k,(a[i][j]+ar[k]),n);
	                            }
	                        }
	                    }
	                }
                    int max=b[0];
	                for(i=0;i<l;i++)
	                {
	                    if(b[i]>max)
	                    max=b[i];
	                }
	                cout<<max<<"\n";
	            }
	        }
	    }
	}
	return 0;
}
