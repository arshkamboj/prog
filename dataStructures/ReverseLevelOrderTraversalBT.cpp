//Reverse Level Order Traversal

#include<iostream>
#include<queue>
#include<stack>
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

void levelOrderTraversalReverse(struct node* root){
    queue<node*> q;
    stack<node*> s;
    struct node* current=root;
    q.push(root);
    while(!q.empty()){
        current=q.front();
        q.pop();
        if(current->right !=NULL)
            q.push(current->right);
            
        if(current->left !=NULL)
            q.push(current->left);
    
        s.push(current);
       
    }
    while(!s.empty())
        {
            cout<<s.top()->data<<" ";
            s.pop();
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
  cout<<"Level order traversal in reverse is: \n";
  levelOrderTraversalReverse(root);
  
  return 0;
}