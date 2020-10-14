#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* left;
  struct node* right;
}N;
void correctpos(N* head,int a,N* nu)
{
  if(head==NULL)
    return;
  	else if(head->data==a)
    {
      if(head->left==NULL)
      {
 		  head->left=nu;
      }
      else
      {
          head->right=nu;
      }
    }
    else
    {
      correctpos(head->left,a,nu);
      correctpos(head->right,a,nu);
    }
}
void insert(N* head,int a,int d)
{
    N* nu=(N*)malloc(sizeof(N));
  	nu->data=d;
  	nu->left=NULL;
  	nu->right=NULL;
    correctpos(head,a,nu);
}
int in[1000],pre[1000],post[1000],k1=0,k2=0,k3=0;
void inorder(N* head)
{
	if(head==NULL)
    return;
  	inorder(head->left);
  	in[k1++]=head->data;
  	inorder(head->right);
}
void preorder(N* head)
{
	if(head==NULL)
    return;
  	pre[k2++]=head->data;
  	preorder(head->left);
  	preorder(head->right);
}
void postorder(N* head)
{
	if(head==NULL)
    return;
  	postorder(head->left);
  	postorder(head->right);
  	post[k3++]=head->data;
}
int check(int a,int b,int c)
{
    if(a>=b && a<=c || a>=c && a<=b)
        return a;
    else if(b>=a && b<=c || b>=c && b<=a)
        return b;
    else
        return c;
}
int main()
{
  int m;
  scanf("%d",&m);
  int i,a;
  N* nu=(N*)malloc(sizeof(N));
  nu->data=0;
  nu->left=NULL;
  nu->right=NULL;
  N* head=nu;
  for(i=0;i<m;i++)
  {
    scanf("%d",&a);
    insert(head,a,i+1);
  }
  inorder(head);
  preorder(head);
  postorder(head);
  /*for(i=0;i<k1;i++)
  {
    printf("%d ",in[i]);
  }
     //   printf("\n");
  for(i=0;i<k1;i++)
  {
    printf("%d ",pre[i]);
  }
   //     printf("\n");
  for(i=0;i<k1;i++)
  {
    printf("%d ",post[i]);
  }*/
  int sum=0,l=0;
  for(i=0;i<k1;i++)
  {
     int ch=check(in[i],pre[i],post[i]);
     sum=(sum+ch)%1000000007;
  }
  printf("%d",sum);
  return 0;
}
