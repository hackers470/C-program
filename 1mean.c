#include<stdio.h>
#define max 100
int main()
{
    int i,t;
    int mean,median;
     int  a[max],s,j;

    printf("enter the size of the array\n");
    scanf("%d",&s);
    printf("enter the number in array\n");
    
    for(i=0;i<s;i++)
      {scanf("%d",&a[i]);}
    
    int sum=0;
    for(i=0;i<s;i++)
       {sum=sum+a[i];}

     mean=sum/s;
     printf("mean of array= %d\n",mean);

    for(i=0;i<s-1;++i)
     {
        for(j=0;j<s-i-1;++j)
         {
            if(a[j]>a[j+1])
            {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
            }
         }
     }
     printf("\nsorted array");
     for(i=0;i<s;++i)
      {
        printf("%d",a[i]);
      }
      if(s%2==0)
        median=(a[s/2]+a[(s/2)+1])/2;
    else
        median=a[(s/2)];

    printf("median= %d",median);
    return 0;
}