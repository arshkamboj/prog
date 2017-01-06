#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};

void push(struct node** head_ref,int data)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->next=*head_ref;
  *head_ref=newNode;
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

void append(struct node** head_ref,int data)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->next=NULL;
  struct node* n=*head_ref;
  while(n->next!=NULL)
    {
      n=n->next;
    }
  n->next=newNode;
}

void insertAfter(struct node* elem,int data)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->next=elem->next;
  elem->next=newNode;
}

int main()
{
  struct node* head=NULL;
  push(&head,5);
  push(&head ,4);
  insertAfter(head,8);
  append(&head,99);
  push(&head,7);
  printNodes(head);
}

