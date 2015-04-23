#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int partition(int arr[], int l, int h)
{
  int pivot=l+(rand()%(h-l));
  int x=arr[pivot];          
  int i=l-1;
  int count=0;
  int p=arr[l];
  int q=arr[h];
  for(int z=l;z<h;z++)
    {
      if(arr[z]>q)
	count++;
    }
  for(int j=l;j<=h;j++)
    {
      if(arr[j]<=q)
	{
	  i++;
	  int temp=arr[i];
	  arr[i]=arr[j];
	  arr[j]=temp;
	}
    }
  //cout<<endl<<"Pivot:"<<pivot<<endl;
  // for(int z=l;z<h;z++)
  //  {
  //    cout<<arr[z]<<" ";
  //  }
  count=h-count;
  return count;
}


void quicksort(int A[],int l, int h)
{
  if(l<h)
    {
      int p=partition(A,l,h);
      quicksort(A,l,p-1);
      quicksort(A,p+1,h);
    }
}

int main()
{
  cout<<"yo";
  int a[100];
  //randomize();
  cout<<"\nBefore sort :"<<endl;
  for(int i=0;i<100;i++)
    {
      
      a[i]=(int)rand()%500;
      cout<<a[i]<<" ";
    }
  quicksort(a,0,100);
  cout<<"\nAfter sort :"<<endl;
  for(int i=0;i<100;i++)
   {
     cout<<a[i]<<" ";
   }
}
