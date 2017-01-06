#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct queue
{
  struct node  *front,*rear;
  int size,capacity;
};

struct stack{
  struct queue *q1;
  struct queue *q2;
};


void enQueue(struct queue* q,int x);
void push(struct stack* s,int x);
void pop(struct stack* s);
void printQueue(struct queue* q);

struct queue* createQueue(int x)
{
  struct queue* q=(struct queue*)malloc(sizeof(struct queue));
  q->size=0;
  q->capacity=x;
  return q;
}

struct stack* createStack(int x)
{
  struct stack *q=(struct stack*)malloc(sizeof(struct stack));
  //printf("sizeof stack : %d\n",(int)sizeof(*q));
  q->q1=createQueue(x);
  q->q2=createQueue(x);
  printf("sizeof stack : %d\n",(int)sizeof(*q));
  return q;
}

void push(struct stack *s,int x)
{
  enQueue(s->q1,x);
}

void enQueue(struct queue* queue_ref,int data)
{
  if (queue_ref->size ==queue_ref->capacity)
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


void pop(struct stack *s)
{
  struct queue *queue_ref=s->q1;
  int data;
  struct queue *k;

  if(queue_ref->size==0) 
    {
      printf("queue is already empty");
      return;
    }

  while(queue_ref->size>0)
    {
      data=queue_ref->front->data;
      if(queue_ref->size==1)
        {
          printf("dequeued item is : %d\n",data);
        }
      else
        {
          enQueue(s->q2,data);
          queue_ref->front=queue_ref->front->next;
        }
      queue_ref->size-=1;
    }

  k=s->q1;
  s->q1=s->q2;
  s->q2=s->q1;


  if (queue_ref->size==0)
    {
      queue_ref->front==NULL;
      queue_ref->rear=NULL;
    }
}

void printStack(struct stack* s)
{
  printQueue(s->q1);
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
  struct stack* newStack=createStack(5);
  push(newStack,1);
  push(newStack,2);
  push(newStack,3);
  push(newStack,4);
  printStack(newStack);
  pop(newStack);
  printStack(newStack);
  push(newStack,8);
  push(newStack,9);
  push(newStack,10);
  printStack(newStack);
  return 0;
}

