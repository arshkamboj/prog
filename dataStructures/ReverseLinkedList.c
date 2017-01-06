#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* createNode(int value)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=NULL;
  return (newNode);
}

struct node* insertNode(struct node* head,int value)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=head;
  head=newNode;
  return newNode;
}

struct node* reverseLinkedList(struct node* head)
{
  struct node* pre=head;
  struct node* curr=head->next;
  struct node* currnext=curr->next;
  head->next=NULL;
  curr->next=head;

  while(currnext!=NULL)
    {
      curr->next=pre;
      pre=curr;
      curr=currnext;
      currnext=currnext->next;
    }
  curr->next=pre;
  head=curr;
  return head;
}


void printNodes(struct node* head)
{
  struct node* n=head;
  while(n!=NULL)
    {
      printf("%d\n",n->data);
      n=n->next;
    }
}

int main()
{
  struct node* head=createNode(5);
  head=insertNode(head,66);
  head=insertNode(head,7);
  head=insertNode(head,8);
  head=insertNode(head,9);
  head=insertNode(head,107);
  printNodes(head);
  printf("reversing linked list\n");
  head=reverseLinkedList(head);
  printNodes(head);
}
