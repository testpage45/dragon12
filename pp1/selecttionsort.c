#include <stdio.h>
int a[20],i,j,n,min,loc;
void read()
{
    printf("enter the number of elements: ");
    scanf("%d",&n);
    printf("enter the numbers:\n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
}

void sort()
{
    for(i=0;i<n;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        a[loc]=a[i];
        a[i]=min;
    }   
}

void display()
{
  printf("sorted array is: ");
  for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

void main()
{
    read();
    sort();
    display();
}
