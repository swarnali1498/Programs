#include <stdio.h>
#include <stdlib.h>

typedef struct node1
{
    int label;
    int rank;
    int p;
}node;
typedef struct edge
{
    int u;
    int v;
    int w;
}edge;
int find_set(int x,node* a)
{
    if(a[x-1].label!=a[x-1].p)
        a[x-1].p=find_set(a[x-1].p,a);
    return a[x-1].p;
}
void make_set(int x,node* a)
{
    a[x-1].p=x;
    a[x-1].rank=0;
}
void link(int x,int y,node* a)
{
    if(a[x-1].rank>a[y-1].rank)
    {
        a[y-1].p=x;
    }
    else
    {
        a[x-1].p=y;
        if(a[x-1].rank==a[y-1].rank)
            a[y-1].rank=a[y-1].rank+1;
    }
}
void Union(node x,node y,node* a)
{
    link(find_set(x.label,a),find_set(y.label,a),a);
}
int partition(edge* list,int p,int r)
{
    int i,j;
    i=p-1;
    edge t;
    for(j=p;j<=r-1;j++)
    {
        if(list[j].w<list[r].w)
        {
            i++;
            t=list[i];
            list[i]=list[j];
            list[j]=t;
        }
    }
    t=list[i+1];
    list[i+1]=list[r];
    list[r]=t;
    return i+1;
}
void quicksort(edge* list,int p,int r)
{
    if(p<r)
    {
        int q=partition(list,p,r);
        quicksort(list,p,q-1);
        quicksort(list,q+1,r);
    }
}
int main()
{
    int n=0,i=0,s,dest,w,max=0;
    FILE* fp=fopen("edge_list.txt","r");
    if(fp==NULL)
    {
        printf("\nFile cannot be found");
        return;
    }
    while(fscanf(fp,"%d%d%d",&s,&dest,&w)!=EOF)
    {
        n++;
        if(s<max)
            max=s;
        if(dest>max)
            max=dest;
    }
    fclose(fp);
    edge* list=(edge*)calloc(n,sizeof(edge));
    node* a=(node*)calloc(max,sizeof(node));
    edge* b=(edge*)calloc(n,sizeof(edge));
    fp=fopen("edge_list.txt","r");
    while(fscanf(fp,"%d%d%d",&s,&dest,&w)!=EOF)
    {
        list[i].u=s;
        list[i].v=dest;
        list[i].w=w;
        a[s-1].label=s;
        a[dest-1].label=dest;
        make_set(s,a);
        make_set(dest,a);
        i++;
    }
    n=i;
    fclose(fp);
    quicksort(list,0,n-1);
    int cost=0;
    for(i=0;i<n;i++)
    {
        if(find_set((list[i].u),a)!=find_set((list[i].v),a))
        {
            b[i]=list[i];
            Union(a[list[i].u-1],a[list[i].v-1],a);
            cost=cost+list[i].w;
            printf("%d-%d (%d)\n",list[i].u,list[i].v,list[i].w);
        }
    }
    printf("Cost is %d",cost);
    return 0;
}
