#include<stdio.h>
#include<stdlib.h>

int x[10],i=0;

struct dLLNode{
  int data;
  struct dLLNode *prv,*next;
};

struct tNode{
  int data;
  struct tNode *left,*right;
};

void createDoubleLLNode(struct dLLNode **head,int data)
{
  struct dLLNode *newNode=(struct dLLNode*)malloc(sizeof(struct dLLNode));
  newNode->data=data;
  newNode->next=*head;
  newNode->prv=NULL;
  *head=newNode;
}

struct tNode* createTNode(int data)
{
  struct tNode* newTNode=(struct tNode*)malloc(sizeof(struct tNode));
  newTNode->left=NULL;
  newTNode->right=NULL;
  newTNode->data=data;
  return newTNode;
}

struct tNode* insertTNode(struct tNode *root, int data)
{
  if (root==NULL)
    {
      root=createTNode(data);
      return root;
    }

  if(data<root->data)
    root->left=insertTNode(root->left,data);
  else
    root->right=insertTNode(root->right,data);

  return root;
}

void PreOrderTreeTraversal(struct tNode* root)
{
  if (root==NULL)
    return;

  x[i++]=root->data;
  printf("%d\n",root->data);
  PreOrderTreeTraversal(root->left);
  PreOrderTreeTraversal(root->right);
}

struct dLLNode* convertBSTtoDLL()
{
  struct dLLNode *DLLroot=NULL;
  for (int a=0;a<i;a++)
    {
      createDoubleLLNode(&DLLroot,x[a]);
    }
  return DLLroot;
}

void printNodes(struct dLLNode* head)
{
  struct dLLNode* n=head;
  while(n!=NULL)
    {
      printf("%d\n",n->data);
      n=n->next;
    }
}


int main()
{
  struct tNode *root=NULL;
  root=createTNode(5);
  root=insertTNode(root,2);
  root=insertTNode(root,1);
  root=insertTNode(root,6);
  root=insertTNode(root,7);
  root=insertTNode(root,8);
  PreOrderTreeTraversal(root);
  struct dLLNode* DLLroot=convertBSTtoDLL();
  printf("elements in converted doubly linked list are\n");
  printNodes(DLLroot);
  return 0;
}

