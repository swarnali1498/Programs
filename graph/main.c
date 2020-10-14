#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char v;
    struct node* link;
}N;
int main()
{
    FILE* f1; char ch; N* g; int n,k=0;
    printf("\nEnter number of vertices in graph : ");
    scanf("%d",&n);
    g=(N*)malloc(n*sizeof(N));
    f1=fopen("xyz.txt","r");
    if(f1==NULL)
    {
        printf("\nFile not found");
        return;
    }
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
        g[k]=insert(g[k],ch);
    }
    return 0;
}
N* insert(N* head,char c)
{
    N* nu,*ptr;
    nu=(N*)malloc(sizeof(N));
    nu->v=c;
    nu->link=NULL;
    if(head==NULL)
    {
        head=nu;
    }
    else
    {
        for(ptr=head;ptr->link!=NULL;ptr=ptr->link);
        ptr->link=nu;
    }
    return head;
}
