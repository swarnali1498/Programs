#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char ar[n][n],ar1[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ar1[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ar[i][j]!=ar1[i][j])
            {
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    return 0;
}
