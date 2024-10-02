#include<stdio.h>
int main()
{ 
    int a[5][5],i,j;
    for(i=0;i<5;++i)
    {printf("enter the sudent %d: ",i+1);
        for(j=0;j<5;++j)
        {printf("Course %d ",j+1);
         scanf("%d",&a[i][j]);
        }
    }
//print marks for the students
printf("\nmarks for students ");
for(i=0;i<5;++i)
  { printf("Student %d: ",i+1);
    for(j=0;j<5;++j)
      {printf("%d ",a[i][j]);}
      printf("\n");
  }
  
  return 0;
}
