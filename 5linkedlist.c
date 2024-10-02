#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
  {
    int data;
    struct node *next;
  }node;
  node *start =NULL;
 
  void create(node *p)
  {int d;
   printf("Enter value from new node");
   scanf("%d",&d);
   if(p==NULL)
    {start=(node*)malloc(sizeof(node));
     start->data=d;
     start->next=NULL;
    }
   else{
    while(p->next!=NULL)
     {p=p->next;}
     p->next=(node*)malloc(sizeof(node));
     p->next->data=d;
     p->next->next=NULL;
   }
  }
  void appbig(node *p)
  {int d;
   printf("Enter value for append big");
   scanf("%d",&d);
   start=(node*)malloc(sizeof(node));
   start->data=d;
   start->next=p;
  }
  void appmid(node *p)
  {node *tmp;
  int d,pos;
  printf("Enter value from mid node and position");
  scanf("%d %d",&d,&pos);
  for(int i=1;i<=pos-2;i++)
   {p=p->next;}
   tmp=p->next;
   p->next=(node*)malloc(sizeof(node));
   p->next->data=d;
   p->next->next=tmp;
  }
  void delbig(node *p)
  {start=start->next;
  free(p);
  }
  void delmid(node *p)
  {node *tmp;
    int pos;
    printf("Enter position for delete mid node");
    scanf("%d",&pos);
    for(int i=1;i<=pos-2;i++)
     {p=p->next;}
     tmp=p->next;
     p->next=p->next->next;
     free(tmp);
   }
   void dellast(node *p)
    {while(p->next->next!=NULL)
      {p=p->next;}
      free(p->next);
      p->next=NULL;
    }
    void disp(node *p)
     {while(p!=NULL)
       {printf("%d ",p->data);
        p=p->next;
       }
       printf("\n");
    }
    void search(node *p)
     {  int s,pos=0,flag=0;
        printf("Enter search number");
        scanf("%d",&s);
        while(p!=NULL)
         {
            pos=pos+1;
            if(p->data==s)
             {flag=1;
              printf("Found at %d position",pos);
              break;
             }
            p=p->next;
         }
             if(flag==0)
              printf("Not found");
     }

  int main()
   {char ch;
    int n;
    do { printf("Pres 1 for create node \n");
        printf("Pres 2 for append big node \n");
        printf("Pres 3 for append mid node \n");
        printf("Pres 4 for delete big node \n");
        printf("Pres 5 for delete mid node \n");
        printf("Pres 6 for delete last node \n");
        printf("Pres 7 for display \n");
        printf("Pres 8 for search \n");
        printf("Pres 0 for exit \n");
        printf("Enter your choice : ");
        scanf("%d",&n);

        if(n==1)
           {create (start);}
                 else if(n==2)
          {appbig(start);}
             else if(n==3)
          {appmid(start);}
        else if(n==4)
          {delbig(start);}
        else if(n==5)
         {delmid(start);}
        else if(n==6)
          {dellast(start);}
        else if(n==7)
          {disp(start);}
        else if(n==8)
          {search(start);}
      else
        {printf("Invalid choice....");
        getch();
        exit(0);
        }
       printf("\n Do you want to continue.....(y/n)");
       fflush(stdin);
       scanf("%c",&ch);
    }  
    while(ch!='n');
     getch();
}
