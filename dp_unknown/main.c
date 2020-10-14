#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,k,i,j,m=0,b=0,sum=0;
    printf("\nEnter number of test cases:");
    scanf("%d",&t);
  //  for(i=1;i<=t;i++)
    {
        printf("\nEnter n and k:");
        scanf("%d%d",&n,&k);
        int a[n],s[n];
        printf("\nEnter array:");
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        while(m<n)
        {
            while(a[m]<0)
            {
                m++;
            }
            sum=a[m];
            printf("\n");
            printf("%d + ",a[m]);
            for(j=m+k+1;j<n;)
            {
                if(a[j]>0)
                {
                    printf("%d + ",a[j]);
                    sum=sum+a[j];
                    j=j+k+1;
                }
                else
                    j++;
            }
            printf("=%d",sum);
            s[b++]=sum;
            m++;
        }
        int max=s[0];
        for(j=0;j<b;j++)
        {
            printf("\n%d",s[j]);
            if(s[j]>max)
                max=s[j];
        }
        printf("\nmax=%d",max);
    }
    return 0;
}
