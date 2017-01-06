#include<stdio.h>
#include<stdlib.h>

int array[20],i=0;

struct node
{
  int data;
  struct node *left,*right;
};

struct node* createNode(int data)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

struct node* insertNode(struct node* root,int data)
{
  if (root==NULL)
    {
      root=createNode(data);
      return root;
    }

  if (data<root->data)
    {
      root->left= insertNode(root->left,data);
    }
  else
    {
      root->right=insertNode(root->right,data);
    }
  return root;
}

void PreOrderTreeTraversal(struct node* root)
{
  if (root==NULL)
    return;

  printf("%d\n",root->data);
  PreOrderTreeTraversal(root->left);
  PreOrderTreeTraversal(root->right);
}

void PostOrderTreeTraversal(struct node* root)
{
  if (root==NULL)
    return;

  PostOrderTreeTraversal(root->left);
  PostOrderTreeTraversal(root->right);
  printf("%d\n",root->data);
}

void InOrderTreeTraversal(struct node* root)
{
  if (root==NULL)
    return;

  InOrderTreeTraversal(root->left);
  array[i++]=root->data;
  printf("%d\n",root->data);
  InOrderTreeTraversal(root->right);
}

struct node* balanceTree(int start,int end)
{
  int mid=(start+end)/2;
  if (start>end )
    {
      return NULL;
    }
  struct node* newroot=createNode(array[mid]);
  newroot->left=balanceTree(start,mid-1);
  newroot->right=balanceTree(mid+1,end);
  return newroot;
} 

void printarray()
{
  int x=0;
  while(x<i)
    {
      printf("%d\n",array[x++]);
    }
}

int main()
{
  struct node *root=NULL,*balanceroot=NULL;
  root=insertNode(root,1);
  root=insertNode(root,2);
  root=insertNode(root,3);
  root=insertNode(root,4);
  root=insertNode(root,5);
  root=insertNode(root,6);
  root=insertNode(root,7);

  printf("In order traversal\n");
  InOrderTreeTraversal(root);
  printf("Pre order traversal\n");
  PreOrderTreeTraversal(root);
  printf("Post order traversal\n");
  PostOrderTreeTraversal(root);

  root=balanceTree(0,i-1);
  printf("After balancing:In order traversal\n");
  InOrderTreeTraversal(root);
  printf("Pre order traversal\n");
  PreOrderTreeTraversal(root);
  printf("Post order traversal\n");
  PostOrderTreeTraversal(root);


  return 0;
}
