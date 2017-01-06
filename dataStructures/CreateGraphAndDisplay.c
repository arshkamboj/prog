#include<stdio.h>
#include<stdlib.h>

struct node{
  int dest;
  struct node *next;
};

struct nodeList{
  struct node *head;
};

struct graph{
  int v;
  struct nodeList *array;
};

struct node* createNode(int data)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));
  newNode->dest=data;
  newNode->next=NULL;
  return newNode;
}

struct nodeList* createNodeList(struct node *head)
{
  struct nodeList *newNodeList=(struct nodeList*)malloc(sizeof(struct nodeList));
  newNodeList->head=head;
  return newNodeList;
}

struct graph* createGraph(int v)
{
  struct graph *newGraph=(struct graph*)malloc(sizeof(struct graph));
  newGraph->v=v;

  struct nodeList *newNodeList=(struct nodeList*)malloc(v*sizeof(struct nodeList));
  newGraph->array=newNodeList;
  for(int i=0;i<v;i++)
    {
      newGraph->array[i].head=NULL;
    }

  return newGraph;
}

void addEdge(struct graph *g,int start,int end)
{
  struct node *nnode=createNode(end);   
  nnode->next=g->array[start].head;
  g->array[start].head=nnode;

  nnode=createNode(start);   
  nnode->next=g->array[end].head;
  g->array[end].head=nnode;
}

void printGraph(struct graph *g)
{
  printf ("graphy nodes and edges are :\n");
  struct node *printnode;
  for (int i=0;i<g->v;i++)
    {
      printnode=g->array[i].head;
      printf("edges for %d node are :\n",i);
      while(printnode!=NULL)
        {
          printf("%d\n",printnode->dest);
          printnode=printnode->next; 
        }
    }

}

int main()
{
  struct graph *newG=createGraph(5);
  addEdge(newG,0,1);
  addEdge(newG,0,4);
  addEdge(newG,1,2);
  addEdge(newG,1,3);
  addEdge(newG,1,4);
  addEdge(newG,2,3);
  addEdge(newG,3,4);
  printGraph(newG);
  return 0;
}
