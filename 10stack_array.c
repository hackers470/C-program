#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int stk[5];
int top=-1;

void push()
{
    int n;
    printf("Enter value for push \n");
    scanf("%d",&n);

    if(top==4)
    {printf("OVERFLOW");
     getch();
     exit(0);
    }
    else
    {top=top+1;
     stk[top]=n;
    }
}

void pop()
{int n;
 if(top==-1)
 {printf("UNDERFLOW");
  getch();
  exit(0);
 }
 else
 {
    n=stk[top];
    top=top-1;
    printf("popped value= %d ",n);
 }
}

void peek()
{int n;
 
 if(top==-1)
 {printf("UNDERFLOW");
  getch();
  exit(0);
 }
 else
 {
    n=stk[top];
    printf("Peeked value=%d ",n);
 }
}

void main()
{int n;
 char ch;
 do
 {printf("Press 1 for push \n");
  printf("Press 2 for pop \n");
  printf("Press 3 for peek \n");
  printf("Press any other for exit \n");
  scanf("%d",&n);
  if(n==1)
      push();
  else if(n==2)
      pop();
  else if(n==3)
      peek();
    else
      {
        printf("Invalid Choice ");
        getch();
        exit(0);
      }
    printf("Do you want to continue....(y/n)");
    fflush(stdin);
    scanf("%c",&ch);
}
while(ch!='n');
getch();
}