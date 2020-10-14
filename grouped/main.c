#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int i,n;
    printf("\nEnter limit: ");
    scanf("%d",&n);
    float a[n][2],x[n],mean,s=0,f[n],cf[n],sum=0;
    printf("\nEnter upper and lower limit: ");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&a[i][0],&a[i][1]);
        x[i]=(a[i][0]+a[i][1])/2;
    }
    printf("\nEnter corresponding frequencies:");
    for(i=0;i<n;i++)
    {
        scanf("%f",&f[i]);
        sum=sum+f[i];
        cf[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        s=s+f[i]*x[i];
    }
    mean=s/cf[n-1];
    printf("\nMean is %f",mean);
    s=cf[n-1]/2;
    i=0;
    while(cf[i]<s)
    {
        i++;
    }
    s=a[i][0]+((s-cf[i-1])*(a[i][1]-a[i][0]))/f[i];
    printf("\nMedian is %f",s);
    int max=f[0],pos=0;
    for(i=0;i<n;i++)
    {
        if(f[i]>max)
        {
            max=f[i];
            pos=i;
        }
    }
    s=a[pos][0]+((f[pos]-f[pos-1])*(a[pos][1]-a[pos][0]))/(2*f[pos]-f[pos+1]-f[pos-1]);
    printf("\nMode is %f ",s);
    s=0;
    for(i=0;i<n;i++)
    {
        s=s+f[i]*pow((x[i]-mean),2);
    }
    sum=sqrt(s/cf[n-1]);
    printf("\nStandard deviation is %f",sum);
    return 0;
}
