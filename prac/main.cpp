#include <iostream>

using namespace std;
int func(int a)
{
    if(a>5)
    {
        cout<<a<<endl;
        return a;
    }
    else
    {
        cout<<2*a<<endl;
        return 2*a;
    }
}
int min(int a,int b,int c,int d)
{
    if(a<b && a<c && a<d)
    return a;
    else if(b<a && b<c && b<d)
    return b;
    else if(c<a && c<b && c<d)
    return c;
    else
    return d;
}
int main()
{
    int count=min(func(-2),func(7),func(1),func(4));
    cout<<count<<endl;
    return 0;
}
