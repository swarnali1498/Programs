#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,c=0;
    printf("\nEnter length of string and pattern: ");
    scanf("%d%d",&n,&m);
    char s[n],p[m];
    printf("\nEnter string:");
    scanf("%s",s);
    printf("\nEnter pattern: ");
    scanf("%s",p);
    for(i=0;i<n-m+1;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i+j]==p[j])
            {
                c++;
            }
        }
        if(c==m)
        {
            printf("\nPattern occurs with shift %d",i);
        }
        c=0;
    }
    return 0;
}
