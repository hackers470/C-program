#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int que[5];
int front=0;
int rear=-1;

void enqueue()
{int n;
 printf("Enter a number for insert in array",n);
 scanf("%d",&n);
 
 if(rear==4)
  {printf("OVERFLOW");
   getch();
   exit(0);
  }
 else
 {
    rear=rear+1;
    que[rear]=n;
 }
}

void dequeue()
{int n;
 if(rear<front)
  {printf("UNDERFLOW");
   getch();
   exit(0);
  }
 else
  {n=que[front];
   front=front+1;
   printf("Delete value from queue =%d",n);
  }
}

void main()
{int n;
 char ch;
 do
 {printf("Press 1 for insert \n");
  printf("Press 2 for delete \n");
  printf("Press any other for exit \n");
  scanf("%d",&n);
  
  if(n==1)
   enqueue();
  else if(n==2)
   dequeue();
  
  else
  {printf("Invalid choice");
   getch();
   exit(0);
  }
 
  printf("Do you want to continue...(y/n)");
  fflush(stdin);
  scanf("%c",&ch);
 }
 while(ch='n');
 getch();
}