#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,ar[3],c=3;
    printf("\nEnter n : ");
    scanf("%d",&n);
    ar[0]=1;
    ar[1]=1;
    ar[2]=n-2;
    int max=1;
    while(1)
    {
        if(ar[2]>ar[1])
        {
            ar[2]--;
            ar[1]++;
        }
        else
        {
            if(ar[1]>ar[0])
            {
                ar[1]--;
                ar[0]++;

            }
            else
            {
                break;
            }
        }
        if(ar[1]>ar[0])
            {
                if(ar[1]>ar[2])
                {
                    max=ar[1];
                }
                else
                {
                    max=ar[2];
                }
            }
            else
            {
                max=ar[0];
            }
            if((ar[0]==ar[1]&&ar[0]!=max)||(ar[1]==ar[2]&&ar[1]!=max)||(ar[0]==ar[2]&&ar[0]!=max))
                {
                    printf("\n%d %d %d %d",ar[0],ar[1],ar[2],max);
                    c=c+3;
                }
                else if(ar[0]!=ar[1] && ar[1]!=ar[2] && ar[2]!=ar[0])
                {
                    if(ar[1]<ar[2])
                    {
                    printf("\n(6)%d %d %d",ar[0],ar[1],ar[2]);
                    c=c+6;
                    }
                }
                max=1;
    }
    printf("\n%d",c);
    return 0;
}
