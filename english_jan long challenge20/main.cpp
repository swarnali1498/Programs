#include <bits/stdc++.h>
using namespace std;
long int compute_i(long int max[],long int n)
{
    long int pos=0,i,maximum=0;
    for(i=0;i<n;i++)
    {
        if(max[i]>=maximum)
        {
            pos=i;
            maximum=max[i];
          //  cout<<"pos="<<pos<<endl;
        }
    }
    return pos;
}
long int compute(char* a,char* b)
{
    long int min,pr=0,su=0,i,m,n;
    m=strlen(a);
    n=strlen(b);
    i=0;
    while(i<m && i<n)
    {
        if(a[i]==b[i])
        pr++;
        else
            break;
        i++;
    }
    i=m-1;
    long int j=n-1;
    while(i>=0 && j>=0)
    {
        if(a[i]==b[j])
        su++;
        else
            break;
        i--;
        j--;
    }
   // cout<<pr<<" "<<su<<endl;
    if(pr<=su)
    min=pr;
    else
    min=su;
    return min*min;
}
int main()
{
    long int t,z,n,i,j;
    cin>>t;
    for(z=0;z<t;z++)
    {
        cin>>n;
        char ar[n][100005],s[100005];
        long int ar1[n],pre[n][n];
        /*ar=(char**)malloc(n*sizeof(char*));
        for(i=0;i<n;i++)
        {
            ar[i]=(char*)malloc(100000*sizeof(char));
        }*/
        for(i=0;i<n;i++)
        {
            cin>>s;
            int l=strlen(s);
            for(j=0;j<l;j++)
            {
                ar[i][j]=s[j];
            }
            ar[i][j]=NULL;
            //cout<<ar[i]<<endl;
            ar1[i]=0;
        }
        /*for(i=0;i<n;i++)
        {
            cout<<ar[i]<<" "<<ar1[i]<<" "<<strlen(ar[i])<<endl;
        }*/
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    pre[i][j]=compute(ar[i],ar[j]);
                }
                else
                {
                    pre[i][j]=0;
                }
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<pre[i][j]<<" ";
            }
            cout<<endl;
        }*/
        long int max[n];
        for(i=0;i<n;i++)
        {
            long int maximum1=0,position=0;
            for(j=0;j<n;j++)
            {
                if(pre[i][j]>=maximum1)
                {
                    maximum1=pre[i][j];
                 //   position=j;
                }
            }
            max[i]=maximum1;
        }

        /*for(i=0;i<n;i++)
        cout<<ar1[i]<<" ";
        cout<<endl;
        /*long int sum=0;
        for(i=0;i<n;i=i+2)
        {
            sum=sum+max[i];
        }
        cout<<sum<<endl;*/
        long int sum=0,counter=0;

        i=compute_i(max,n);
        while(counter<n/2)
        {
            //cout<<counter<<" "<<i<<endl;
            long int maximum=-1,pos=0,f=0;

            {
                for(j=0;j<n;j++)
                {
                    if(maximum<=pre[i][j] && ar1[j]==0 && i!=j)
                    {
                      //  cout<<"max="<<max<<" pre[i][j]="<<pre[i][j]<<" i="<<i<<" j="<<j<<endl;
                        maximum=pre[i][j];
                        pos=j;
                        f=1;
                    }
                }
                //if(f==1)
                {
                    ar1[pos]=-1;
                    ar1[i]=-1;
                    max[pos]=-1;
                    max[i]=-1;
                }
              //  if(f==1)
                sum=sum+maximum;
              //  cout<<maximum<<" "<<f<<endl;
                i=compute_i(max,n);
              /*  for(j=0;j<n;j++)
                {
                    cout<<max[j]<<" ";
                }
                cout<<endl;*/
                /*long int d=0;
                for(i=0;i<n;i++)
                {
                    if(max[i]==-1)
                    d++;
                }
                if(d==n)
                break;*/
                counter++;
                //cout<<i<<" "<<pos<<" "<<ar1[i]<<ar1[pos]<<endl;
            }
        }
        cout<<sum<<endl;
    }
	return 0;
}
