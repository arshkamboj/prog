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

void insertAfter(struct node* elem,int data)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->next=elem->next;
  elem->next=newNode;
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

struct node* mergeNodes(struct node* head1,struct node* head2){
    struct node* head;
     if(head1->data > head2->data)
     {
         head=head1;
         head1=head2;
         head2=head;
     }
      head=head1;
         while(head1->next!=NULL && head2!=NULL)
         {
             if(head1->next->data > head2->data){
                insertAfter(head1,head2->data);
                head2=head2->next;
             }
              head1=head1->next;
         }
        while(head2!=NULL)
        {
            insertAfter(head1,head2->data);
            head2=head2->next;
        }
        
     
 return head;
}

int main()
{
  struct node* head=createNode(2);
  insertAfter(head,8);
  insertAfter(head,6);
  insertAfter(head,4);
  
  struct node* head2=createNode(1);
  insertAfter(head2,7);
  insertAfter(head2,5);
  insertAfter(head2,3);
  
  head= mergeNodes(head,head2);
  printf("merged linked list\n");
  printNodes(head);
  
return 0;
}