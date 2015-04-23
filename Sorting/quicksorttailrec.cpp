#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int partition(int arr[], int l, int h)
{
  int x=arr[h];
  int i=l-1;
  for(int j=l;j<h;j++)
    {
      if(arr[j]<=x)
	{
	  i++;
	  int temp=arr[i];
	  arr[i]=arr[j];
	  arr[j]=temp;
	}
    }
  int temp=arr[i+1];
  arr[i+1]=arr[h];
  arr[h]=temp;
  return i+1;
}


void quicksort(int A[],int l, int h)
{
  while(l<h)
    {
      int p=partition(A,l,h);
      quicksort(A,l,p-1);
      l=p+1;
    }
}

int main()
{
  double start=0,end=0;
  start=clock();
    for(int x=0;x<1000;x++)
    {
  int a[100];
  //randomize();
  cout<<"\nBefore sort :"<<endl;
  for(int i=0;i<100;i++)
    {
      
      a[i]=rand()%500;
      cout<<a[i]<<" ";
    }
  quicksort(a,0,100);
  cout<<"\nAfter sort :"<<endl;
  for(int i=0;i<100;i++)
   {
     cout<<a[i]<<" ";
   }
    }
    end=clock();
  cout<<endl<<"time:"<<end-start;
}
