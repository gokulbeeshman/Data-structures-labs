#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void selectionsort(int a[],int size)
{
  
  
  for(int i=0;i<size;i++)
    {
      int smallest=a[i];
      int smallindex=i;
      for(int j=i;j<size;j++)
	{
	  if(a[j]<smallest)
	    {
	      smallest=a[j];
	      smallindex=j;
	    }
	}
      int temp=a[smallindex];
      a[smallindex]=a[i];
      a[i]=temp;
	
    }

  
}

int main()
{
  int a[100];
  //randomize();
  cout<<"Before sort :"<<endl;
  for(int i=0;i<20;i++)
    {
      
      a[i]=rand()%50;
      cout<<a[i]<<" ";
    }
  selectionsort(a,20);
  cout<<"After sort :"<<endl;
  for(int i=0;i<20;i++)
   {
     cout<<a[i]<<" ";
   }
}
