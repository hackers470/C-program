#include<stdio.h>
#define  max 100  
int  main()
{
    int i;
    int  a[max],n,p,s;

    printf("enter the size of the array");
    scanf("%d",&s);  //input array size

    for(i=0;i<s;i++)
    {
        printf("Enter the values of array");
        scanf("%d",&a[i]);  //inputs values in array
    }
    
    //INSERTION CODE
    printf("enter the number and pos to replace the number:");
    scanf("%d%d",&n,&p);

    s=s+1;
    for(i=s-1;i>=p;i--)
    {a[i]=a[i-1];}

    a[p-1] = n;
    printf("after insert the new array is");

    for(i=0;i<s;i++)
       {printf("%d, ",a[i]);}
     return 0;
}