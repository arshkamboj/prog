#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left,*right;
};

struct node* createNode(int data)
{
  struct node *newNode=(struct node*)(malloc(sizeof(struct node)));
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

void InOrderTreeTraversal(struct node* root)
{
  if (root==NULL)
    return;

  InOrderTreeTraversal(root->left);
  printf("%d\n",root->data);
  InOrderTreeTraversal(root->right);
}

struct node* inOrderSuccessor(struct node* ipNode,struct node **parent)
{
  struct node* succNode=ipNode->right;
  *parent=ipNode;
  while(succNode->left !=NULL)
    {
      *parent=succNode;
      succNode=succNode->left;
    }
  printf("succNode:%d\n",succNode->data);

  return succNode;
}

void findNode(int data, struct node **delNode, struct node **parent, int *found)
{
  if (*parent==NULL)
    {
      *delNode=NULL;
      printf("node not found\n"); 
      return;
    }
  if(data==(*parent)->data)
    {
      *delNode=*parent;
      *found=1;
      return;
    }
  if (data==(*parent)->left->data)
    {
      *delNode=(*parent)->left;
      *found=1;
      return;
    }

  else if(data==(*parent)->right->data)
    {
      *delNode=(*parent)->right;
      *found=1;
      return;
    }

  if (data<(*parent)->data)
    {
      *parent=(*parent)->left;
      findNode(data,delNode,parent,found);
    }
  else
    {
      *parent=(*parent)->right;
      findNode(data,delNode,parent,found);
    }

  return;

}

void deleteNode(struct node *root,int data)
{
  struct node *delNode=NULL,*parent=root;
  int found=0;

  findNode(data,&delNode,&parent,&found);

  if ( found==0)
    {
      printf("node not found\n");
      return;
    } 

  if ( found==1)
    {
      printf("node found\n");

      if ((delNode->left ==NULL) && (delNode->right==NULL))
        {
      
          //node to be deleted is leaf node
          if(parent->right==delNode)
            parent->right=NULL;
          else
            parent->left=NULL;

          free(delNode);
        }

      else if (delNode->left !=NULL && delNode->right !=NULL)
        {
          struct node* snode=inOrderSuccessor(delNode,&parent);
          delNode->data=snode->data;

          if(delNode->data==parent->left->data)
            {      
              parent->left=NULL;      
            }
          else
            {
              parent->right=NULL;
            }
          free(snode);
        }
  
      else
        {
          //node to be deleted has exactly one child
          if (delNode->left==NULL)
            {
              delNode->data=delNode->right->data;
              free(delNode->right);
            }
          else
            {
              delNode->data=delNode->left->data;
              free(delNode->left);
            }
        }
    }
}

int main()
{
  struct node *root=NULL;
  root=insertNode(root,50);
  insertNode(root,30);
  insertNode(root,20);
  insertNode(root,40);
  insertNode(root,70);
  insertNode(root,60);
  insertNode(root,80);

  printf("Pre order traversal\n");
  PreOrderTreeTraversal(root);
  printf("In order traversal\n");
  InOrderTreeTraversal(root);

  printf("node to be deleted:50\n");
  deleteNode(root,50);

  printf("Pre order traversal\n");
  PreOrderTreeTraversal(root);
  printf("In order traversal\n");
  InOrderTreeTraversal(root);

  return 0;
}
