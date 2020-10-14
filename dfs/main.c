#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int color,pi,d,f,label;
}node;
typedef struct edge
{
    int id,v1,v2;
}edge;
int* dfs_visit(node** adj,int* deg_arr,node* vertex,int u,int* t,int n,edge* e)
{
    int i;
    node v;
    t[0]=t[0]+1;
    vertex[u].d=t[0];
    vertex[u].color=1;
    for(i=0;i<deg_arr[u];i++)
    {
      //  printf("\n(%d %d)",u+1,adj[u][i].label);
        v=adj[u][i];
        if(vertex[v.label-1].color==0)
        {
           e[t[1]].v1=u+1;
           e[t[1]].v2=v.label;
           e[t[1]].id=0;
           t[1]++;
           vertex[v.label-1].pi=u+1;
           t=dfs_visit(adj,deg_arr,vertex,v.label-1,t,n,e);
        }
        else if(vertex[v.label-1].color==1)
        {
           e[t[1]].v1=u+1;
           e[t[1]].v2=v.label;
           e[t[1]].id=1;
           t[1]++;
        }
        else
        {
           e[t[1]].v1=u+1;
           e[t[1]].v2=v.label;
           e[t[1]].id=2;
           t[1]++;
        }
    }
    vertex[u].color=2;
    t[0]=t[0]+1;
    vertex[u].f=t[0];
    return t;
}
int main()
{
    int i,j;
    FILE* fp=fopen("edge_list.txt","r");
    if(fp==NULL)
    {
        printf("\nFile not found");
        return;
    }
    int n=0,m=0,u,v;
    while(fscanf(fp,"%d%d",&u,&v)!=EOF)
    {
        m++;
        if(u>n)
            n=u;
        if(v>n)
            n=v;
    }
    fclose(fp);
    fp=fopen("edge_list.txt","r");
    int* deg_arr=(int*)calloc(n,sizeof(int));
    node** adj=(node**)malloc(n*sizeof(node*));
    while(fscanf(fp,"%d%d",&u,&v)!=EOF)
    {
       deg_arr[u-1]++;
    }
    for(i=0;i<n;i++)
    {
        adj[i]=(node*)malloc(deg_arr[i]*sizeof(node));
    }
    fclose(fp);
    fp=fopen("edge_list.txt","r");
    int* pos=(int*)calloc(n,sizeof(int));
    while(fscanf(fp,"%d%d",&u,&v)!=EOF)
    {
        adj[u-1][pos[u-1]].label=v;
        pos[u-1]++;
    }
    for(i=0;i<n;i++)
    {
        printf("%d : ",i+1);
        for(j=0;j<deg_arr[i];j++)
        {
            printf("%d ",adj[i][j].label);
        }
        printf("\n");
    }
    free(pos);
    node* vertex=(node*)malloc(n*sizeof(node));
    edge* e=(edge*)malloc(m*sizeof(edge));
    for(i=0;i<n;i++)
    {
        vertex[i].color=0;
        vertex[i].d=0;
        vertex[i].f=0;
        vertex[i].label=i+1;
        vertex[i].pi=-1;
    }
    int *t=(int*)calloc(2,sizeof(int));
    for(i=0;i<n;i++)
    {
        if(vertex[i].color==0)
            t=dfs_visit(adj,deg_arr,vertex,i,t,n,e);
    }
    for(i=0;i<n;i++)
    {
        printf("\nlabel=%d pi=%d d=%d f=%d color=%d",vertex[i].label,vertex[i].pi,vertex[i].d,vertex[i].f,vertex[i].color);
    }
    printf("\nEdges classified : ");
    for(i=0;i<m;i++)
    {
        if(e[i].id==0)
            printf("\nTree edge : (%d %d)",e[i].v1,e[i].v2);
        else if(e[i].id==1)
            printf("\nBack edge : (%d %d)",e[i].v1,e[i].v2);
        else
        {
            if(vertex[e[i].v1-1].d<vertex[e[i].v2-1].d)
                printf("\nForward edge : (%d %d)",e[i].v1,e[i].v2);
            else
                printf("\nCross edge : (%d %d)",e[i].v1,e[i].v2);
        }
    }
    return 0;
}
