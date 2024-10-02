#include<stdio.h>
#define max 100
    int isearch(int a[],int s)
     {
        int i;
         for(i=0;i<10;i++)
          {if(a[i]==s)
             {return 1;}
          }
          return -1;
     }
     
   int bsearch(int a[],int l,int u, int s)
    {
        if(l<=u)
       {
        int mid = (l+u)/2;
         if(s==a[mid])
           {return mid;}
        else if (s<a[mid])
          {return bsearch(a,l,mid-1,s);}
        else if(s>a[mid])
          {return bsearch(a,mid+1,u,s);}
       }
        else
          {return -1;}
    }
    
    int main()
    {
        int a[10],i,n,p,j,t;
        printf("Enter values in array");
        for(i=0l;i<10;i++)
           {scanf("%d",&a[i]);}
    
    printf("Enter search number");
    scanf("%d",&n);
    p=isearch(a,n);
    if(p==-1)
      {printf("\n Not found with linear search");} 
    else
       {printf("\n Found at %d position using linear search",p+1);}

    for(i=0;i<9;i++)
    {for (j=i+1;j<10;j++)
         {
            if (a[i] > a[j])
            {
                t=a[i];
             a[i]=a[j];
             a[j]=t;
             }
         }
    }
        for (i=0;i<10;i++)
        {
            printf("%d ",a[i]);
            }
        printf("\n");
    
        p=bsearch(a,0,9,n);
        if (p==-1)
          {
            printf("\n Not found with binary search");
          }
        else
        {printf("\n Found at %d position using binary search",p+1);}
        return 0;
    }    