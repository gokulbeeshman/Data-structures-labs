#include<stdio.h>

void printarray(int a[100], int n)
{
printf("\n Sorted nos: \n");
for(int i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}

int main()
{
int a[100];int n;
printf("Enter the no of nos");
scanf("%d",&n);

for(int x=0;x<n;x++)
{
scanf("%d",&a[x]);
}
int temp;
for(int i=1;i<n;i++)
	{
	temp=a[i];
	for(int j=i-1;;j--)
	{
	if(j<0)
	{
	a[0]=temp;
	break;
	}
	if(a[j]<temp)
	{
	a[j+1]=temp;
	break;
	}
	else
	{
	a[j+1]=a[j];
	}
	
	}
	printarray(a,n);
	}

}
