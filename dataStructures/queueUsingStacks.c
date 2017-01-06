#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct stack{
  struct node *top;
  int size,capacity;
};

struct queue{
  struct stack* s1;
  struct stack* s2;
};
void push(struct stack* s,int x);

struct stack* createStack(int x)
{
  struct stack* newStack=(struct stack*)malloc(sizeof(struct stack));
  newStack->size=0;
  newStack->capacity=x;
  newStack->top=NULL;
  return newStack;
}

struct queue* createQueue(int x)
{
  struct queue* newQueue=(struct queue*)malloc(sizeof(struct queue));
  newQueue->s1=createStack(x);
  newQueue->s2=createStack(x);
  return newQueue;
}

void enQueue(struct queue* q,int x)
{
  push(q->s1,x);
}

void push(struct stack* s,int x)
{
  if(s->size==s->capacity)
    {
      printf("queue is full\n");
      return;
    }
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=x;
  if(s->top ==NULL)
    {
      newNode->next=NULL;
    }
  else
    {
      newNode->next=s->top;
    }

  s->top=newNode;
  s->size+=1;
}

void deQueue(struct queue* q)
{

  if(q->s1->size==0 || q->s1->top==NULL)
    {
      printf("queue is empty\n");
      return;
    }

  while(q->s1->size>=1)
    {
      if(q->s1->size==1)
        {
          printf("popped item is %d\n",q->s1->top->data);
          q->s1->top=NULL;   
        }
      else
        {
          push(q->s2,q->s1->top->data);
          q->s1->top=q->s1->top->next;
        }
      q->s1->size-=1;
    }

  while(q->s2->size>=1)
    {
      push(q->s1,q->s2->top->data);
      q->s2->top=q->s2->top->next;
      q->s2->size-=1;
      q->s1->size-=1;
    }

}


void printQueue(struct queue* q)
{
  struct node* n=q->s1->top;

  while(n!=NULL)
    {
      printf("%d\n",n->data);
      n=n->next;
    }
}

int main()
{
  struct queue* newQueue=createQueue(4);
  enQueue(newQueue,5);
  enQueue(newQueue,6);
  enQueue(newQueue,7);
  enQueue(newQueue,8);
  printQueue(newQueue);

  enQueue(newQueue,9);
  deQueue(newQueue);
  enQueue(newQueue,10);
  printQueue(newQueue);
  return 0;
}

