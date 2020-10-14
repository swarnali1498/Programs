/*#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  float l;
  cin>>l;
  float t=(n*l)/360;
  int h=(int)t;
  int m=(int)((t-h)*60);
  int hr=h*5;
  int d;
  if(hr>m)
    d=hr-m;
  else
    d=m-hr;
   //cout<<d<<endl;
  float ans=d*((float)360/(n*5));
  if(360-ans<ans)
    ans=360-ans;
  cout<<fixed;
  cout<<setprecision(2);
  cout<<ans;
  //cout<<360-25.3<<endl;
  //printf("%0.2f",ans);
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int a,b;
  	cin>>a>>b;
  	long int i,j,r,k1=0,k2=0,ar1[10],ar2[10],temp[10],pos;
  	while(a!=0)
    {
      r=a%10;
      a=a/10;
      temp[k1++]=r;
    }
  	for(i=0;i<k1;i++)
    {
      ar1[i]=temp[k1-1-i];
    }
  	while(b!=0)
    {
      r=b%10;
      b=b/10;
      temp[k2++]=r;
    }
  	for(i=0;i<k2;i++)
    {
      ar2[i]=temp[k2-1-i];
    }
  	int min=10,f=0;
  	for(i=0;i<k2;i++)
    {
      min=10;
      for(j=0;j<k1;j++)
      {
        if(ar1[j]>=ar2[i] && ar1[j]<min)
        {
          min=ar1[j];
          pos=j;
        }
      }
      if(min==10)
      {
        f=1;
        break;
      }
      temp[i]=min;
      ar1[pos]=10;
    }
  	if(f==1)
    {
      cout<<-1;
    }
  	else
    {
      for(i=0;i<k1;i++)
        cout<<temp[i];
    }
}
