#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct stack
{int data;
 struct stack *next;
}stack;
stack *start=NULL;

void push(stack *top,int item)
{if(top==NULL)
  {start=(stack*)malloc(sizeof(stack));
    if(start==NULL)
    {printf("OVERFLOW");
     getch();
     exit(0);
    }
    start->data=item;
    start->next=NULL;
  }
 else
   {while(top->next!=NULL)
    {top=top->next;}
    top->next=(stack*)malloc(sizeof(stack));
    if(top->next==NULL)
    {printf("OVERFLOW");
      getch();
      exit(0);
    }
    top->next->data=item;
    top->next->next=NULL;
   }
}
void pop(stack *top)
{if(top==NULL)
  {printf("UNDERFLOW");
  getch();
  exit(0);
  }
 else if(top->next==NULL)
  {start=start->next;
  free(top);
  }
 else
    {while(top->next->next!=NULL)
      {top=top->next;}
      free(top->next);
       top->next=NULL;
    }
}

void disp(stack *top)
{int c=0;
while(top!=NULL)
  {c=c+1;
   top=top->next;
  }
for(int i=1;i<=c;i++)
 {top=start;
   for(int j=1;j<=c-i;j++)
    {top=top->next;}
   printf("%d ",top->data);
 }
 printf("\n");
}

int main()
{push(start,10); push(start,20); push(start,30);
 disp(start); pop(start);
 disp(start); pop(start);
 disp(start); pop(start);
 disp(start);
 getch();}