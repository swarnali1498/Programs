/*#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        else
            return c;
    }
    else
    {
        if(b<c)
            return b;
        else
            return c;
    }
}
/*int check(string str1,string str2,int m,int n,int i,int j)
{
    if(i==m||j==n)
    {
        return 0;
    }
    else if(str1[i]==str2[j])
    {
        return check(str1,str2,m,n,i+1,j+1);
    }
    else
    {
        return min(1+check(str1,str2,m,n,i,j+1),1+check(str1,str2,m,n,i+1,j));
    }
}*/
/*int main() {
    int t,p,q;
    string str1,str2;
    //cout<<"Enter number of test cases : "<<"\n";
    //cin>>t;
    //if(t>=1 && t<=50)
    {
       // while(t--)
        {
            cout<<"Enter length of strings";
            cin>>p>>q;
            if(p>=1 && q>=1 && p<=100 && q<=100)
            {
                cout<<"Enter strings"<<"\n";
                cin>>str1;
	            cin>>str2;
	            int a[p][q],i,j;
	            for(i=0;i<p;i++)
                {
                    a[i][0]=i;
                }
                for(i=0;i<q;i++)
                {
                    a[0][i]=i;
                }
                for(i=1;i<p;i++)
                {
                    for(j=1;j<q;j++)
                    {
                        if(str1[i]==str2[j])
                        {
                            a[i][j]=a[i-1][j-1];
                        }
                        else
                        {
                            a[i][j]=min(a[i][j-1],a[i-1][j],a[i-1][j-1])+1;
                        }
                    }
                }
                for(i=0;i<p;i++)
                {
                    for(j=0;j<q;j++)
                    {
                        cout<<a[i][j]<" ";
                    }
                    cout<<"\n";
                }
	            cout<<a[p-1][q-1];
            }
        }

    }
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        else
            return c;
    }
    else
    {
        if(b<c)
            return b;
        else
            return c;
    }
}
int main() {
    int t,p,q;
    string str1,str2;
 //   cout<<"Enter t";
    cin>>t;
    if(t>=1 && t<=50)
    {
        while(t--)
        {
   //         cout<<"Enter p and q";
            cin>>p>>q;
            if(p>=1 && q>=1 && p<=100 && q<=100)
            {
     //           cout<<"Enter strings";
                cin>>str1;
	            cin>>str2;
	            int a[p+1][q+1],i,j;
	            for(i=0;i<p+1;i++)
                {
                    a[i][0]=i;
                }
                for(i=0;i<q+1;i++)
                {
                    a[0][i]=i;
                }
                for(i=1;i<p+1;i++)
                {
                    for(j=1;j<q+1;j++)
                    {
                        if(str1[i-1]==str2[j-1])
                        {
                            a[i][j]=a[i-1][j-1];
                        }
                        else
                        {
                            a[i][j]=min(a[i][j-1],a[i-1][j],a[i-1][j-1])+1;
                        }
                    }
                }
                 /* for(i=0;i<p+1;i++)
                {
                    for(j=0;j<q+1;j++)
                    {
                        cout<<a[i][j]<<" ";
                    }
                    cout<<"\n";
                }*/
	            cout<<a[p][q]<<"\n";
            }
        }
    }
	return 0;
}
