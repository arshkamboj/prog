#include<stdio.h>
#include<iostream>
#include<deque> 
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

void printLeftNodes(struct node* root){
   if(root->left==NULL && root->right==NULL)
      return;
   
    printf("%d ",root->data);
    if(root->left!=NULL)
    printLeftNodes(root->left);
    else
    printLeftNodes(root->right);
}

void printRightNodes(struct node* root){
   if(root->left==NULL && root->right==NULL)
      return;
   
    if(root->right!=NULL)
    printRightNodes(root->right);
    else
    printRightNodes(root->left);
    
    printf("%d ",root->data);
   
}

void printLeafNodes(struct node* root){
    if(root==NULL)
    return;
    
    printLeafNodes(root->left);
    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->data);
    }
    printLeafNodes(root->right);
}

void printNodes(struct node* root){
  printf("%d ",root->data);
  printLeftNodes(root->left);
  printLeafNodes(root);
  printRightNodes(root->right);
}

int main()
{
  struct node *root=NULL,*balanceroot=NULL;
  root=insertNode(root,100);
  root=insertNode(root,50);
  root=insertNode(root,150);
  root=insertNode(root,24);
  root=insertNode(root,57);
  root=insertNode(root,130);
  root=insertNode(root,12);
  root=insertNode(root,30);
  root=insertNode(root,60);
  root=insertNode(root,132);
  printNodes(root);
  return 0;
}