#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=3,i,j;
    vector <int> vect;
    long int ar[]={1,2,3};
    //cout << (1<<i) << endl;
    for(i=0;i<(1<<n);i++)
    {
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))
                vect.push_back(ar[j]);
        }
        for(j=0;j<vect.size();j++)
        cout<<vect[j]<<" ";
        cout<<endl;
        vect.clear();
    }
    for(i=0;i<vect.size();i++)
        cout<<vect[i]<<" ";
    cout<<endl;
    return 0;
}
