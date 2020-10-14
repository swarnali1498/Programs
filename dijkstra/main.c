#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
	int v;
	int w;
}node;

typedef struct heap
{
	int index;
	int key;
	int pi;
}heap;
void print_path(int v,heap* s)
{
    if(v!=0)
    {
        print_path(s[v].pi-1,s);
        printf("->%d",v+1);
    }
}
void min_heapify(heap* tree,int* heap_pos,int n,int i)
{
	heap t;
	int l,r,min;
	l=2*i+1;
	r=2*i+2;
	if(r<n && tree[r].key<tree[i].key)
		min=r;
	else
		min=i;
	if(l<n && tree[l].key<tree[min].key)
		min=l;
	if(min!=i)
	{
		t=tree[i];
		tree[i]=tree[min];
		tree[min]=t;
		heap_pos[tree[i].index-1]=i;
		heap_pos[tree[min].index-1]=min;
		min_heapify(tree,heap_pos,n,min);
	}
}
void see_heap(heap* tree,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n%d %d %d",tree[i].index,tree[i].key,tree[i].pi);
	}
}
void heap_decrease_key(heap* tree,int* heap_pos,int i,int k)
{
	heap t;
	tree[i].key=k;
	while(i>0 && tree[i/2].key>tree[i].key)
	{
		t=tree[i];
		tree[i]=tree[i/2];
		tree[i/2]=t;
		heap_pos[tree[i].index-1]=i;
		heap_pos[tree[i/2].index-1]=i/2;
		i=i/2;
	}
}
heap extract_min(heap* tree,int* heap_pos,int n)
{
	heap min;
	if(n<1)
	{
		printf("\nUnderflow");
		return;
	}
	min=tree[0];
	tree[0]=tree[n-1];
	tree[n-1]=min;
	heap_pos[tree[0].index-1]=0;
	heap_pos[tree[n-1].index-1]=n-1;
	n--;
	min_heapify(tree,heap_pos,n,0);
	return min;
}
void relax(heap u,heap v,int w,int* heap_pos,heap* tree)
{
    if(v.key>u.key+w)
    {
        heap_decrease_key(tree,heap_pos,heap_pos[v.index-1],u.key+w);
        tree[heap_pos[v.index-1]].pi=u.index;
    }
}
int findN(void)
{
	int n=1,temp1,temp2,temp3;
	FILE* fp=fopen("edge_list.txt","r");
	if(fp==NULL)
	{
		printf("\nFile not found");
		return;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d\n",&temp1,&temp2,&temp3);
		if(temp1>n)
		n=temp1;
		if(temp2>n)
		n=temp2;
	}
	fclose(fp);
	return n;
}
void print(node** adj_list,int* deg_arr,int n)
{
	int i,j;
	printf("Adjacency list\n");
	for(i=0;i<n;i++)
	{
		printf("%d (%d) : ",(i+1),deg_arr[i]);
		for(j=0;j<deg_arr[i];j++)
		{
			printf(" %d %d \t",adj_list[i][j].v,adj_list[i][j].w);
		}
		printf("\n");
	}
}
int main()
{
	int n,i,j,max=0,temp,k=0;
	n=findN();
	int *deg_arr=(int*)calloc(n,sizeof(int));
	int *heap_pos=(int*)malloc(n*sizeof(int));
	FILE* fp=fopen("edge_list.txt","r");
	if(fp==NULL)
	{
		printf("\nFile not found");
		return;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d\n",&i,&j,&temp);
		deg_arr[i-1]++;
	}
	/*for(i=0;i<n;i++)
	{
		printf(" %d %d\n ",i+1,deg_arr[i]);
	}*/
	fclose(fp);
	int* pos=(int*)calloc(n,sizeof(int));
	node** adj_list=(node**)malloc(n*sizeof(node*));
	heap* s=(heap*)malloc(max*sizeof(heap));
	for(i=0;i<n;i++)
	{
		adj_list[i]=(node*)malloc(deg_arr[i]*sizeof(node));
	}
	fp=fopen("edge_list.txt","r");
		while(!feof(fp))
		{
			fscanf(fp,"%d %d %d\n",&i,&j,&temp);
			(adj_list[i-1][pos[i-1]]).v=j;
			(adj_list[i-1][pos[i-1]]).w=temp;
            pos[i-1]++;
		}
		fclose(fp);
		fp=fopen("edge_list.txt","r");
        while(fscanf(fp,"%d%d%d",&i,&j,&temp)!=EOF)
        {
            if(i>max)
            max=i;
            if(j>max)
            max=j;
        }
        fclose(fp);
		free(pos);
		print(adj_list,deg_arr,n);
		heap* tree=(heap*)malloc(n*sizeof(heap));
		heap u,v; int x;
		for(i=0;i<n;i++)
		{
			tree[i].index=i+1;
			tree[i].key=INT_MAX;
			heap_pos[i]=i;
			tree[i].pi=0;
		}
		tree[0].key=0;
		while(n>0)
		{
			u=extract_min(tree,heap_pos,n);
            n--;
			s[u.index-1]=u;
			for(i=0;i<deg_arr[u.index-1];i++)
			{
				x=adj_list[u.index-1][i].v;
				v=tree[heap_pos[x-1]];
				relax(u,v,adj_list[u.index-1][i].w,heap_pos,tree);
			}
		}

	for(i=0;i<max;i++)
    {
        printf("%d(%d) %d\n",s[i].index,s[i].pi,s[i].key);
    }
    int vertex;
    printf("\nEnter destination vertex:");
    scanf("%d",&vertex);
    printf("1");
    print_path(vertex-1,s);
    printf("\nPath weight is %d",s[vertex-1].key);
	free(deg_arr);
	free(pos);
	free(s);
	for(i=0;i<n;i++)
	free(adj_list[i]);
	free(adj_list);
	return 0;
}
