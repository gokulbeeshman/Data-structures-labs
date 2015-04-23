#include<stdio.h>

int main()
{
int n;
printf("Enter the no of days");
scanf("%d",&n);
int a[100];
printf("\nEnter the value of the stock on each day");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
int span[100];
span[0]=1;
int max=a[0];
for(int i=1;i<n;i++)
{
if(a[i]>max)
{
max=a[i];
span[i]=i+1;
continue;
}
if(a[i]<=a[i-1])
{
span[i]=1;
}
if(a[i]>a[i-1])
{
span[i]=span[i-1]+1;
}
}
for(int i=0;i<n;i++)
{
printf("%d ",span[i]);
}
}


