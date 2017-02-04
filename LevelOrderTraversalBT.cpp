#include<iostream>
#include<queue>
using namespace std;

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

void levelOrderTraversal(struct node* root){
    queue<node*> q;
    q.push(root);
    struct node* tempNode=root;
    while(tempNode!=NULL){
        if(tempNode->left !=NULL)
            q.push(tempNode->left);
    
        if(tempNode->right !=NULL)
            q.push(tempNode->right);
    
        if(!q.empty())
        {
            cout<<q.front()->data<<" ";
            q.pop();
        }
        tempNode=q.front();
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
  cout<<"Level order traversal is: \n";
  levelOrderTraversal(root);
  
  return 0;
}