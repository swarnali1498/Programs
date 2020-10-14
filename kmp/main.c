#include <stdio.h>
#include <stdlib.h>
int* compute_prefix_function(char* p,int m)
{
    int* pi=(int*)calloc(m,sizeof(int));
    int k=0,q;
    for(q=1;q<m;q++)
    {
        while(k>0 && p[k]!=p[q])
        {
            k=pi[k];
        }
        if(p[k]==p[q])
        {
            k++;
        }
        pi[q]=k;
    }
    return pi;
}
void kmp_matcher(char* t,char* p,int n,int m)
{
    int* pi,i;
    pi=compute_prefix_function(p,m);
    int q=0;
    for(i=0;i<n;i++)
    {
        while(q>0 && p[q]!=t[i])
        {
            q=pi[q-1];
        }
        if(p[q]==t[i])
        {
            q++;
        }
        if(q==m)
        {
            printf("\nPattern occurs with shift %d",i-m+1);
            q=pi[q-1];
        }
    }
}
int main()
{
    int n,m;
    printf("\nEnter length of string and pattern:\n");
    scanf("%d%d",&n,&m);
    char* t=(char*)malloc(n*sizeof(char));
    char* p=(char*)malloc(m*sizeof(char));
    printf("\nEnter string and pattern:\n");
    scanf("%s",t);
    scanf("%s",p);
    kmp_matcher(t,p,n,m);
    return 0;
}
