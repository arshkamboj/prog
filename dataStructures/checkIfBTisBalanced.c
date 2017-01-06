#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *left,*right;
}node;

node* createNode(int data)
{
  node* newNode=(node*)malloc(sizeof(node));
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

node* insertNode(node *root,int data)
{
  if (root==NULL)
    {
      root=createNode(data);
      return root;
    }

  if (data<root->data)
    root->left=insertNode(root->left,data);
  else
    root->right=insertNode(root->right,data);

  return root;
}

int max(int a ,int b)
{
  if (a>=b)
    return a;
  else 
    return b;
}


int height(node* root)
{
  if (root==NULL)
    return 0;

  else
    return 1+max(height(root->left),height(root->right));
}

int isBalanced(node* root)
{
  if (root==NULL)
    return 1;

  if (abs(height(root->right) - height(root->left)) <=1)
    return 1;

  return 0;
}

void PreOrderTreeTraversal(struct node* root)
{
  if (root==NULL)
    return;

  printf("%d\n",root->data);
  PreOrderTreeTraversal(root->left);
  PreOrderTreeTraversal(root->right);
}


int main()
{
  node* root=NULL;
  root=insertNode(root,4);
  insertNode(root,5);
  insertNode(root,6);
  insertNode(root,7);
  insertNode(root,3);
  PreOrderTreeTraversal(root);
  if (isBalanced(root)==1)
    printf("tree is balanced\n");
  else
    printf("tree is unbalanced\n");
  return 0;
}
