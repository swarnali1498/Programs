/*#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,q,i,l,r,j,c1=0,c2=0,p=0,s=0;
	cin>>n>>q;
	long int ar[n];
	for(i=0;i<n;i++)
	{
	    cin>>ar[i];
	}
	for(i=0;i<q;i++)
	{
	    cin>>l>>r;
	    c1=0; c2=0; p=0; s=0;
	    for(j=l-1;j<r-1;j++)
	    {
	        if(ar[j]<ar[j+1])
	        {
	            p++;
	        }
	        else
	        {
	            if(p>0)
	            {
	                c1++;
	                p=0;
	            }
	        }
	        if(ar[j]>ar[j+1])
	        {
	            s++;
	        }
	        else
	        {
	            if(s>0)
	            {
	                c2++;
	                s=0;
	            }
	        }
	    }
	    if(p>0)
	    c1++;
	    if(s>0)
	    c2++;
	    if(c1==c2)
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	      //  cout<<c1<<" "<<c2<<endl;
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,q,i,l,r,j,c1=0,c2=0,p=0,s=0;
	cin>>n>>q;
	long int ar[n],ar1[n],ar2[n];
	for(i=0;i<n;i++)
	{
	    cin>>ar[i];
	    ar1[i]=0;
	    ar2[i]=0;
	}
	for(j=0;j<n-1;j++)
	{
	    if(ar[j]<ar[j+1])
	        {
	            p++;
	            ar1[j]=c1+1;
	        }
	        else
	        {
	            if(p>0)
	            {
	                ar1[j]=c1+1;
	                c1++;
	                p=0;
	            }
	        }
	        if(ar[j]>ar[j+1])
	        {
	            s++;
	            ar2[j]=c2+1;
	        }
	        else
	        {
	            if(s>0)
	            {
	                ar2[j]=c2+1;
	                c2++;
	                s=0;
	            }
	        }
	}
	if(p>0)
        ar1[j]=c1+1;
    if(s>0)
        ar2[j]=c2+1;
	cout<<"ar1"<<endl;
	for(i=0;i<n;i++)
    {
        cout<<ar1[i]<<" ";
    }
    cout<<endl;
    cout<<"ar1"<<endl;
	for(i=0;i<n;i++)
    {
        cout<<ar2[i]<<" ";
    }
    cout<<endl;
	int inc=0,dec=0,u,v;
	for(i=0;i<q;i++)
	{
	    int l1,r1;
	    cin>>l>>r;
	    l1=l; r1=r;
	    l--; r--;
	    while(ar1[l]==0)
        {
            l++;
        }
        while(ar1[r]==0)
        {
            r--;
        }
	    if(ar1[l]==ar1[l+1] && ar1[r]==ar1[r-1])
        {
            inc=ar1[r]-ar1[l]+1;
        }
        else if(ar1[l]==ar1[l+1] && ar1[r]!=ar1[r-1] || ar1[l]!=ar1[l+1] && ar1[r]==ar1[r-1])
        {
            inc=ar1[r]-ar1[l];
        }
        else if(ar1[l]!=ar1[l+1] && ar1[r]!=ar1[r-1])
        {
            inc=0;
        }
        l=l1; r=r1;
        l--; r--;
        while(ar2[l]==0)
        {
            l++;
        }
        while(ar2[r]==0)
        {
            r--;
        }
	    if(ar2[l]==ar2[l+1] && ar2[r]==ar2[r-1])
        {
            dec=ar2[r]-ar2[l]+1;
        }
        else if(ar2[l]==ar2[l+1] && ar2[r]!=ar2[r-1] || ar2[l]!=ar2[l+1] && ar2[r]==ar2[r-1])
        {
            dec=ar2[r]-ar2[l];
        }
        else if(ar2[l]!=ar2[l+1] && ar2[r]!=ar2[r-1])
        {
            dec=0;
        }
	    if(inc==dec)
	    {
	        //cout<<inc<<" "<<dec<<endl;
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	        //cout<<inc<<" "<<dec<<endl;
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}

