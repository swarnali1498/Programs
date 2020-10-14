#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[10000];
        cin>>s;
        int n=strlen(s);
        int k,k1,x;
        cin>>k>>x;
        k1=k;
        int i;
        int ar[26]={0};
        for(i=0;i<n;i++)
        {
            int index=(int)(s[i])-97;
            if(ar[index]==x && k==0)
            break;
            else if(ar[index]==x && k>0)
            {
                k--;
            }
            else
            ar[index]++;
        }
        if(k!=k1)
        cout<<i-k1<<endl;
        else
        cout<<i<<endl;
    }
	return 0;
}
