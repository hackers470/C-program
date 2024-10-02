#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct queue
{int data;
  struct queue *next;
}queue;
queue *start=NULL;

void enqueue(queue *rear,int item)
{if(rear==NULL)
  {start=(queue*)malloc(sizeof(queue));
    if(start==NULL)
    {printf("Overflow");
      getch();
      exit(0);
    }
     start->data=item;
     start->next=NULL;
    }
    else
    {while(rear->next!=NULL)
     {rear=rear->next;}
     rear->next=(queue*)malloc(sizeof(queue));
      if(rear->next==NULL)
       {printf("overflow");
        getch();
        exit(0);
       }
       rear->next->data=item;
       rear->next->next=NULL;
  }
}

void dequeue(queue *front)
{if(front==NULL)
   {printf("UNDERFLOW");
    getch();
    exit(0);
   }
  else
    {start=start->next;
     free(front);
    }
}

void disp(queue *p)
{while(p!=NULL)
  {printf("%d ",p->data);
   p=p->next;
  }
  printf("\n");
}

int main()
{enqueue(start,10);enqueue(start,20);enqueue(start,30);
 disp(start); dequeue(start);
 disp(start); dequeue(start);
 disp(start); dequeue(start);
 disp(start);
 getch();
}
