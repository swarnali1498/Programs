#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}N;
N* insert(N* root,N* nu)
{
    if(root!=NULL)
    {
        if(nu->data<root->data)
        {
            root->left=insert(root->left,nu);
        }
        else if(nu->data>root->data)
        {
            root->right=insert(root->right,nu);
        }
        return root;
    }
    return nu;
}
void inorder_traversal(N* root)
{
        if(root==NULL)
        {
            return;
        }
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
}
void display(N* root)
{
    if(root==NULL)
    {
        printf("\nBinary Search Tree is empty");
    }
    else
    {
        inorder_traversal(root);
    }
}
N* search(N* root,int a)
{
    if(root!=NULL)
    {
        if(a==root->data)
            return root;
        else if(a<root->data)
            search(root->left,a);
        else if(a>root->data)
            search(root->right,a);
    }
    else
    {
        return root;
    }
}
N* inorder_predecessor(N* ptr,N* prev,int c)
{
    if(ptr->right!=NULL)
    {
        inorder_predecessor(ptr->right,ptr,c);
    }
    else
    {
        if(c==1)
            return ptr;
        else if(c==0)
            return prev;
    }
}
N* inorder_successor(N* ptr,N* prev,int c)
{
    if(ptr->left!=NULL)
    {
        inorder_successor(ptr->left,ptr,c);
    }
    else
    {
        if(c==1)
            return ptr;
        else if(c==0)
            return prev;
    }
}
N* deleteNode(N* root,int key,N* pr)
{
    int temp;
    N* ptr;
    if(key<root->data && root->left!=NULL)
    {
        deleteNode(root->left,key,root);
    }
    else if(key>root->data && root->right!=NULL)
    {
        deleteNode(root->right,key,root);
    }
    else if(key==root->data)
    {
        if(root->left==NULL && root->right!=NULL)
        {
            ptr=inorder_successor(root->right,root,1);
            pr=inorder_successor(root->right,root,0);
            root->data=ptr->data;
            deleteNode(ptr,ptr->data,pr);
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            ptr=inorder_predecessor(root->left,root,1);
            pr=inorder_predecessor(root->left,root,0);
            root->data=ptr->data;
            deleteNode(ptr,ptr->data,pr);
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            ptr=inorder_successor(root->right,root,1);
            pr=inorder_successor(root->right,root,0);
            root->data=ptr->data;
            deleteNode(ptr,ptr->data,pr);
        }
        else
        {
            if(pr->left==root)
                pr->left=NULL;
            else if(pr->right==root)
                pr->right=NULL;
            ptr=root;
            free(ptr);
            root=NULL;
        }
    }
    else
    {
        printf("\nElement not present");
        return;
    }
    return root;
}
int main()
{
    int a,i,n;
    N* root=NULL,*nu;
    while(1)
    {
        printf("\nEnter 1/2/3/4 for insertion, deletion, inorder traversal, exit : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("\nEnter element to be inserted : ");
                    scanf("%d",&a);
                    nu=(N*)malloc(sizeof(N));
                    nu->data=a;
                    nu->left=nu->right=NULL;
                    root=insert(root,nu);
                    break;
            case 2: if(root==NULL)
                    {
                        printf("\nBinary search tree is empty");
                    }
                    else
                    {
                        printf("\nEnter element to be deleted : ");
                        scanf("%d",&a);
                        printf("\nDeleted element is %d",a);
                        root=deleteNode(root,a,root);
                    }
                    break;
            case 3: display(root);
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nWrong choice");
        }
    }
}
