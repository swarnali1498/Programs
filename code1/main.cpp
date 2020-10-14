#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    long int ar[n],y,i,j;
  	for(i=0;i<n;i++)
    {
      cin>>ar[i];
    }
  	i=0;
  	long int m=0;
    for(i=0;i<n;i++)
    {
        m=max(ar[i],m);
    }
    long int bits=log2(m);
    bits++;
    vector <long int> vect;
    long int k=0,o,z,c=0;
    vector <long int>::iterator itr2;
    for(long int b=0;b<(1<<n);b++)
    {
        for(i=0;i<n;i++)
        {
            if(b&(1<<i))
                vect.push_back(ar[i]);
        }
        o=0;z=0;
      	for(itr2=vect.begin();itr2!=vect.end();itr2++)
        {
            long int a=__builtin_popcount(*itr2);
            long int b=bits-a;
            o+=a;
            z+=b;
        }
        if(o==0 && z==0)
            continue;
        else if(o==z)
            c++;
        vect.clear();
    }
    k=0;
    string bin="";
    while(c>0)
    {
      	char ch=(char)((c%2)+48);
        bin=ch+bin;
        k++;
        c=c/2;
    }
    for(;k<bits;k++)
        bin='0'+bin;
    for(i=0;i<k;i++)
    {
        cout<<(int)bin[i]-48;
    }
    cout<<endl;
  	return 0;
}
