#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct queue{
  struct node* front;
  struct node* rear;
  int capacity,size;
};

struct queue* createQueue(int capacity)
{
  struct queue* newQueue=(struct queue*)malloc(sizeof(struct queue));
  newQueue->capacity=capacity;
  newQueue->size=0;
  newQueue->front=NULL;
  newQueue->rear=NULL;
  return (newQueue);
}

void enQueue(struct queue* queue_ref,int data)
{
  if (queue_ref->size == queue_ref->capacity)
    {
      printf ("queue is full\n");
      return;
    }

  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->next=NULL;

  if(queue_ref->front==NULL && queue_ref->rear==NULL)
    {
      queue_ref->rear=newNode;
      queue_ref->front=newNode;
    }
  else
    {
      queue_ref->rear->next=newNode;
      queue_ref->rear=newNode;
    }

  queue_ref->size+=1;
}

void deQueue(struct queue* queue_ref)
{
  if(queue_ref->size==0) 
    {
      printf("queue is already empty");
      return;
    }

  queue_ref->front=queue_ref->front->next;
  queue_ref->size-=1;

  if (queue_ref->size==0)
    {
      queue_ref->front==NULL;
      queue_ref->rear=NULL;
    }
}

void printQueue(struct queue* q)
{
  struct node* n=q->front;

  while(n!=NULL)
    {
      printf("%d\n",n->data);
      n=n->next;
    }
}

int main()
{
  struct queue* newQueue=createQueue(5);
  enQueue(newQueue,1);
  enQueue(newQueue,2);
  enQueue(newQueue,3);
  enQueue(newQueue,4);
  enQueue(newQueue,5);
  enQueue(newQueue,6);
  deQueue(newQueue);
  deQueue(newQueue);
  deQueue(newQueue);
  deQueue(newQueue);
  deQueue(newQueue);
  deQueue(newQueue);
  enQueue(newQueue,9);
  printQueue(newQueue);
}
