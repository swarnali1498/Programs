#include <bits/stdc++.h>
using namespace std;
void func(int* p)
{
    int max=p[0],min=p[0],i;
    for(i=1;i<3;i++)
    {
        if(p[i]>max)
        max=p[i];
        if(p[i]<min)
        min=p[i];
    }
    int r=0;
    for(i=0;i<3;i++)
    {
        if(p[i]==max||p[i]==min)
        {
           // if(i!=0 && p[0]!=p[i])
            {
                p[r++]=p[i];
            }

        }
      //  else
        //{
            /*if(p[i]==38)
            {
                int j;
                for(j=0;j<3;j++)
                cout<<p[j]<<" ";
            }*/
            //cout<<p[i]<<" ";
        //}
    }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	if(t>=1 && t<=74)
	{
	    while(t--)
        {
            int n,i,z;
            cin>>n;
            if(n>=3 && n<=19)
            {
                int* ar=(int*)malloc(n*sizeof(int));
                int* p=(int*)malloc(3*sizeof(int));
                for(i=0;i<n;i++)
                {
                    cin>>z;
                    if(z>=0 && z<=109)
                    {
                        ar[i]=z;
                    }
                }
                p[0]=ar[0];
                p[1]=ar[1];
                p[2]=ar[2];
                for(i=2;i<n;i++)
                {
                    p[2]=ar[i];
                    func(p);
                }
                //cout<<"\n";
                for(i=0;i<2;i++)
                {
                    cout<<p[i]<<" ";
                }
                cout<<"\n";
            }
        }
	}
	return 0;
}





#include <bits/stdc++.h>
using namespace std;
int func(long long n,int c)
{
    if(n%10!=0 && n%20!=0)
    return 0;

    else if(n==10 || n==20)
    {
        return 1;
    }
    else if(n==0)
    return 0;
    else
    {
        c=func(n/10,c)+func(n/20,c);
    }
    return c;
}
int main() {
	// your code goes here
	int t;
	long long n;
	cin>>t;
	if(t>=1 && t<=100)
	{
	    while(t--)
	    {
	        cin>>n;
	        if(n>=1 && n<=1000000000000000000)
	        {
	            int c=0;
	            c=func(n,c);
	            if(c)
	            cout<<"Yes"<<"\n";
	            else
	            cout<<"No"<<"\n";
	        }
	    }
	}
	return 0;
}

