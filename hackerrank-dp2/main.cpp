#include<bits/stdc++.h>
using namespace std;
/*int main()
{
    int t,z,k=0,p,q,i,d;
    char a[1005],b[1005];
    cin>>t;
    for(z=0;z<t;z++)
    {
        cin>>a;
        cin>>b;
        p=strlen(a);
        q=strlen(b);
        int f=0,k=0,c=1,d1=1,d2=1;
        for(i=0;i<p;i++)
        {
            //cout<<(int)a[i]<<" ";
            c=1;d1=1;d2=1;
            if(a[i]==b[k] || a[i]==b[k]+32)
            {
                int count1=k,count2=0;
                    while(b[count1+1]==b[count1])
                    {
                        c++;
                        count1++;
                    }
                    while(a[i+1]==a[i] || a[i+1]==a[i]-32)
                    {
                        if(a[i+1]==a[i]-32)
                        d1++;
                        else
                        d2++;
                        i++;
                        count2=1;
                    }
                    if(c>d1+d2 && count2==1)
                    {
                        cout<<"NO"<<endl;//<<" "<<c<<" "<<d1<<" "<<d2<<endl;
                        break;
                    }
                    else if(c<=d1+d2 && count2==1)
                    {
                        k=count1;
                        //cout<<k<<" "<<count1<<endl;
                    }
                    k++;
            }
            else if((int)(a[i])<97 || (int)(a[i])>122)
            {
               // cout<<a[i]<<k<<endl;
                cout<<"NO"<<endl;//<<" a[i]= "<<a[i]<<" i= "<<i<<endl;
                f=1;
                break;
            }
        }
       // cout<<k<<q<<f<<endl;
        if(k==q && f==0)
        cout<<"YES"<<endl;
        else if(k!=q && f==0)
        cout<<"NO"<<endl;//<<" k= "<<k<<" q= "<<q<<endl;
    }
}*/

#include<bits/stdc++.h>
using namespace std;
int check(char a[],char b[],int i,int j,int p,int q)
{
    if(i==p && j==q)
    return 1;
    else if(a[i]==b[j])
    {
        return check(a,b,i+1,j+1,p,q);
    }
    else if(a[i]==b[j]+32)
    {
        int c,d;
        c=check(a,b,i+1,j+1,p,q);
        if(c==0)
        {
            d=check(a,b,i+1,j,p,q);
            return d;
        }
        return c;
    }
    else if((int)a[i]>=97 && (int)a[i]<=122)
    {
        return check(a,b,i+1,j,p,q);
    }
    else
    {
        //cout<<a[i]<<" "<<i<<" "<<b[j]<<" "<<j<<endl;
        return 0;
    }
}
int main()
{
    int t,z,k=0,p,q,i,d;
    char a[1005],b[1005];
    cin>>t;
    for(z=0;z<t;z++)
    {
        cin>>a;
        cin>>b;
        p=strlen(a);
        q=strlen(b);
        d=check(a,b,0,0,p,q);
        if(d)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}


/*int f=0,k=0,c=1,d1=1,d2=1;
        for(i=0;i<p;i++)
        {
            //cout<<(int)a[i]<<" ";
            c=1;d1=1;d2=1;
            if(a[i]==b[k] || a[i]==b[k]+32)
            {
                int count1=k,count2=0;
                    while(b[count1+1]==b[count1])
                    {
                        c++;
                        count1++;
                    }
                    while(a[i+1]==a[i] || a[i+1]==a[i]-32)
                    {
                        if(a[i+1]==a[i]-32)
                        d1++;
                        else
                        d2++;
                        i++;
                        count2=1;
                    }
                    if(c>d1+d2 && count2==1)
                    {
                        cout<<"NO"<<" "<<c<<" "<<d1<<" "<<d2<<endl;
                        break;
                    }
                    else if(c<=d1+d2 && count2==1)
                    {
                        k=count1;
                        cout<<k<<" "<<count1<<endl;
                    }
                    k++;
            }
            else if((int)(a[i])<97 || (int)(a[i])>122)
            {
               // cout<<a[i]<<k<<endl;
                cout<<"NO"<<" a[i]= "<<a[i]<<" i= "<<i<<" "<<k<<" "<<b[k]<<endl;
                f=1;
                break;
            }
        }
       // cout<<k<<q<<f<<endl;
        if(k==q && f==0)
        cout<<"YES"<<endl;
        else if(k!=q && f==0)
        cout<<"NO"<<" k= "<<k<<" q= "<<q<<endl;*/
