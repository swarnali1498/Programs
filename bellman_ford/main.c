#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct edge
{
    int u;
    int v;
    int w;
}edge;
typedef struct vertex
{
    int label;
    int d;
    int p;
}vertex;
void relax(int u,int v,int w,vertex* a)
{
    if(a[v-1].d>a[u-1].d+w)
    {
        a[v-1].d=a[u-1].d+w;
        a[v-1].p=u;
    }
}
void print_path(int v,vertex* a)
{
    if(v!=0)
    {
        print_path(a[v].p-1,a);
        printf("->%d",v+1);
    }
}
int main()
{
    int n=0,i=0,j,s,dest,w,max=0;
    FILE* fp=fopen("edge_list.txt","r");
    if(fp==NULL)
    {
        printf("\nFile cannot be found");
        return;
    }
    while(fscanf(fp,"%d%d%d",&s,&dest,&w)!=EOF)
    {
        n++;
        if(s>max)
            max=s;
        if(dest>max)
            max=dest;
    }
    fclose(fp);
    edge* list=(edge*)calloc(n,sizeof(edge));
    vertex* a=(vertex*)calloc(max,sizeof(vertex));
    fp=fopen("edge_list.txt","r");
    while(fscanf(fp,"%d%d%d",&s,&dest,&w)!=EOF)
    {
        list[i].u=s;
        list[i].v=dest;
        list[i].w=w;
        i++;
        a[s-1].label=s;
        a[s-1].d=INT_MAX;
        a[s-1].p=-1;
    }
    fclose(fp);
    a[0].d=0;
    for(i=0;i<max-1;i++)
    {
        for(j=0;j<n;j++)
        {
            relax(list[j].u,list[j].v,list[j].w,a);
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[list[i].v-1].d>a[list[i].u-1].d+list[i].w)
        {
            printf("\nNegative weight cycle present. Bellman Ford algorithm not applicable.");
            return;
        }
    }
    for(i=0;i<max;i++)
    {
        printf("%d(%d) %d\n",a[i].label,a[i].p,a[i].d);
    }
    int v;
    printf("\nEnter destination vertex:");
    scanf("%d",&v);
    printf("1");
    print_path(v-1,a);
    printf("\nPath weight is %d",a[v-1].d);
    return 0;
}
