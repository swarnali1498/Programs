#include <bits/stdc++.h>
using namespace std;

int main()
{
    int minh,maxh,minw,maxw,i,j,h,w,c=0;
    cin>>minh>>maxh>>minw>>maxw;
    //cout<<minh<<maxh<<minw<<maxw<<endl;
    for(h=minh;h<=maxh;h++)
    {
        for(w=minw;w<=maxw;w++)
        {
            i=h;
            j=w;
            while(i!=0 && j!=0)
            {
                if(i>j)
                {
                    i=i-j;
                }
                else
                {
                    j=j-i;
                }
                c++;
              //  cout<<c<<endl;
            }
        }
    }
    cout<<c;
    return 0;
}
