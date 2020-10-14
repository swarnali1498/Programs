#include<stdio.h>
#include<stdlib.h>
struct get_graph
{
int id; //'0' for tree edge and 1 for back edge/cross edge
int v1; //one end vertex of an edge
int v2; //other end vertex of an edge
};
typedef struct get_graph tree;
int findN(void)
{
int n=1,temp1,temp2;
FILE *fp = fopen("edge_list.txt","r");
while(!feof(fp))
{
fscanf(fp,"%d %d\n",&temp1,&temp2);
if(temp1>n)
n=temp1;
if(temp2>n)
n=temp2;
}
fclose(fp);
return n;
}
int *create_deg_array(int n)
{
int i,j;
int *deg_arr = (int *)calloc(n,sizeof(int));
FILE *fp = fopen("edge_list.txt","r");
while(!feof(fp))
{
fscanf(fp,"%d %d\n",&i,&j);
deg_arr[i-1]++;
deg_arr[j-1]++;
}
fclose(fp);
return deg_arr;
}
int **make_adj_list(int n, int *deg_arr)
{
int i,j;
int *pos = (int *)calloc(n,sizeof(int));
int **adj_list = (int **)calloc(n,sizeof(int *));
for(i=0; i<n; i++)
adj_list[i]=(int *)calloc(deg_arr[i],sizeof(int));
FILE *fp = fopen("edge_list.txt","r");
while(!feof(fp))
{
fscanf(fp,"%d %d\n",&i,&j);
adj_list[i-1][pos[i-1]]=j;
adj_list[j-1][pos[j-1]]=i;
pos[i-1]++;
pos[j-1]++;
}
fclose(fp);
free(pos);
return adj_list;
}
void print_op(int **adj_list, int *deg_arr, int n)
{
FILE *fp = fopen("AdjListOutput.txt","w");
int i,j;
for(i=0; i<n; i++)
{
fprintf(fp,"%d (%d) : ",(i+1),deg_arr[i]);
for(j=0;j<deg_arr[i];j++)
{
fprintf(fp," %d ",adj_list[i][j]);
}
fprintf(fp,"\n");
}
fclose(fp);
}
int count;
tree t_arr[500];
int isAdjacent(int a, int b)
{ //if v1 and v2 are adjacent return 1 else 0
int i;
for(i=0;i<=count;i++)
{
if(t_arr[i].v1 == a && t_arr[i].v2 == b)
return 1;
else if(t_arr[i].v2 == a && t_arr[i].v1 == b)
return 1;
}
return 0;
}
int both_in_stack(int stack[],int a, int b, int top)
{
int i,c=0;
for(i=top; i>=0; i--)
{
if(stack[i]==a)
c++;
else if(stack[i]==b)
c++;
}
if(c>=2)
return 1;
else
return 0;
}
//called by the DFS_init function
void DFS(int parent_node, int **adj_list, int *deg_arr, int stack[], int
*visited, int *top)
{
if(visited[parent_node-1]==0)
{
stack[++(*top)]=parent_node;
visited[parent_node-1]=1;
int i,temp;
for(i=0; i<deg_arr[parent_node-1]; i++)
{
//both not visited
if(visited[adj_list[parent_node-1][i]-1]==0)
{
t_arr[count].id = 0;
t_arr[count].v1 = parent_node;
t_arr[count].v2 = adj_list[parent_node-1][i];
count++;
DFS(adj_list[parent_node-
1][i],adj_list,deg_arr,stack,visited,top);
}
else //both visited - possibility of back edge
{
if(isAdjacent(adj_list[parent_node-1][i],parent_node) ==
0) //Not parent child
{
if(both_in_stack(stack, parent_node,
adj_list[parent_node-1][i], *top)) //BE is there.
{
t_arr[count].id = 1;
t_arr[count].v1 = parent_node;
t_arr[count].v2 = adj_list[parent_node-1][i];
count++;
}
}
}
}
(*top)--; //pop
}
return;
}
void DFS_init(int **adj_list, int *deg_arr, int n)
{
int start,j;
count=0;
printf("\n Enter which node to start DFS from (1 to %d) : ",n);
scanf("%d",&start);
int stack[n];
int top = -1;
int *visited = (int *)calloc(n,sizeof(int));
DFS(start,adj_list,deg_arr,stack,visited,&top);
//checking for multiple components.
for(j=0;j<n;j++)
{
if(visited[j]==0)
{
printf("%d node is left out. starting DFS again from there.");
DFS(j+1,adj_list,deg_arr,stack,visited,&top);
}
}
free(visited);
}
void print_DFS(void)
{
int i;
FILE *fp = fopen("DFS_out.txt","w");
for(i=0; i<count; i++)
{
fprintf(fp,"%d %d - ",t_arr[i].v1,t_arr[i].v2);
if(t_arr[i].id==0)
fprintf(fp,"tree edge");
else
fprintf(fp,"Back Edge");
fprintf(fp,"\n");
}
fclose(fp);
}
//-----------------------------------------------------
void enqueue (int queue[], int *f, int *r, int n, int num)
{
if (*f==-1)
(*f)++;
*r=(*r+1)%n;
queue[*r]=num;
}
int dequeue(int queue[], int *f, int *r, int n)
{
int temp = queue[*f];
if(*r == *f) //sole element in queue. dequeue and reset
{
*r=*f=-1;
return temp;
}
*f=(*f+1)%n;
return temp;
}
//only check if second element is in queue, because first has been popped, and is held in temp (in BFS fn)
int both_in_queue(int queue[], int a, int f, int r, int n)
{
int x = f;
if(f==-1)
return 0;
while(1)
{
if(queue[x]==a)
return 1;
if(x==r)
break;
x=(x+1)%n;
}
return 0;
}
void BFS(int parent_node, int **adj_list, int *deg_arr, int queue[], int
*visited, int n, int *f, int *r)
{
enqueue(queue,f,r,n,parent_node);
visited[parent_node-1]=1;
int i;
while((*f) != -1) //while queue is not empty
{
int temp = dequeue(queue,f,r,n);
for(i=0; i<deg_arr[temp-1]; i++)
{
if(visited[adj_list[temp-1][i]-1]==0)
{
enqueue(queue,f,r,n,adj_list[temp-1][i]);
visited[adj_list[temp-1][i]-1]=1;
t_arr[count].id = 0;
t_arr[count].v1 = temp;
t_arr[count].v2 = adj_list[temp-1][i];
count++;
continue;
}
else if(isAdjacent(temp,adj_list[temp-1][i])==0)
{
if(both_in_queue(queue,adj_list[temp-1][i],*f,*r,n))
{
t_arr[count].id = 1;
t_arr[count].v1 = temp;
t_arr[count].v2 = adj_list[temp-1][i];
count++;
}
}
}
}
}
void BFS_init(int **adj_list, int *deg_arr, int n)
{
int start,j;
count=0;
printf("\n Enter which node to start BFS from (1 to %d) : ",n);
scanf("%d",&start);
int queue[n];
int f = -1,r = -1;
int *visited = (int *)calloc(n,sizeof(int));
BFS(start,adj_list,deg_arr,queue,visited,n,&f,&r);
//checking for multiple components.
for(j=0; j<n; j++)
{
if(visited[j]==0)
{
printf("%d node is left out. starting BFS again from there.");
BFS(j+1,adj_list,deg_arr,queue,visited,n,&f,&r);
}
}
free(visited);
}
void print_BFS(void)
{
int i;
FILE *fp = fopen("BFS_out.txt","w");
for(i=0; i<count; i++)
{
fprintf(fp,"%d %d - ",t_arr[i].v1,t_arr[i].v2);
if(t_arr[i].id==0)
fprintf(fp,"tree edge");
else
fprintf(fp,"cross edge");
fprintf(fp,"\n");
}
fclose(fp);
}
//-------------------------------------------
int main()
{
int n = findN();
int *deg_arr;
deg_arr = create_deg_array(n);
int **adj_list;
adj_list = make_adj_list(n,deg_arr);
print_op(adj_list,deg_arr,n);
DFS_init(adj_list,deg_arr,n);
print_DFS();
//BFS_init(adj_list,deg_arr,n);
//print_BFS();
int i;
/*for(i=0; i<n; i++)
free(adj_list[i]);
free(adj_list);
free(deg_arr);*/
return 0;
}
