#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Maxheap
{
  int size;
  int * array;
};

void Heapifier(Maxheap * maxHeap, int index)
{
  int largest=index;
  int left=index*2+1;
  int right=index*2+2;
  if((left<maxHeap->size)&&(maxHeap->array[left]>maxHeap->array[largest]))
    {
      largest=left;
    }
  if((right<maxHeap->size)&&(maxHeap->array[right]>maxHeap->array[largest]))
    {
      largest=right;
    }
  if(largest!=index)
    {
      int temp=maxHeap->array[largest];
      maxHeap->array[largest]=maxHeap->array[index];
      maxHeap->array[index]=temp;
       Heapifier(maxHeap,largest);
    }
 
  //else cout<<"\nlargest:"<<maxHeap->array[largest]<<endl;
}

Maxheap * Heapcreator(int * array, int size)
{
  int i;
  Maxheap * maxHeap= new Maxheap;
  maxHeap->size=size;
  cout<<endl<<"heap size:"<<maxHeap->size<<endl;
  maxHeap->array=array;
  for(int i=(maxHeap->size-2)/2;i>=0;i--)
    {
      Heapifier(maxHeap,i);
    }
  return maxHeap;
}
void sort(int a[],int size)
{
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      if(a[j]<a[i])
	{
	  int temp=a[i];
	  a[i]=a[j];
	  a[j]=temp;
	}
}
void HeapSort(int * array, int size)
{
  Maxheap * maxHeap=Heapcreator(array,size);
  while(maxHeap->size>1)
    {
      int temp=maxHeap->array[0];
      maxHeap->array[0]=maxHeap->array[size-1];
      maxHeap->array[size-1]=temp;
      --maxHeap->size;
      Heapifier(maxHeap,0);
    }
}

int main()
{
 int a[100];
  //randomize();
  cout<<"\nBefore sort :"<<endl;
  for(int i=0;i<100;i++)
    {
      
      a[i]=rand()%1000;
      cout<<a[i]<<" ";
    }
  cout<<endl<<endl;
  // a={1,2,7,4,3,5,8,9,0};
  HeapSort(a,100);
  cout<<"\nAfter sort :"<<endl;
  sort(a,100);
  for(int i=0;i<100;i++)
   {
       cout<<a[i]<<" ";
   }
}
