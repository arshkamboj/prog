//print leftmost and rightmost nodes of tree clockwise
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<deque> 
using namespace std;
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

void printNodes(struct node* root){
   std::deque<struct node*> mydeque;
   mydeque.push_front (root);
  
  while(mydeque.front()->left!=NULL || (mydeque.front()->left==NULL && mydeque.front()->right!=NULL)) {
  if(mydeque.front()->left!=NULL)
  mydeque.push_front(mydeque.front()->left);
  else
  mydeque.push_front(mydeque.front()->right);
  }
  
  while(mydeque.back()->right!=NULL || (mydeque.front()->right==NULL && mydeque.front()->left!=NULL)){
   if(mydeque.back()->right!=NULL)
  mydeque.push_back(mydeque.back()->right);
  else
  mydeque.push_back(mydeque.back()->left);
  }

  std::deque<struct node*>::iterator it = mydeque.begin();
  while (it != mydeque.end() ){
    std::cout << ' ' << (*it)->data;
    *it++;
      
  }
  std::cout << '\n';
}

int main()
{
  struct node *root=NULL,*balanceroot=NULL;
  root=insertNode(root,100);
  root=insertNode(root,50);
  root=insertNode(root,150);
  root=insertNode(root,25);
  root=insertNode(root,75);
  root=insertNode(root,140);
  root=insertNode(root,142);
  root=insertNode(root,30);
  root=insertNode(root,70);
  root=insertNode(root,80);
  root=insertNode(root,35);
  printNodes(root);
  return 0;
}